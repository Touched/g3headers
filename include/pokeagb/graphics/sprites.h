/**
 * @file
 * @brief Game engine sprites.
 */

#ifndef POKEAGB_GRAPHICS_SPRITES_H_
#define POKEAGB_GRAPHICS_SPRITES_H_

#include <pokeagb/types.h>

POKEAGB_BEGIN_DECL

#define SPRITE_RAM 0x6010000

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
    u32 y : 8;

    /**
     * 0=Normal, 1=Affine, 2=Disable, 3=Double Size
     */
    u32 affine_mode : 2;

    /**
     * 0=Normal, 1=Semi-Transparent, 2=OBJ Window, 3=Prohibited
     */
    u32 obj_mode : 2;

    /**
     * Enable mosaic
     */
    u32 mosaic : 1;

    /**
     * 1=256 colours
     */
    u32 bpp : 1;

    /**
     * 0=Square,1=Horizontal,2=Vertical,3=Prohibited
     */
    u32 shape : 2;

    u32 x : 9;
    u32 matrix_num : 5; // bits 3/4 are h-flip/v-flip if not in affine mode

    /**
     * Size  Square   Horizontal  Vertical
     * 0     8x8      16x8        8x16
     * 1     16x16    32x8        8x32
     * 2     32x32    32x16       16x32
     * 3     64x64    64x32       32x64
     */
    u32 size : 2;

    u16 tile_num : 10;

    /**
     * 0-3; 0=Highest
     */
    u16 priority : 2;
    u16 palette_num : 4;
    u16 affine_param;
};

/**
 * Tileset Data
 */
struct SpriteTiles {
    const void* data;
    u16 size;
    u16 tag;
};

struct SpritePalette {
    const void* data;
    u16 tag;
};

/**
 * A template for a sprite object
 */
struct Template {
    u16 tiles_tag;
    u16 pal_tag;
    const struct OamData* oam;
    struct Frame** animation;
    struct SpriteTiles* graphics;
    struct RotscaleFrame** rotscale;
    ObjectCallback callback;
};

/**
 * Sprite object
 */
struct Object {
    struct OamData final_oam;
    struct Frame (**animation_table)[];
    struct SpriteTiles* gfx_table;
    struct RotscaleFrame (**rotscale_table)[];
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
extern struct Frame* anim_image_empty;

#define SPRITE_NO_ANIMATION (&anim_image_empty)
#define SPRITE_NO_ROTSCALE (&rotscale_empty)

/**
 * @address{BPRE,0800760C}
 */
POKEAGB_EXTERN void oac_nullsub(struct Object* o);

/**
 * @address{BPRE,08006B5C}
 */
POKEAGB_EXTERN void objc_exec(void);

/**
 * @address{BPRE,08006FE0}
 */
POKEAGB_EXTERN u8 template_instanciate_reverse_search(struct Template*, u16 x, u16 y, u8 height);

/**
 * @address{BPRE,08006BA8}
 */
POKEAGB_EXTERN DEPRECATED void obj_sync_something(void);

/**
 * @address{BPRE,08006BA8}
 */
POKEAGB_EXTERN void obj_sync_superstate(void);

/**
 * @address{BPRE,08006F8C}
 */
POKEAGB_EXTERN u8 template_instanciate_forward_search(const struct Template* template,
                                                      u8 x,
                                                      u8 y,
                                                      u8 priority);

/**
 * @address{BPRE,08007804}
 */
POKEAGB_EXTERN u8 obj_delete_and_free(struct Object*);

/**
 * @address{BPRE,0800F078}
 */
POKEAGB_EXTERN void gpu_pal_decompress_alloc_tag_and_upload(const struct SpritePalette* pal);

/**
 * @address{BPRE,08008928}
 */
POKEAGB_EXTERN void gpu_pal_obj_alloc_tag_and_apply(const struct SpritePalette* pal);

/**
 * @address{BPRE,0800F034}
 */
POKEAGB_EXTERN void gpu_tile_obj_decompress_alloc_tag_and_upload(const struct SpriteTiles* tile);

/**
 * @address{BPRE,080086DC}
 */
POKEAGB_EXTERN void gpu_tile_obj_alloc_tag_and_upload(const struct SpriteTiles* tile);

/**
 * @address{BPRE,08008804}
 */
POKEAGB_EXTERN u16 gpu_tile_obj_tag_range_for_tag(u16 tile_tag);

/**
 * @address{BPRE,08008A30}
 */
POKEAGB_EXTERN u16 gpu_pal_free_by_tag(u16 pal_tag);

/**
 * @address{BPRE,08006B10}
 */
POKEAGB_EXTERN void obj_and_aux_reset_all(void);

/**
 * @address{BPRE,080087C4}
 */
POKEAGB_EXTERN void gpu_tile_obj_tags_reset(void);

/**
 * @address{BPRE,080836B4}
 */
POKEAGB_EXTERN void obj_free(struct Object *obj);


/**
 * @address{BPRE,0800874C}
 */
POKEAGB_EXTERN void gpu_tile_obj_free_by_tag(u16 tag);

/**
 * @address{BPRE,080073DC}
 */
POKEAGB_EXTERN void obj_delete(u8 id);

/**
 * Bouncing object. Uses private variables for control.
 * private[0] = 0 - Start object animation before bounce, 1 - Just bounce, other - disable
 * private[1] = Animation to start if private[0] == 0
 * private[2] = Direction: 0 - horizontal, 1 - vertical
 * private[3] = Distance
 * private[4] = Speed
 * private[5] = Phase Shift
 * @address{BPRE,08133904}
 */
POKEAGB_EXTERN void oac_pingpong(struct Object*);

/**
 * Sine wave. Used to animate bouncing objects.
 * @param phase The current phase or the x in sin(x)
 * @param scale The amplitude of the wave
 * @address{BPRE,08044E30}
 */
POKEAGB_EXTERN s16 get_pingpong(s16 phase, u16 scale);

POKEAGB_END_DECL

#endif /* POKEAGB_GRAPHICS_SPRITES_H_ */
