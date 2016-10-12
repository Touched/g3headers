#ifndef POKEAGB_MACROS_H_
#define POKEAGB_MACROS_H_

#include <stddef.h>

#define POKEAGB_EXTERN extern __attribute__((long_call))

/* TODO: Add more asserts to the code. */

/**
 * Assert (at compile time) that a type is of a given size.
 */
#define ASSERT_SIZEOF(type, size) _Static_assert(sizeof(type) == size, \
                                                 "Expected size of '" \
                                                 #type "' to be " #size ".")

/**
 * Assert (at compile time) that a member occurs at a given offset.
 */
#define ASSERT_OFFSETOF(type, member, offset) _Static_assert(offsetof(type, member) == offset, \
                                                             "Expected `" #member "` in `" \
                                                             #type "` to be at offset " #offset ".")

#ifdef __cplusplus
#define POKEAGB_BEGIN_DECL extern "C" {
#define POKEAGB_END_DECL }
#else
#define POKEAGB_BEGIN_DECL
#define POKEAGB_END_DECL
#endif

#endif /* POKEAGB_MACROS_H_ */
