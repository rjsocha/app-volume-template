# syntax=docker/dockerfile:1.5
FROM alpine:3.16 AS template
RUN apk add --no-cache tini rsync && apk del --purge alpine-keys apk-tools libc-utils ca-certificates-bundle
RUN rm -rf /etc/group- /etc/passwd- /etc/shadow- /lib/apk /lib/firmware /lib/mdev rm /lib/modules-load.d /lib/sysctl.d /etc/sysctl.conf /etc/udhcpd.conf /media /mnt /opt /srv /var/spool /var/opt /var/mail /var/cache/apk /usr/sbin/nginx-debug /etc/init.d /etc/apk /etc/logrotate.d  /etc/modprobe.d /etc/modules-load.d /etc/network /etc/opt /etc/periodic /etc/secfixes.d /etc/ssl /etc/sysctl.d /home /var/lib/misc /var/lib/udhcpd  /usr/lib/modules-load.d /etc/conf.d /etc/crontabs /etc/profile.d /etc/inittab  /etc/motd /etc/fstab /usr/share/licenses /usr/share/man /usr/share/misc /usr/share/udhcpc
COPY wyga-deploy /usr/local/bin/wyga-deploy
RUN chmod +x /usr/local/bin/wyga-deploy

FROM scratch
COPY --from=0 / /
ENTRYPOINT ["/sbin/tini", "--", "wyga-deploy"]
