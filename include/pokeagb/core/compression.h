/**
 * @file
 * @brief Compression
 */

#ifndef POKEAGB_COMPRESSION_H_
#define POKEAGB_COMPRESSION_H_

#include "../types.h"

/**
 * @address{BPRE,081E3B70}
 */
void LZ77UnCompWram(void* src, void* dst);

/**
 * @address{BPRE,080F6AA0}
 */
void* malloc_and_LZ77UnComp(void* src, u32* size);

#endif /* POKEAGB_COMPRESSION_H_ */
