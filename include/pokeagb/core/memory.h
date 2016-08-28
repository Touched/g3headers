#ifndef POKEAGB_CORE_MEMORY_H_
#define POKEAGB_CORE_MEMORY_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>

#ifdef __cplusplus
extern "C" {
#endif

  LONG_CALL void* malloc(u32 size);
  LONG_CALL void* malloc_and_clear(u32 size);
  LONG_CALL void free(void* ptr);
  LONG_CALL void* memcpy(void* dst, const void* src, u32 size);
  LONG_CALL void memset(void* dst, u8 value, u32 size);

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_MEMORY_H_ */
