#/usr/bin/bash
CC="arm-none-eabi-gcc"
CFLAGS="-Wall -Werror -Wfatal-errors -fno-builtin -I include -std=c11"

CXX="arm-none-eabi-g++"
CXXFLAGS="-Wall -Werror -Wfatal-errors -fno-builtin -I include -std=c++14"

$CC $CFLAGS include/pokeagb/pokeagb.h -o /dev/null
$CXX $CXXFLAGS include/pokeagb/pokeagb.h -o /dev/null
