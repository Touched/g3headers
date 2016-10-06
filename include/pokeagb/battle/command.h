/**
 * @file
 * @brief Internal battle commands
 */

#ifndef POKEAGB_BATTLE_COMMAND_H_
#define POKEAGB_BATTLE_COMMAND_H_

#include "../types.h"
#include "../common.h"

#define BATTLE_SIDES 4
#define BATTLE_COMMAND_BUFFER_SIZE 0x200

enum BattleSide {
    SIDE_PLAYER,
    SIDE_OPPONENT,
};

enum BattleBank {
    BANK_PLAYER,
    BANK_OPPONENT,
    BANK_PLAYER_ALLY,
    BANK_OPPONENT_ALLY,
};

/**
 * @address{BPRE,03004FE0}
 */
extern void (*b_x[BATTLE_SIDES])(void);

/**
 * @address{BPRE,02023BC4}
 */
extern u8 b_active_side;

/**
 * @address{BPRE,02023D6B}
 */
extern u8 b_attacker;

/**
 * @address{BPRE,02023D6C}
 */
extern u8 b_defender;

/**
 * @address{BPRE,02023D6D}
 */
extern u8 b_attacker_partner;

/**
 * @address{BPRE,02023D6E}
 */
extern u8 b_defender_partner;

/**
 * @address{BPRE,02023D70}
 */
extern u8 absent_flags_for_banks;

/**
 * @address{BPRE,02023BC8}
 */
extern u32 b_buffers_awaiting_execution_bitfield;

/**
 * @address{BPRE,02022BC4}
 */
extern u8 b_buffer_A[BATTLE_SIDES][BATTLE_COMMAND_BUFFER_SIZE];

/**
 * @address{BPRE,020233C4}
 */
extern u8 b_buffer_B[BATTLE_SIDES][BATTLE_COMMAND_BUFFER_SIZE];

/**
 * @address{BPRE,080751C4}
 */
POKEAGB_EXTERN enum BattleSide battle_side_get_owner(enum BattleBank side);

/**
 * Prepare the AI for the current Pokemon.
 *
 * @address{BPRE,080C6DA0}
 */
POKEAGB_EXTERN void tai_prepare_struct(void);

/**
 * Uses the AI to pick a move index for the current Pokemon.
 *
 * @address{BPRE,080C6F44}
 */
POKEAGB_EXTERN u8 tai_pick_move(void);

/**
 * @address{BPRE,080751E8}
 */
POKEAGB_EXTERN u8 battle_get_side_with_given_state(u8 state);

/**
 * Uses the AI to pick a move index for the current Pokemon.
 *
 * @address{BPRE,080751D8}
 */
POKEAGB_EXTERN u8 battle_get_per_side_status(u8 bank);

/**
 * Mark the buffer as needing execution
 *
 * @address{BPRE,08017248}
 */
POKEAGB_EXTERN void dp01_battle_side_mark_buffer_for_execution(u8 buffer);

/**
 * Select a move to attack with.
 *
 * @address{BPRE,0800E848}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x21_a_bb(u8 buffer, u8, u16* moves);

/**
 * Perform a switch in.
 *
 * @address{BPRE,0800E874}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x22(u8 buffer, u8 index, u8);

/**
 * Select a move to attack with.
 *
 * @address{BPRE,0800E0D4}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x07(u8 buffer);

/**
 * Slide out OAM on the bank.
 *
 * @address{BPRE,0800E114}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x09(u8 buffer);

/**
 * The Pokemon party index by bank number.
 *
 * @address{BPRE,02023BCE}
 */
extern u16 b_pokemon_team_id_by_side[BATTLE_SIDES];

#endif /* POKEAGB_BATTLE_COMMAND_H_ */
