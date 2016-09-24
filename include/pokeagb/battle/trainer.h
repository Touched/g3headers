/**
 * @file
 * @brief Trainer related data
 */

#ifndef POKEAGB_BATTLE_TRAINER_H_
#define POKEAGB_BATTLE_TRAINER_H_

#include "../types.h"
#include "../common.h"
#include "../pokemon.h"
#include "../overworld/item.h"

#define TRAINER_COUNT 743
#define TRAINER_CLASS_COUNT 107

struct Trainer {
    u8 flags;
    u8 class;
    u8 music;
    u8 sprite;
    pchar name[10];
    u16 field_E;
    enum Item items[4];
    u32 field_18;
    u32 ai;
    u32 pokemon_number;
    void* party;
};

ASSERT_SIZEOF(struct Trainer, 0x28);

/**
 * @address{BPRE,0823EAC8}
 */
extern struct Trainer trainer_data[TRAINER_COUNT];

/**
 * @address{BPRE,0823E558}
 */
extern pchar trainer_class_names[TRAINER_CLASS_COUNT][13];

/**
 * Fill the trainer party using the Pokemon from the trainer data.
 *
 * @address{BPRE,080112E0}
 */
POKEAGB_EXTERN void setup_opponent_party(struct Pokemon* party, u16 trainer_id);

/**
 * Fill the trainer party using the Pokemon from the trainer data.
 *
 * @address{BPRE,0803DA34}
 */
POKEAGB_EXTERN void pokemon_purge_opponent(void);

/**
 * Returns non-zero if the NPC state for the given index spotted
 * the player. This is for trainers that walk up to the player.
 *
 * @address{BPRE,08081B84}
 */
POKEAGB_EXTERN u8 check_if_npc_spotted_player(u8 npc_state_index);

/**
 * Returns non-zero if the player can't double battle.
 *
 * @address{BPRE,08040CC4}
 */
POKEAGB_EXTERN u8 player_unable_to_double_battle(void);

/**
 * Configure a battle using script arguments. Should be a pointer to
 * the arguments, not the actual trainer battle command.
 *
 * @address{BPRE,08080228}
 */
POKEAGB_EXTERN void battle_configure_by_script(void* script_arguments);

/**
 * Setup the task necessary for the trainer `npc` to walk `distance`
 * squares. Uses some specials to operate.
 *
 * @address{BPRE,08081E68}
 */
void add_task_trainer_walk(struct NpcState* npc, u8 distance);

/**
 * @address{BPRE,020386AE}
 */
extern u16 trainerbattle_flag_id;

#endif /* POKEAGB_BATTLE_TRAINER_H_ */
