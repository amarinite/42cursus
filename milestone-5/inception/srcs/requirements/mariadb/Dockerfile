FROM alpine:3.22

RUN apk update && apk upgrade && apk add --no-cache mariadb mariadb-client gosu

COPY db-entrypoint.sh /db-entrypoint.sh
RUN chmod +x /db-entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/db-entrypoint.sh"]
