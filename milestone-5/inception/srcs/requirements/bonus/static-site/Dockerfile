FROM alpine:3.22

RUN apk update && apk add --no-cache nginx

COPY tools/ss-entrypoint.sh /usr/local/bin/
RUN chmod +x usr/local/bin/ss-entrypoint.sh

RUN mkdir -p /usr/share/nginx/html

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY web/ /usr/share/nginx/html/

EXPOSE 80

ENTRYPOINT [ "ss-entrypoint.sh" ]