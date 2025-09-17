#!/usr/bin/env sh

set -e pipefail

SCRIPT_DIR="${0%/*}"
SCRIPT_DIR="$(readlink -f "$SCRIPT_DIR")"
PATCH_DIR="$SCRIPT_DIR/patches"
SRC="$SCRIPT_DIR/src"
PATCHED="$SCRIPT_DIR/patched"

rm -fr "$PATCHED"
cp -r "$SRC" "$PATCHED"
cd "$PATCHED"

for patch in \
    tabbed-keyrelease-20191216-b5f9ec6.diff \
    tabbed-hidetabs-0.9.diff \
    tabbed-xresources-20230128-41e2b8f.diff \
    tabbed-bar-height-0.9.diff  \

do
    patch -p1 <"$PATCH_DIR/$patch"
done

cp "$SCRIPT_DIR/config.h" "$PATCHED"
