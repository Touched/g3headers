/**
 * @file
 * @brief Pokemon sprites
 */

#ifndef POKEAGB_POKEMON_SPRITES_H_
#define POKEAGB_POKEMON_SPRITES_H_

#include "../common.h"
#include "base.h"
#include "../graphics.h"

POKEAGB_BEGIN_DECL

/**
 * @address{BPRE,082350AC}
 */
extern struct SpriteTiles pokemon_graphics_front[POKEAGB_POKEMON_SLOTS];

/**
 * @address{BPRE,0823654C}
 */
extern struct SpriteTiles pokemon_graphics_back[POKEAGB_POKEMON_SLOTS];

/**
 * @address{BPRE,0823730C}
 */
extern struct SpritePalette pokemon_palette_normal[POKEAGB_POKEMON_SLOTS];

/**
 * @address{BPRE,082380CC}
 */
extern struct SpritePalette pokemon_palette_shiny[POKEAGB_POKEMON_SLOTS];

POKEAGB_END_DECL

#endif /* POKEAGB_POKEMON_SPRITES_H_ */
