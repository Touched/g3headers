/**
 * @file
 * @brief Pokedex functions.
 */

#ifndef POKEAGB_POKEMON_POKEDEX_H_
#define POKEAGB_POKEMON_POKEDEX_H_

#include <pokeagb/common.h>
#include <pokeagb/types.h>

POKEAGB_BEGIN_DECL

enum DexFlagOperation {
    DEX_FLAG_CHECK_SEEN,
    DEX_FLAG_CHECK_CAUGHT,
    DEX_FLAG_SET_SEEN,
    DEX_FLAG_SET_CAUGHT,
    /* TODO: Figure out rest */
};

/**
 * Check the Pokedex flag given a Pokedex index.
 * @param index The species or Pokedex index
 * @param op The operation to perform
 * @address{BPRE,08088E74}
 */
POKEAGB_EXTERN bool dex_flag_pokedex_index(u16 index, enum DexFlagOperation op);

/**
 * Check the Pokedex flag given an index.
 * @param index The species or Pokedex index
 * @param op The operation to perform
 * @param convert_index If true, the index given is a PokemonSpecies index and will be converted.
 * @address{BPRE,08088E74}
 */
POKEAGB_EXTERN bool dex_flag(u16 index, enum DexFlagOperation op, bool convert_index);

POKEAGB_END_DECL

#endif /* POKEAGB_POKEMON_POKEDEX_H_ */
