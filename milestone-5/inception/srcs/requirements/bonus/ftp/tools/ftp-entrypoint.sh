#!/bin/sh
set -eu

for var in FTP_USER FTP_PASSWORD_FILE; do
    eval f="\$$var"
    [ -n "$f" ] || { echo "ERROR: $var is not set"; exit 1; }
done

[ -s "$FTP_PASSWORD_FILE" ] || { echo "ERROR: FTP_PASSWORD_FILE points to missing or empty file"; exit 1; }

FTP_PASSWORD=$(cat "$FTP_PASSWORD_FILE")

if ! id -u "$FTP_USER" > /dev/null 2>&1; then
    adduser -h /var/www/html -s /sbin/nologin -D "$FTP_USER"
    echo "$FTP_USER:$FTP_PASSWORD" | chpasswd
fi

exec vsftpd /etc/vsftpd/vsftpd.conf