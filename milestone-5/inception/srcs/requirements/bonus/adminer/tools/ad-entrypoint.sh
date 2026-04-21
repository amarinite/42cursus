#!/bin/sh
set -eu

echo "[i] Starting Adminer..."
exec php82 -S 0.0.0.0:8080 -t /var/www/html