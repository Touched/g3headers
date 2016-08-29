#ifndef POKEAGB_POKEMON_BASE_H_
#define POKEAGB_POKEMON_BASE_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/core/string.h>
#include <pokeagb/pokemon/type.h>
#include <pokeagb/pokemon/ability.h>
#include <pokeagb/overworld/item.h>

#ifdef __cplusplus
extern "C" {
#endif

  #define POKEAGB_POKEMON_SLOTS 412
  #define POKEAGB_POKEMON_NAME_LENGTH 11

  enum PokemonEggGroup {
    EGG_GROUP_MONSTER,
    EGG_GROUP_WATER1,
    EGG_GROUP_BUG,
    EGG_GROUP_FLYING,
    EGG_GROUP_FIELD,
    EGG_GROUP_FAIRY,
    EGG_GROUP_GRASS,
    EGG_GROUP_HUMAN_LIKE,
    EGG_GROUP_WATER3,
    EGG_GROUP_MINERAL,
    EGG_GROUP_AMORPHOUS,
    EGG_GROUP_WATER2,
    EGG_GROUP_DITTO,
    EGG_GROUP_DRAGON,
    EGG_GROUP_UNDISCOVERED
  };

  ASSERT_SIZEOF(enum PokemonEggGroup, 1);

  enum PokemonExpGrowth {
    EXP_MEDIUM_FAST,
    EXP_ERRATIC,
    EXP_FLUCTUATING,
    EXP_MEDIUM_SLOW,
    EXP_FAST,
    EXP_SLOW
  };

  ASSERT_SIZEOF(enum PokemonExpGrowth, 1);

  enum PokemonColor {
    POKEMON_COLOR_RED,
    POKEMON_COLOR_BLUE,
    POKEMON_COLOR_YELLOW,
    POKEMON_COLOR_GREEN,
    POKEMON_COLOR_BLACK,
    POKEMON_COLOR_BROWN,
    POKEMON_COLOR_PURPLE,
    POKEMON_COLOR_GRAY,
    POKEMON_COLOR_WHITE,
    POKEMON_COLOR_PINK
  };

  ASSERT_SIZEOF(enum PokemonColor, 1);

  struct PokemonBaseStat {
    u8 hp;
    u8 atk;
    u8 def;
    u8 spd;
    u8 spatk;
    u8 spdef;
    enum PokemonType type[2];
    u8 catch_rate;
    u8 xp_yield;
    u16 effort_yield;
    enum Item item[2];
    u8 gender_ratio;
    u8 steps_to_hatch;
    u8 base_friendship;
    enum PokemonExpGrowth exp_growth;
    enum PokemonEggGroup eggroup[2];
    enum PokemonAbility ability[2];
    u8 safari_zone_flee_rate;
    enum PokemonColor color;
    u16 padding;
  };

  ASSERT_SIZEOF(struct PokemonBaseStat, 0x1C);

  /**
   * Pokemon base stats table.
   *
   * @address{BPRE,08254784}
   */
  extern struct PokemonBaseStat pokemon_base_stats[POKEAGB_POKEMON_SLOTS];

  /**
   * Pokemon names table.
   *
   * @address{BPRE,08245EE0}
   */
  extern pchar pokemon_names[POKEAGB_POKEMON_SLOTS][POKEAGB_POKEMON_NAME_LENGTH];

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_POKEMON_BASE_H_ */
