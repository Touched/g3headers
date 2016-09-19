/**
 * @file
 * @brief Palettes
 */

#ifndef POKEAGB_GRAPHICS_PALETTE_H_
#define POKEAGB_GRAPHICS_PALETTE_H_

struct FadeControl {
    u16 bg_pal_bitfield;
    u16 obj_pal_bitfield;
    u8 delay_counter:6;
    u16 y:5; // blend coefficient
    u16 target_y:5; // target blend coefficient
    u16 blend_color:15;
    u16 active:1;
    u16 multipurpose:6;
    u16 y_dec:1; // whether blend coefficient is decreasing
    u16 buffer_transfer_disabled:1;
    u16 mode:2;
    u16 should_reset_blend_registers:1;
    u16 hardware_fade_finishing:1;
    u16 software_fade_finishing_counter:5;
    u16 software_fade_finishing:1;
    u16 obj_palette_toggle:1;
    u8 delta_y:4; // rate of change of blend coefficient
};

/**
 * @address{BPRE,02037AB8}
 */
struct FadeControl pal_fade_control;

/**
 * @address{BPRE,080703EC}
 */
POKEAGB_EXTERN void gpu_pal_apply(u8* palette, u16 offset, u16 size);

/**
 * @address{BPRE,08070588}
 */
POKEAGB_EXTERN bool fade_screen(u32 bitmask, s8 speed, u8 to, u8 from, u16 color);

/**
 * @address{BPRE,080704D0}
 */
POKEAGB_EXTERN void fade_and_return_progress_probably(void);

/**
 * @address{BPRE,08070474}
 */
POKEAGB_EXTERN void gpu_pal_upload(void);

#endif /* POKEAGB_GRAPHICS_PALETTE_H_ */
