/**
 * @file
 * @brief GBA IO registers
 */

#ifndef POKEAGB_CORE_IO_H_
#define POKEAGB_CORE_IO_H_

#include "../common.h"
#include "../types.h"

/**
 * 0x4000000 + number = reg_id -> the register to modify
 * @address{BPRE,08000A38}
 */
POKEAGB_EXTERN void lcd_io_set(u8 reg_id, u16 value);

#endif /* POKEAGB_CORE_IO_H_ */
