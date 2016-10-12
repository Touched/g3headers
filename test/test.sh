#/usr/bin/bash
CC="arm-none-eabi-gcc"
CFLAGS="-Wall -Werror -Wfatal-errors -fno-builtin -I include -std=c11"

$CC $CFLAGS `find include -name '*.h'` -o /dev/null
