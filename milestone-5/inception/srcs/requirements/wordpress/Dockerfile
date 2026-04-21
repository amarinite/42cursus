FROM alpine:3.22

ARG PHP_VERSION=82

RUN apk update && apk upgrade && apk add --no-cache \
 php${PHP_VERSION} \
 php${PHP_VERSION}-fpm \
 php${PHP_VERSION}-mysqli \
 php${PHP_VERSION}-curl \
 php${PHP_VERSION}-mbstring \
 php${PHP_VERSION}-openssl \
 php${PHP_VERSION}-phar \
 php${PHP_VERSION}-xml \
 php${PHP_VERSION}-zip \
 php${PHP_VERSION}-dom \
 php${PHP_VERSION}-exif \
 php${PHP_VERSION}-fileinfo \
 php${PHP_VERSION}-redis \
 mariadb-client \
 curl \
 unzip

RUN ln -s /usr/bin/php82 /usr/bin/php

RUN cd /usr/local/bin && \
    curl -o wp -L https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp

COPY conf/www.conf /etc/php82/php-fpm.d/www.conf

COPY tools/wp-entrypoint.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/wp-entrypoint.sh

COPY conf/custom.ini /etc/php82/conf.d/custom.ini

WORKDIR /var/www/html/

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wp-entrypoint.sh"]
