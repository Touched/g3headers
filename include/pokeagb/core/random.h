#ifndef POKEAGB_CORE_RANDOM_H_
#define POKEAGB_CORE_RANDOM_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>

#ifdef __cplusplus
extern "C" {
#endif

  #define RAND_MAX 0xFFFF

  /**
   * Generate a pseudo-random integer between 0 and RAND_MAX.
   *
   * @address{BPRE,08044EE8}
   */
  LONG_CALL u16 rand();

  /**
   * Initialize the PRNG with seed.
   *
   * @address{BPRE,08044EC8}
   */
  LONG_CALL void set_rand_seed(u16 seed);

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_RANDOM_H_ */
