#!/bin/sh
set -eu

echo "[i] Starting static website..."
exec nginx -g "daemon off;"