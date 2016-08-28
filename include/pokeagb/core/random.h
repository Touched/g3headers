#ifndef POKEAGB_CORE_RANDOM_H_
#define POKEAGB_CORE_RANDOM_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>

#ifdef __cplusplus
extern "C" {
#endif

  LONG_CALL u16 rand();
  LONG_CALL void set_rand_seed(u16 seed);

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_RANDOM_H_ */
