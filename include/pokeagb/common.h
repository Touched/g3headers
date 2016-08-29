#ifndef POKEAGB_MACROS_H_
#define POKEAGB_MACROS_H_

#define POKEAGB_EXTERN extern __attribute__((long_call))

#define ASSERT_SIZEOF(type, size) _Static_assert(sizeof(type) == size, \
                                                 "Expected size of '" \
                                                 #type "' to be " #size ".")

#ifdef __cplusplus
#define POKEAGB_BEGIN_DECL extern "C" {
#define POKEAGB_END_DECL }
#else
#define POKEAGB_BEGIN_DECL
#define POKEAGB_END_DECL
#endif

#endif /* POKEAGB_MACROS_H_ */
