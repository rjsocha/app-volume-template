FROM alpine:3.16 AS template
RUN apk add --no-cache rsync && apk del alpine-keys apk-tools libc-utils
COPY wyga-deploy /usr/local/bin/wyga-deploy
RUN chmod +x /usr/local/bin/wyga-deploy

FROM scratch
COPY --from=0 / /
ENTRYPOINT [ "wyga-deploy" ]
