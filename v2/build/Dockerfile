FROM alpine AS builder
RUN apk --update add gcc musl-dev make bash g++ upx tini
COPY src/busybox-1.36.0.tar.bz2 /src/
COPY src/rsync-3.2.7.tar.gz /src/
RUN tar xjf /src/busybox-1.36.0.tar.bz2 -C /src
RUN tar xzf /src/rsync-3.2.7.tar.gz -C /src
COPY src/.config /src/busybox-1.36.0/
WORKDIR /src/busybox-1.36.0/
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

FROM scratch AS mold
COPY --from=builder /dist/busybox /bin/sh
COPY --from=builder /dist/rsync /usr/local/bin/rsync
#COPY --from=builder /dist/tini /usr/local/sbin/tini
COPY --chmod=0755 build/wyga-deploy /
FROM scratch
COPY --from=mold / /
ENTRYPOINT [ "/wyga-deploy" ]
