#!/bin/sh
# Build RetroUnix64 utilities and prepare bootable image
set -e
DIR="$(dirname "$0")"
make -C "$DIR"
# TODO: implement bootable image packaging (requires kernel & bootloader)
echo "Utilities built. Bootable image packaging not yet implemented." >&2
