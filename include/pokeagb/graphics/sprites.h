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

struct OamData {
    u32 y:8;
    u32 affineMode:2;
    u32 objMode:2;
    u32 mosaic:1;
    u32 bpp:1;
    u32 shape:2;

    u32 x:9;
    u32 matrixNum:5; // bits 3/4 are h-flip/v-flip if not in affine mode
    u32 size:2;

    u16 tileNum:10;
    u16 priority:2;
    u16 paletteNum:4;
    u16 affineParam;
};

/**
 * Tileset Data
 */
struct Graphics {
    u8* data;
    u16 size;
    u16 tag;
};

struct SpritePalette {
    u8* data;
    u16 tag;
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
    struct OamData final_oam;
    struct Frame** animation_table;
    struct Graphics* gfx_table;
    struct RotscaleFrame** rotscale_table;
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

/**
 * @address{BPRE,08231CFC}
 */
extern struct RotscaleFrame* rotscale_empty;

/**
 * @address{BPRE,08231CF0}
 */
extern struct Frame* anim_image_table_empty;

/**
 * @address{BPRE,0800760C}
 */
POKEAGB_EXTERN void oac_nullsub(struct Object* o);

/**
 * @address{BPRE,08006B5C}
 */
POKEAGB_EXTERN void objc_exec(void);

/**
 * @address{BPRE,08006BA8}
 */
POKEAGB_EXTERN void obj_sync_something(void);

/**
 * @address{BPRE,08006F8C}
 */
POKEAGB_EXTERN u8 template_instanciate_forward_search(struct Template* template,
                                                      u8 x,
                                                      u8 u,
                                                      u8 priority);

/**
 * @address{BPRE,0800F078}
 */
POKEAGB_EXTERN void gpu_pal_decompress_alloc_tag_and_upload(struct SpritePalette* pal);

/**
 * @address{BPRE,08008928}
 */
POKEAGB_EXTERN void gpu_pal_obj_alloc_tag_and_apply(struct SpritePalette* pal);

/**
 * @address{BPRE,0800EBCC}
 */
POKEAGB_EXTERN void gpu_tile_obj_decompress_alloc_tag_and_upload(struct Graphics* pal);

/**
 * @address{BPRE,080086DC}
 */
POKEAGB_EXTERN void gpu_tile_obj_alloc_tag_and_upload(struct Graphics* pal);

POKEAGB_END_DECL

#endif /* POKEAGB_GRAPHICS_SPRITES_H_ */
