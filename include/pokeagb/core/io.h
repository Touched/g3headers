/**
 * @file
 * @brief GBA IO registers
 */

#ifndef POKEAGB_CORE_IO_H_
#define POKEAGB_CORE_IO_H_

#include "../common.h"
#include "../types.h"

/**
 * @address{BPRE,08000A38}
 */
POKEAGB_EXTERN void lcd_io_set(u8, u16);

#endif /* POKEAGB_CORE_IO_H_ */
