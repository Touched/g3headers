#/usr/bin/bash
CC="arm-none-eabi-gcc"
CFLAGS="-Wall -Werror -fno-builtin -I include"

$CC $CFLAGS `find include -name '*.h'` -o /dev/null
