/**
 * @file
 * @brief GameFreak strings.
 */

#ifndef POKEAGB_CORE_STRING_H_
#define POKEAGB_CORE_STRING_H_

#include <pokeagb/types.h>

POKEAGB_BEGIN_DECL

typedef u8 pchar;

struct Textbox {
    u8 bg_id;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u16 charbase;
    u8* pixels;
};

ASSERT_SIZEOF(struct Textbox, 12);
ASSERT_OFFSETOF(struct Textbox, bg_id, 0);
ASSERT_OFFSETOF(struct Textbox, x, 1);
ASSERT_OFFSETOF(struct Textbox, y, 2);
ASSERT_OFFSETOF(struct Textbox, width, 3);
ASSERT_OFFSETOF(struct Textbox, height, 4);
ASSERT_OFFSETOF(struct Textbox, charbase, 6);
ASSERT_OFFSETOF(struct Textbox, pixels, 8);

/**
 * @address{BPRE,020204B4}
 */
extern struct Textbox rboxes[32];

/**
 * Clear a textbox.
 *
 * @address{BPRE,0800445C}
 */
POKEAGB_EXTERN void rboxid_clear_pixels(u8 id, u8 offset);

/**
 * Update a textbox.
 *
 * @param mode 3 == Update tileset & tilemap, 2 == update tileset, 1 == update tilemap
 * @address{BPRE,08003F20}
 */
POKEAGB_EXTERN void rboxid_update(u8 id, u8 mode);

POKEAGB_END_DECL

#endif /* POKEAGB_CORE_STRING_H_ */
