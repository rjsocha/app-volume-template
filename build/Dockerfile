FROM alpine:latest AS template
RUN apk add --no-cache rsync
COPY wyga-deploy /usr/local/bin/wyga-deploy
RUN chmod +x /usr/local/bin/wyga-deploy

FROM scratch
COPY --from=0 / /
ENTRYPOINT [ "wyga-deploy" ]
