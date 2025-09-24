#!/usr/bin/env sh

set -e pipefail

SCRIPT_DIR="$(readlink -f "$0")"
SCRIPT_DIR="${SCRIPT_DIR%/*}"
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
    echo "Applying $patch"
    patch -p1 <"$PATCH_DIR/$patch"
done

cp "$SCRIPT_DIR/config.h" "$PATCHED"
cp "$SCRIPT_DIR/tabbed.1" "$PATCHED"
if [ "$(uname)" = "FreeBSD" ]; then
    cp "$SCRIPT_DIR/config.freebsd.mk" "$PATCHED/config.mk"
fi
