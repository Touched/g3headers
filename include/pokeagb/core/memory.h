#ifndef POKEAGB_CORE_MEMORY_H_
#define POKEAGB_CORE_MEMORY_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>

#ifdef __cplusplus
extern "C" {
#endif

  /**
   * Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.
   *
   * @address{BPRE,08002B9C}
   */
  LONG_CALL void* malloc(u32 size);

  /**
   * Allocates a block of size bytes of memory and zero fills it.
   *
   * @address{BPRE,08002BB0}
   */
  LONG_CALL void* malloc_and_clear(u32 size);

  /**
   * Deallocate a block of memory previously allocated with malloc.
   *
   * @address{BPRE,08002BC4}
   */
  LONG_CALL void free(void* ptr);

  /**
   * Copies size bytes from src to dst.
   *
   * @address{BPRE,081E5E78}
   */
  LONG_CALL void* memcpy(void* dst, const void* src, u32 size);

  /**
   * Set size bytes at dst to value.
   *
   * @address{BPRE,081E5ED8}
   */
  LONG_CALL void memset(void* dst, u8 value, u32 size);

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_MEMORY_H_ */
