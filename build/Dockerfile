FROM alpine:latest AS template
RUN apk add --no-cache rsync
COPY start-me /start-me
RUN chmod +x /start-me

FROM scratch
COPY --from=0 / /
ENTRYPOINT [ "/start-me" ]
