FROM alpine:3.22

RUN apk update && apk upgrade && apk add --no-cache php82 php82-mysqli php82-session curl

RUN addgroup -S adminer \
&&  adduser -S -G adminer adminer \
&&  mkdir -p /var/www/html \
&&  chown -R adminer:adminer /var/www/html

WORKDIR /var/www/html

ENV ADMINER_VERSION=5.4.2

RUN curl -fsSL https://github.com/vrana/adminer/releases/download/v${ADMINER_VERSION}/adminer-${ADMINER_VERSION}.php \
    -o index.php

COPY tools/ad-entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/ad-entrypoint.sh

USER adminer

EXPOSE 8080

ENTRYPOINT ["ad-entrypoint.sh"]