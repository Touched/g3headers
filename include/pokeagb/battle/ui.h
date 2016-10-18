/**
* @file
* @brief HP bar related attributes
*/

#ifndef POKEAGB_BATTLEE_UI_H_
#define POKEAGB_BATTLEE_UI_H_

#include "../types.h"
#include "../common.h"

POKEAGB_BEGIN_DECL

#define TILE_SIZE 32
#define NAME_TILE_PLAYER 10
#define NAME_TILE_OPPONENT 9
#define LEVEL_TILE_SINGLE_PLAYER 74
#define LEVEL_TILE_OPPONENT 40
#define LEVEL_TILE_DOUBLES_PLAYER 42
#define HEALTH_NUMS_TILE_PLAYER 30
#define AILMENT_TILE_SINLE_PLAYER 26
#define AILMENT_TILE_DOUBLE_PLAYER 17
#define AILMENT_TILE_OPPONENT 16

POKEAGB_EXTERN void load_gfxc_health_bar(void);
POKEAGB_EXTERN void hpbox_data_set(u8, u8, u32, u32, u8);
POKEAGB_EXTERN void sync_hpbox_vram(u8, u8, u8);

POKEAGB_END_DECL

#endif /* POKEAGB_BATTLEE_UI_H_ */


