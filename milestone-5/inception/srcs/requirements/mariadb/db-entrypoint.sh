#!/bin/sh
set -eu

#set secrets if they exist; fail early if they don't
for var in MYSQL_ROOT_PASSWORD_FILE MYSQL_PASSWORD_FILE; do
    eval f="\$$var"
    [ -n "$f" ] || { echo "ERROR: $var is not set"; exit 1; }
    [ -s "$f" ] || { echo "ERROR: $var points to missing or empty file: $f"; exit 1; }
done


#creating db daemon directory if it doesn't exist
if [ -d "/run/mysqld" ]; then
	echo "[i] mysqld already present, skipping creation"
else
	echo "[i] mysqld not found, creating...."
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
fi

#configuring mariadb on first run
if [ -d "/var/lib/mysql/mysql" ]; then
	echo "[i] DB data directory already present, skipping creation"
else
	echo "[i] DB data directory not found, creating initial DBs"
	chown -R mysql:mysql /var/lib/mysql

	mariadb-install-db --user=mysql --datadir=/var/lib/mysql > /dev/null

	MYSQL_ROOT_PASSWORD=$(cat "$MYSQL_ROOT_PASSWORD_FILE")
	MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")

	#temp SQL file to create initial database
	tfile=$(mktemp)
	trap 'rm -f "$tfile"' EXIT

	cat << EOF > "$tfile"
USE mysql;
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
DROP DATABASE IF EXISTS test;
CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\` CHARACTER SET $MYSQL_CHARSET COLLATE $MYSQL_COLLATION;
GRANT ALL ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
FLUSH PRIVILEGES;
EOF

	#run mariadb on bootstrap mode so the process ends on its own
	gosu mysql /usr/bin/mariadbd --user=mysql --bootstrap --verbose=0 --skip-name-resolve --skip-networking=0 < "$tfile"
	rm -f "$tfile"

fi

#exec mariadb with permissions on PID 1 skipping DNS and allowing TCP connection
echo "[i] DB init done, starting MariaDB..."
exec gosu mysql /usr/bin/mariadbd --user=mysql --console --skip-name-resolve --skip-networking=0 "$@"
