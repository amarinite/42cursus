FROM alpine:3.22

RUN apk update && apk upgrade && apk add --no-cache vsftpd

COPY conf/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY tools/ftp-entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/ftp-entrypoint.sh

EXPOSE 21 21000-21010

ENTRYPOINT ["ftp-entrypoint.sh"]