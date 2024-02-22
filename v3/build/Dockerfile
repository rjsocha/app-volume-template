FROM alpine AS builder
RUN apk --update add gcc musl-dev make bash g++ upx tini
COPY src/busybox-1.36.1.tar.bz2 /src/
COPY src/rsync-3.2.7.tar.gz /src/
COPY src/mv.ex.c /src/
RUN tar xjf /src/busybox-1.36.1.tar.bz2 -C /src
RUN tar xzf /src/rsync-3.2.7.tar.gz -C /src
COPY src/.config /src/busybox-1.36.1/
WORKDIR /src
RUN gcc -o mv.ex -s -O2 -static mv.ex.c
WORKDIR /src/busybox-1.36.1/
RUN make oldconfig
RUN make && mkdir -p /dist && cp busybox /dist/
WORKDIR /src/rsync-3.2.7
ENV LDFLAGS="-s -static"
RUN ./configure --disable-openssl  --disable-xxhash --disable-zstd --disable-lz4 --disable-ipv6 --disable-locale --disable-debug --disable-md2man --disable-iconv --disable-iconv-open
RUN make && cp rsync /dist/
# ????
#RUN cp /sbin/tini /dist/tini
RUN upx /dist/busybox
RUN upx /dist/rsync
RUN cp /src/mv.ex /dist/mv.ex
COPY --chmod=0755 build/wyga-deploy /dist/deploy-template

FROM scratch AS mold
COPY --from=builder /dist/busybox /bin/sh
COPY --from=builder /dist/mv.ex /bin/mv.ex
COPY --from=builder /dist/rsync /bin/rsync
COPY --from=builder /dist/deploy-template /.entrypoint/deploy-template

FROM scratch
COPY --from=mold / /
ENTRYPOINT [ "/.entrypoint/deploy-template" ]
