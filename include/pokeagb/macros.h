#ifndef POKEAGB_MACROS_H_
#define POKEAGB_MACROS_H_

#define LONG_CALL __attribute__((long_call))
#define ASSERT_SIZEOF(type, size) _Static_assert(sizeof(type) == size, \
                                                 "Expected size of '" \
                                                 #type "' to be " #size ".")

#endif /* POKEAGB_MACROS_H_ */
