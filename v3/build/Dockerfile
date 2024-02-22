FROM alpine AS builder
RUN apk --update add gcc musl-dev make bash g++ upx tini
COPY src/busybox-1.36.1.tar.bz2 /src/
RUN tar xjf /src/busybox-1.36.1.tar.bz2 -C /src
COPY src/.config /src/busybox-1.36.1/
WORKDIR /src/busybox-1.36.1/
RUN make oldconfig
RUN make && mkdir -p /dist && cp busybox /dist/
RUN upx /dist/busybox
WORKDIR /src
COPY src/mv-swap.c mv-swap.c
RUN gcc -o mv-swap -s -O2 -static mv-swap.c
RUN cp mv-swap /dist/mv-swap
COPY --chmod=0755 script/deploy-image /dist/deploy-image

FROM scratch AS mold
COPY --from=builder /dist/busybox /bin/sh
COPY --from=builder /dist/mv-swap /bin/mv-swap
COPY --from=builder /dist/deploy-image /.entrypoint/deploy-image

FROM scratch
COPY --from=mold / /
ENTRYPOINT [ "/.entrypoint/deploy-image" ]
