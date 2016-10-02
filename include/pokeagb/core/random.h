/**
 * @file
 * @brief PRNG.
 */

#ifndef POKEAGB_CORE_RANDOM_H_
#define POKEAGB_CORE_RANDOM_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>

POKEAGB_BEGIN_DECL

#define RAND_MAX 0xFFFF

/**
 * Generate a pseudo-random integer between 0 and RAND_MAX.
 *
 * @address{BPRE,08044EC8}
 */
POKEAGB_EXTERN u16 rand();

/**
 * Initialize the PRNG with seed.
 *
 * @address{BPRE,08044EE8}
 */
POKEAGB_EXTERN void set_rand_seed(u16 seed);

POKEAGB_END_DECL

#endif /* POKEAGB_CORE_RANDOM_H_ */
