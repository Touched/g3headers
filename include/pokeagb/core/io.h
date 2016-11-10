/**
 * @file
 * @brief GBA IO registers
 */

#ifndef POKEAGB_CORE_IO_H_
#define POKEAGB_CORE_IO_H_

#include "../common.h"
#include "../types.h"

/*
 * Macro alternative to icd_io_set, but ofcourse not is vblank synced, which is important for Hblank IRQ
 */

#define ADDR_REG_WININ 0x4000048
#define WRITE_REG_WININ(value) ((*(volatile uint16_t *)ADDR_REG_WININ) = (value))

#define ADDR_REG_BLDCNT 0x4000050
#define WRITE_REG_BLDCNT(value) ((*(volatile uint16_t *)ADDR_REG_BLDCNT) = (value))

/*
 *
 * IO Registers. Sequentially ordered
 *
 */

struct dispstat {
	u16 v_refresh : 1;
	u16 h_refresh : 1;
	u16 vcount_trigger : 1;
	u16 IRQ_vblank : 1;
	u16 IRQ_hblank : 1;
	u16 IRQ_vcount_trigger : 1;
	u16 padding : 2;
	u16 vcount_line_trigger : 8;
};

/**
 * REG_DISPSTAT
 * @address{BPRE,04000004}
 */
extern struct dispstat REG_DISPSTAT;


/**
 * REG_VCOUNT
 * @address{BPRE,04000006}
 */
extern u16 REG_VCOUNT;

#define WIN0_BG0 1
#define WIN0_BG1 2
#define WIN0_BG2 4
#define WIN0_BG3 8
#define WIN0_SPRITES 16
#define WIN0_BLENDS 32
#define WIN1_BG0 256
#define WIN1_BG1 512
#define WIN1_BG2 1024	
#define WIN1_BG3 2048
#define WIN1_SPRITES 4096
#define WIN1_BLENDS 8192

struct win_in {
	u16 win0_BG0 : 1;
	u16 win0_BG1 : 1;
	u16 win0_BG2 : 1;
	u16 win0_BG3 : 1;
	u16 win0_sprites : 1;
	u16 win0_blends : 1;
	u16 padding0 : 2;
	u16 win1_BG0 : 1;
	u16 win1_BG1 : 1;
	u16 win1_BG2 : 1;
	u16 win1_BG3 : 1;
	u16 win1_sprites : 1;
	u16 win1_blends : 1;
	u16 padding1 : 2;
};

 
/**
 * WININ register
 * @address{BPRE,04000048}
 */
extern struct win_in REG_WININ;

#define BLD_BG0_SRC 1
#define BLD_BG1_SRC 2
#define BLD_BG2_SRC 4
#define BLD_BG3_SRC 8
#define BLD_SPRITES_SRC 16
#define BLD_BACKDROP_SRC 32
#define BLD_ALPHA_BLEND 64
#define BLD_LIGHTEN 128
#define BLD_DARKEN 192
#define BLD_BG0_DST 256
#define BLD_BG1_DST 512
#define BLD_BG2_DST 1024
#define BLD_BG3_DST 2048
#define BLD_SPRITES_DST 4096
#define BLD_BACKDROP_DST 8192

struct bldmod {
	u16 bg0_src : 1;
	u16 bg1_src : 1;
	u16 bg2_src : 1;
	u16 bg3_src : 1;
	u16 sprites_src : 1;
	u16 backdrop : 1;
	u16 mode : 2;	/*	00: All effects off 
						01: alpha blend 
						10: lighten (fade to white) 
						11: darken (fade to black)
					*/
	u16 bg0_dst : 1;
	u16 bg1_dst : 1;
	u16 bg2_dst : 1;
	u16 bg3_dst : 1;
	u16 sprites_dst : 1;
	u16 backdrop_dst : 1;
	u16 padding : 2;
};


/**
 * BLDMOD register
 * @address{BPRE,04000050}
 */
extern struct bldmod REG_BLDCNT;


struct bld_alpha {
	u16 coA : 5;
	u16 padding : 3;
	u16 coB : 5;
	u16 padding2 : 3;
	
};


/**
 * bldalpha register
 * @address{BPRE,04000052}
 */
extern struct bld_alpha REG_COLEV;


struct bldy {
	u16 fade : 5;
	u16 padding : 11;
};

/**
 * BLDY register
 * @address{BPRE,04000054}
 */
extern struct bldy REG_COLEY;


struct interrupt_register {
	u16 vblank_int : 1;
	u16 hblank_int : 1;
	u16 vcount_int : 1;
	u16 timer0_int : 1;
	u16 timer1_int : 1;
	u16 timer2_int : 1;
	u16 timer3_int : 1;
	u16 serial_comm_int : 1;
	u16 DMA0_int : 1;
	u16 DMA1_int : 1;
	u16 DMA2_int : 1;
	u16 DMA3_int : 1;
	u16 key_int : 1;
	u16 cassette_int : 1;
	u16 padding : 2;
};

/**
 * Set a bit to enable an interrupt
 * REG_DISPSTAT
 * @address{BPRE,04000200}
 */
extern struct interrupt_register REG_IE;

/**
 * write 1 to corresponding bit to acknowledge interrupt
 * has been completed. REG_DISPSTAT
 * @address{BPRE,04000202}
 */
extern struct interrupt_register REG_IF;


/**
 * REG_DISPSTAT
 * @address{BPRE,04000208}
 */
extern u16 REG_IME;


/*
 *
 * IO Register dealing functions 
 *
 */


/**
 * 0x4000000 + number = reg_id -> the register to modify
 * @address{BPRE,08000A38}
 */
POKEAGB_EXTERN void lcd_io_set(u8 reg_id, u16 value);

/**
 *
 * @address{BPRE,08000B68}
 */
POKEAGB_EXTERN void interrupts_enable(u8);

/**
 *
 * @address{BPRE,08000B94}
 */
POKEAGB_EXTERN void interrupts_disable(u8);

#endif /* POKEAGB_CORE_IO_H_ */
