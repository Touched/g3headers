/**
 * @file
 * @brief Game engine sprites.
 */

#ifndef POKEAGB_GRAPHICS_SPRITES_H_
#define POKEAGB_GRAPHICS_SPRITES_H_

#include <pokeagb/types.h>

POKEAGB_BEGIN_DECL

struct Object;

/**
 * Sprite object callback.
 * @param o The object the callback belongs to
 */
typedef void (*ObjectCallback)(struct Object* o);

/**
 * 8 bit coordinates
 */
struct Coords8 {
    u8 x;
    u8 y;
};

/**
 * 16 bit coordinates;
 */
struct Coords16 {
    u16 x;
    u16 y;
};

/**
 * Tile animation frame
 */
struct Frame {
    u16 data;
    u16 duration;
};

/**
 * Rotation/Scaling frame
 */
struct RotscaleFrame {
    u16 scale_delta_x;
    u16 scale_delta_y;
    u8 rot_delta;
    u8 duration;
    u16 field_6;
};

/**
 * OAM Structure
 */
struct Sprite {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 rotscale;
};

/**
 * Tileset Data
 */
struct Graphics {
    u8* address;
    u32 size;
};

/**
 * A template for a sprite object
 */
struct Template {
    u16 tiles_tag;
    u16 pal_tag;
    struct Sprite* oam;
    struct Frame** animation;
    struct Graphics* graphics;
    struct RotscaleFrame** rotscale;
    ObjectCallback callback;
};

/**
 * Sprite object
 */
struct Object {
    struct Sprite final_oam;
    struct Frame** animation_table;
    struct Graphics* gfx_table;
    struct RotscaleFrame* rotscale_table;
    struct Template* template;
    u32 field18;
    ObjectCallback callback;
    struct Coords16 pos1;
    struct Coords16 pos2;
    struct Coords8 shift;
    u8 anim_number;
    u8 anim_frame;
    u8 anim_delay;
    u8 counter;
    u16 private[8];
    u8 bitfield2;
    u8 bitfield;
    u16 anim_data_offset;
    u8 field42;
    u8 y_height_related;
};

/**
 * All the objects
 * @address{BPRE,0202063C}
 */
extern struct Object objects[64];

POKEAGB_END_DECL

#endif /* POKEAGB_GRAPHICS_SPRITES_H_ */
