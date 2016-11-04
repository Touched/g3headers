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


struct ScrollArrows {
    struct Arrow {
        /* TODO: Enum direction */
        u8 orientation;
        u8 x;
        u8 y;
    } positions[2];

    /**
     * Arrow IDs. A pointer to the arrow ID function can be passed in
     * to the spawning function. If the value at that pointer is equal
     * to the ID in this array, then the arrow is visible. There are
     * two slots for the two arrows.
     */
    u16 ids[2];

    /**
     * The tiles tag or 0xFFFF.
     */
    u16 tiles_tag;

    /**
     * The palette tag or 0xFFFF.
     */
    u16 palette_tag;

    /**
     * The palette slot index to start copying the arrow palette to.
     */
    u8 palette_index;
};

ASSERT_SIZEOF(struct ScrollArrows, 16);
ASSERT_OFFSETOF(struct ScrollArrows, positions, 0);
ASSERT_OFFSETOF(struct ScrollArrows, ids, 6);
ASSERT_OFFSETOF(struct ScrollArrows, tiles_tag, 10);
ASSERT_OFFSETOF(struct ScrollArrows, palette_tag, 12);
ASSERT_OFFSETOF(struct ScrollArrows, palette_index, 14);

struct ScrollArrowTaskState {
    u8 starts_zero;
    u16* current_arrow_id;
    u16 arrow_ids[2];
    u16 unknown;
    u16 tiles_tag;
    u16 palette_tag;
};

/**
 * Draw a pair of red arrows to indicate scrolling. This creates a
 * task with the private state layout seen in ScrollArrowTaskState
 *
 * @param data The box that the arrows must be drawn around.
 * @param arrows Pointer to a byte which controls which arrows ID to activate.
 * @returns Task ID
 * @address{BPRE,08133A20}
 */
POKEAGB_EXTERN u8 textbox_spawn_scroll_arrows(const struct ScrollArrows* data, u16* arrows);

/**
 * Clean up the scroll arrows and delete the task. Set the task
 * function for the task returned from textbox_spawn_scroll_arrows to
 * this to clean up.
 *
 * @address{BPRE,08133C30}
 */
POKEAGB_EXTERN void textbox_task_delete_scroll_arrows(u8 task_id);

#define FCODE_BUFFER_SIZE 20
#define STRING_BUFFER_SIZE 1000

/**
 * Generic buffer for strings.
 * @address{BPRE,02021CD0}
 */
extern pchar fcode_buffer2[FCODE_BUFFER_SIZE];

/**
 * Generic buffer for strings.
 * @address{BPRE,02021CF0}
 */
extern pchar fcode_buffer3[FCODE_BUFFER_SIZE];

/**
 * Generic buffer for strings.
 * @address{BPRE,02021D04}
 */
extern pchar fcode_buffer4[FCODE_BUFFER_SIZE];

/**
 * Generic buffer also used for strings 
 * @address{BPRE,02021D18}
 */
extern pchar string_buffer[STRING_BUFFER_SIZE];

/**
 * Copies the 0xFF terminated string from source to desination.
 * @address{BPRE,08008D84}
 */
POKEAGB_EXTERN pchar* pstrcpy(pchar* dst, const pchar* src);

/**
 * Appends a copy of the source to the end of the 0xFF terminated string at destination.
 * @address{BPRE,08008DA4}
 */
POKEAGB_EXTERN pchar* pstrcat(pchar* dst, const pchar* src);

/**
 * Returns the length of the 0xFF terminated string.
 * @address{BPRE,08008E08}
 */
POKEAGB_EXTERN u16 pstrlen(pchar* s);

/**
 * Converts int to pstring. Maybe more.
 * @address{BPRE,08008E78}
 */
POKEAGB_EXTERN pchar* fmt_int_10(pchar* dst, u32 num, u8, u8);

/**
 * @address{BPRE,08002C28}
 */
POKEAGB_EXTERN void remo_reset_acknowledgement_flags(void);

/**
 * @address{BPRE,08003ECC}
 */
POKEAGB_EXTERN void rboxes_free(void);

/**
 * @address{BPRE,0808002DE8}
 */
POKEAGB_EXTERN void remoboxes_upload_tilesets();
 

POKEAGB_END_DECL

#endif /* POKEAGB_CORE_STRING_H_ */
