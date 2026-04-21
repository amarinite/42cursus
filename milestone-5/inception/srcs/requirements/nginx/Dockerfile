FROM alpine:3.22

RUN apk update && apk upgrade && apk add --no-cache nginx openssl

COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -newkey rsa:2048 -keyout '/etc/nginx/ssl/domain.key' -out '/etc/nginx/ssl/domain.crt' -days 365 -subj "/CN=amarquez.42.fr"

EXPOSE 443

ENTRYPOINT ["nginx"]

CMD ["-g", "daemon off;"]
