/*
 * This file is part of PokeAGB.
 *
 * PokeAGB is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PokeAGB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PokeAGB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef POKEAGB_POKEMON_TYPE_H_
#define POKEAGB_POKEMON_TYPE_H_

#include <pokeagb/macros.h>
#include <pokeagb/core/string.h>

#ifdef __cplusplus
extern "C" {
#endif

  #define POKEAGB_TYPE_NAME_LENGTH 7

  enum PokemonType {
    TYPE_NORMAL,
    TYPE_FIGHTING,
    TYPE_FLYING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_BUG,
    TYPE_GHOST,
    TYPE_STEEL,
    TYPE_NONE, /**< ??? Type */
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ELECTRIC,
    TYPE_PSYCHIC,
    TYPE_ICE,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_MAX,
  };

  ASSERT_SIZEOF(enum PokemonType, 1);

  extern pchar pokemon_type_names[TYPE_MAX][POKEAGB_TYPE_NAME_LENGTH];

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_POKEMON_TYPE_H_ */
