/**
 * @file
 * @brief Background graphics
 */

#ifndef POKEAGB_GRAPHICS_BACKGROUND_H_
#define POKEAGB_GRAPHICS_BACKGROUND_H_

struct BgConfig {
    u8 active : 1;
    u8 padding : 1;
    u8 screen_size : 2;
    u8 priority : 2;
    u8 mosaic : 1;
    u8 wraparound : 1;
    u8 character_base : 2;
    u8 screen_base : 5;
    u8 palette : 1; 	/* 1: 256/1, 0: 16/16 */
    u16 unknown;
};

struct BgConfig2 {
    u16 target_tile;
    u16 *tilemap;
    u32 x;
    u32 y;
};

extern struct BgConfig2 bg_config2[4];

/**
 * @address{BPRE,08001618}
 */
POKEAGB_EXTERN void gpu_tile_bg_drop_all_sets(u8);

/**
 * @address{BPRE,0812D594}
 */
POKEAGB_EXTERN void bg_positions_reset(void);

/**
 * @address{BPRE,080F4E24}
 */
POKEAGB_EXTERN void callback_clear_and_init(void);

/**
 * @address{BPRE,08001FD4}
 */
POKEAGB_EXTERN void bgid_nullify_tilemap(u8);

/**
 * @address{BPRE,080017D0}
 */
POKEAGB_EXTERN u16 gpu_copy_to_tileset(u8 layer, u8* tiles, u16 size, u16 offset);

/**
 * @address{BPRE,08002040}
 */
POKEAGB_EXTERN void gpu_copy_tilemap(u8 layer, u8* map, u16 size_or_null, u16 offset);

/**
 * @address{BPRE,080020BC}
 */
POKEAGB_EXTERN void bgid_send_tilemap(u8 layer);

/**
 * @address{BPRE,08001FA0}
 */
POKEAGB_EXTERN void bgid_set_tilemap(u8 layer, u8* space);

/**
 * @address{BPRE,08001658}
 */
POKEAGB_EXTERN void bg_vram_setup(u8 layer, struct BgConfig* config, u8 layers);

/**
 * @address{BPRE,080F6878}
 */
POKEAGB_EXTERN void* decompress_with_fallback_maybe(u8 layer,
                                                    u8* tiles,
                                                    u16 size,
                                                    u16 offset,
                                                    u8 mode);

/**
 * @address{BPRE,080019BC}
 */
POKEAGB_EXTERN void gpu_sync_bg_show(u8 layer);

/**
 * @address{BPRE,080019D0}
 */
POKEAGB_EXTERN void gpu_sync_bg_hide(u8 layer);

/**
 * @address{BPRE,08007320}
 */
POKEAGB_EXTERN void gpu_sprites_upload(void);

/**
 * @address{BPRE,08007610}
 */
POKEAGB_EXTERN void copy_queue_process(void);

/**
 * @address{BPRE,08002DE8}
 */
POKEAGB_EXTERN void textbox_something(void);

#endif /* POKEAGB_GRAPHICS_BACKGROUND_H_ */
