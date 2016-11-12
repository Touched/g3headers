/**
 * @file
 * @brief Pokemon icons
 */

#ifndef POKEAGB_POKEICONS_H_
#define POKEAGB_POKEICONS_H_

#include <pokeagb/common.h>
#include <pokeagb/core/string.h>
#include "../graphics/palette.h"
#include "../graphics/sprites.h"


POKEAGB_BEGIN_DECL

/**
 * @address{BPRE,083D37A0}
 */
extern const u8* pokeicon_table[410];

/**
 * Icons Pal Table
 * @address{BPRE,083D3740}
 */
extern const u16 pokeicon_pals[3][16];


/**
 * Icons Pal index Table. It contains an index 0-2 for the three
 * pals which are from the icons Pal table.
 * @address{BPRE,083D3E80}
 */
extern const u8 pokeicon_pal_indices[410];


/**
 * Graphics for held items. Hold item and mail held indicators
 * @address{BPRE,0845A3AC}
 */
extern const void *gfx_heldicons;


/**
 * Pal for held items. The yellow box and mail icon
 * @address{BPRE,0845A3EC}
 */
extern const void *pal_heldicons;

POKEAGB_END_DECL

#endif /* POKEAGB_POKEICONS_H_ */
