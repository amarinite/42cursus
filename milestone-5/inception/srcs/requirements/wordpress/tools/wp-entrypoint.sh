#!/bin/sh
set -eu

#check secrets file
for var in MYSQL_PASSWORD_FILE WP_ADMIN_PASSWORD_FILE WP_USER_PASSWORD_FILE; do
    eval f="\$$var"
    [ -n "$f" ] || { echo "ERROR: $var is not set"; exit 1; }
    [ -s "$f" ] || { echo "ERROR: $var points to missing or empty file: $f"; exit 1; }
done
MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
WP_ADMIN_PASSWORD=$(cat "$WP_ADMIN_PASSWORD_FILE")
WP_USER_PASSWORD=$(cat "$WP_USER_PASSWORD_FILE")

#wait for the database
# must re-run safely if db restarts
while ! mariadb -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" "$MYSQL_DATABASE" -e "SELECT 1" &>/dev/null; do
    echo "[i] Waiting for MariaDB..."
    sleep 2
done
echo "[i] MariaDB ready"

#download wp core
if [ ! -f wp-config-sample.php ]; then
    echo "[i] Downloading WordPress..."
    wp core download --allow-root
fi

#configure wp (wp config create)
if [ -e wp-config.php ]; then
	echo "[i] Wordpress config already created, skipping creation"
else
	wp config create --allow-root \
	       --dbname="$MYSQL_DATABASE" \
	       --dbuser="$MYSQL_USER" \
	       --dbpass="$MYSQL_PASSWORD" \
	       --dbhost="$MYSQL_HOST"
	echo "[i] Wordpress config created"
fi

#if wp is not installed, install it
# wp core install with url, site title, admin username, password, email
if wp core is-installed --allow-root; then
	  echo "[i] Wordpress core already installed, skipping creation"
else
	wp core install --allow-root \
		--url="$WP_URL" \
		--title="$WP_TITLE" \
		--admin_user="$WP_ADMIN_USER" \
		--admin_email="$WP_ADMIN_EMAIL" \
		--admin_password="$WP_ADMIN_PASSWORD"
			
	wp user create --allow-root "$WP_USER_NAME" "$WP_USER_EMAIL" \
		--role=author \
		--user_pass="$WP_USER_PASSWORD"

	#disabling debug logs
	wp config set WP_DEBUG false --allow-root

	#redis config
	wp plugin install redis-cache --activate --allow-root
	wp config set WP_REDIS_HOST redis --allow-root
	wp config set WP_REDIS_PORT 6379 --allow-root
	wp redis enable --allow-root
	echo "[i] Redis configuration complete"
fi

#start php (exec php-fpm) on the foreground (-F)
echo "[i] WP init done, starting PHP-FPM"
exec php-fpm82 -F
