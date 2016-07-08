/*
 * This file is part of PokeAGB.
 *
 * PokeAGB is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PokeAGB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PokeAGB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef POKEAGB_POKEMON_MOVE_H_
#define POKEAGB_POKEMON_MOVE_H_

#include <pokeagb/macros.h>
#include <pokeagb/core/string.h>

#ifdef __cplusplus
extern "C" {
#endif

  #define POKEAGB_MOVE_NAME_LENGTH 13

  enum Move {
    MOVE_NONE,
    MOVE_POUND,
    MOVE_KARATE_CHOP,
    MOVE_DOUBLESLAP,
    MOVE_COMET_PUNCH,
    MOVE_MEGA_PUNCH,
    MOVE_PAY_DAY,
    MOVE_FIRE_PUNCH,
    MOVE_ICE_PUNCH,
    MOVE_THUNDERPUNCH,
    MOVE_SCRATCH,
    MOVE_VICEGRIP,
    MOVE_GUILLOTINE,
    MOVE_RAZOR_WIND,
    MOVE_SWORDS_DANCE,
    MOVE_CUT,
    MOVE_GUST,
    MOVE_WING_ATTACK,
    MOVE_WHIRLWIND,
    MOVE_FLY,
    MOVE_BIND,
    MOVE_SLAM,
    MOVE_VINE_WHIP,
    MOVE_STOMP,
    MOVE_DOUBLE_KICK,
    MOVE_MEGA_KICK,
    MOVE_JUMP_KICK,
    MOVE_ROLLING_KICK,
    MOVE_SAND_ATTACK,
    MOVE_HEADBUTT,
    MOVE_HORN_ATTACK,
    MOVE_FURY_ATTACK,
    MOVE_HORN_DRILL,
    MOVE_TACKLE,
    MOVE_BODY_SLAM,
    MOVE_WRAP,
    MOVE_TAKE_DOWN,
    MOVE_THRASH,
    MOVE_DOUBLE_EDGE,
    MOVE_TAIL_WHIP,
    MOVE_POISON_STING,
    MOVE_TWINEEDLE,
    MOVE_PIN_MISSILE,
    MOVE_LEER,
    MOVE_BITE,
    MOVE_GROWL,
    MOVE_ROAR,
    MOVE_SING,
    MOVE_SUPERSONIC,
    MOVE_SONICBOOM,
    MOVE_DISABLE,
    MOVE_ACID,
    MOVE_EMBER,
    MOVE_FLAMETHROWER,
    MOVE_MIST,
    MOVE_WATER_GUN,
    MOVE_HYDRO_PUMP,
    MOVE_SURF,
    MOVE_ICE_BEAM,
    MOVE_BLIZZARD,
    MOVE_PSYBEAM,
    MOVE_BUBBLEBEAM,
    MOVE_AURORA_BEAM,
    MOVE_HYPER_BEAM,
    MOVE_PECK,
    MOVE_DRILL_PECK,
    MOVE_SUBMISSION,
    MOVE_LOW_KICK,
    MOVE_COUNTER,
    MOVE_SEISMIC_TOSS,
    MOVE_STRENGTH,
    MOVE_ABSORB,
    MOVE_MEGA_DRAIN,
    MOVE_LEECH_SEED,
    MOVE_GROWTH,
    MOVE_RAZOR_LEAF,
    MOVE_SOLARBEAM,
    MOVE_POISONPOWDER,
    MOVE_STUN_SPORE,
    MOVE_SLEEP_POWDER,
    MOVE_PETAL_DANCE,
    MOVE_STRING_SHOT,
    MOVE_DRAGON_RAGE,
    MOVE_FIRE_SPIN,
    MOVE_THUNDERSHOCK,
    MOVE_THUNDERBOLT,
    MOVE_THUNDER_WAVE,
    MOVE_THUNDER,
    MOVE_ROCK_THROW,
    MOVE_EARTHQUAKE,
    MOVE_FISSURE,
    MOVE_DIG,
    MOVE_TOXIC,
    MOVE_CONFUSION,
    MOVE_PSYCHIC,
    MOVE_HYPNOSIS,
    MOVE_MEDITATE,
    MOVE_AGILITY,
    MOVE_QUICK_ATTACK,
    MOVE_RAGE,
    MOVE_TELEPORT,
    MOVE_NIGHT_SHADE,
    MOVE_MIMIC,
    MOVE_SCREECH,
    MOVE_DOUBLE_TEAM,
    MOVE_RECOVER,
    MOVE_HARDEN,
    MOVE_MINIMIZE,
    MOVE_SMOKESCREEN,
    MOVE_CONFUSE_RAY,
    MOVE_WITHDRAW,
    MOVE_DEFENSE_CURL,
    MOVE_BARRIER,
    MOVE_LIGHT_SCREEN,
    MOVE_HAZE,
    MOVE_REFLECT,
    MOVE_FOCUS_ENERGY,
    MOVE_BIDE,
    MOVE_METRONOME,
    MOVE_MIRROR_MOVE,
    MOVE_SELFDESTRUCT,
    MOVE_EGG_BOMB,
    MOVE_LICK,
    MOVE_SMOG,
    MOVE_SLUDGE,
    MOVE_BONE_CLUB,
    MOVE_FIRE_BLAST,
    MOVE_WATERFALL,
    MOVE_CLAMP,
    MOVE_SWIFT,
    MOVE_SKULL_BASH,
    MOVE_SPIKE_CANNON,
    MOVE_CONSTRICT,
    MOVE_AMNESIA,
    MOVE_KINESIS,
    MOVE_SOFTBOILED,
    MOVE_HI_JUMP_KICK,
    MOVE_GLARE,
    MOVE_DREAM_EATER,
    MOVE_POISON_GAS,
    MOVE_BARRAGE,
    MOVE_LEECH_LIFE,
    MOVE_LOVELY_KISS,
    MOVE_SKY_ATTACK,
    MOVE_TRANSFORM,
    MOVE_BUBBLE,
    MOVE_DIZZY_PUNCH,
    MOVE_SPORE,
    MOVE_FLASH,
    MOVE_PSYWAVE,
    MOVE_SPLASH,
    MOVE_ACID_ARMOR,
    MOVE_CRABHAMMER,
    MOVE_EXPLOSION,
    MOVE_FURY_SWIPES,
    MOVE_BONEMERANG,
    MOVE_REST,
    MOVE_ROCK_SLIDE,
    MOVE_HYPER_FANG,
    MOVE_SHARPEN,
    MOVE_CONVERSION,
    MOVE_TRI_ATTACK,
    MOVE_SUPER_FANG,
    MOVE_SLASH,
    MOVE_SUBSTITUTE,
    MOVE_STRUGGLE,
    MOVE_SKETCH,
    MOVE_TRIPLE_KICK,
    MOVE_THIEF,
    MOVE_SPIDER_WEB,
    MOVE_MIND_READER,
    MOVE_NIGHTMARE,
    MOVE_FLAME_WHEEL,
    MOVE_SNORE,
    MOVE_CURSE,
    MOVE_FLAIL,
    MOVE_CONVERSION_2,
    MOVE_AEROBLAST,
    MOVE_COTTON_SPORE,
    MOVE_REVERSAL,
    MOVE_SPITE,
    MOVE_POWDER_SNOW,
    MOVE_PROTECT,
    MOVE_MACH_PUNCH,
    MOVE_SCARY_FACE,
    MOVE_FAINT_ATTACK,
    MOVE_SWEET_KISS,
    MOVE_BELLY_DRUM,
    MOVE_SLUDGE_BOMB,
    MOVE_MUD_SLAP,
    MOVE_OCTAZOOKA,
    MOVE_SPIKES,
    MOVE_ZAP_CANNON,
    MOVE_FORESIGHT,
    MOVE_DESTINY_BOND,
    MOVE_PERISH_SONG,
    MOVE_ICY_WIND,
    MOVE_DETECT,
    MOVE_BONE_RUSH,
    MOVE_LOCK_ON,
    MOVE_OUTRAGE,
    MOVE_SANDSTORM,
    MOVE_GIGA_DRAIN,
    MOVE_ENDURE,
    MOVE_CHARM,
    MOVE_ROLLOUT,
    MOVE_FALSE_SWIPE,
    MOVE_SWAGGER,
    MOVE_MILK_DRINK,
    MOVE_SPARK,
    MOVE_FURY_CUTTER,
    MOVE_STEEL_WING,
    MOVE_MEAN_LOOK,
    MOVE_ATTRACT,
    MOVE_SLEEP_TALK,
    MOVE_HEAL_BELL,
    MOVE_RETURN,
    MOVE_PRESENT,
    MOVE_FRUSTRATION,
    MOVE_SAFEGUARD,
    MOVE_PAIN_SPLIT,
    MOVE_SACRED_FIRE,
    MOVE_MAGNITUDE,
    MOVE_DYNAMICPUNCH,
    MOVE_MEGAHORN,
    MOVE_DRAGONBREATH,
    MOVE_BATON_PASS,
    MOVE_ENCORE,
    MOVE_PURSUIT,
    MOVE_RAPID_SPIN,
    MOVE_SWEET_SCENT,
    MOVE_IRON_TAIL,
    MOVE_METAL_CLAW,
    MOVE_VITAL_THROW,
    MOVE_MORNING_SUN,
    MOVE_SYNTHESIS,
    MOVE_MOONLIGHT,
    MOVE_HIDDEN_POWER,
    MOVE_CROSS_CHOP,
    MOVE_TWISTER,
    MOVE_RAIN_DANCE,
    MOVE_SUNNY_DAY,
    MOVE_CRUNCH,
    MOVE_MIRROR_COAT,
    MOVE_PSYCH_UP,
    MOVE_EXTREMESPEED,
    MOVE_ANCIENTPOWER,
    MOVE_SHADOW_BALL,
    MOVE_FUTURE_SIGHT,
    MOVE_ROCK_SMASH,
    MOVE_WHIRLPOOL,
    MOVE_BEAT_UP,
    MOVE_FAKE_OUT,
    MOVE_UPROAR,
    MOVE_STOCKPILE,
    MOVE_SPIT_UP,
    MOVE_SWALLOW,
    MOVE_HEAT_WAVE,
    MOVE_HAIL,
    MOVE_TORMENT,
    MOVE_FLATTER,
    MOVE_WILL_O_WISP,
    MOVE_MEMENTO,
    MOVE_FACADE,
    MOVE_FOCUS_PUNCH,
    MOVE_SMELLINGSALT,
    MOVE_FOLLOW_ME,
    MOVE_NATURE_POWER,
    MOVE_CHARGE,
    MOVE_TAUNT,
    MOVE_HELPING_HAND,
    MOVE_TRICK,
    MOVE_ROLE_PLAY,
    MOVE_WISH,
    MOVE_ASSIST,
    MOVE_INGRAIN,
    MOVE_SUPERPOWER,
    MOVE_MAGIC_COAT,
    MOVE_RECYCLE,
    MOVE_REVENGE,
    MOVE_BRICK_BREAK,
    MOVE_YAWN,
    MOVE_KNOCK_OFF,
    MOVE_ENDEAVOR,
    MOVE_ERUPTION,
    MOVE_SKILL_SWAP,
    MOVE_IMPRISON,
    MOVE_REFRESH,
    MOVE_GRUDGE,
    MOVE_SNATCH,
    MOVE_SECRET_POWER,
    MOVE_DIVE,
    MOVE_ARM_THRUST,
    MOVE_CAMOUFLAGE,
    MOVE_TAIL_GLOW,
    MOVE_LUSTER_PURGE,
    MOVE_MIST_BALL,
    MOVE_FEATHERDANCE,
    MOVE_TEETER_DANCE,
    MOVE_BLAZE_KICK,
    MOVE_MUD_SPORT,
    MOVE_ICE_BALL,
    MOVE_NEEDLE_ARM,
    MOVE_SLACK_OFF,
    MOVE_HYPER_VOICE,
    MOVE_POISON_FANG,
    MOVE_CRUSH_CLAW,
    MOVE_BLAST_BURN,
    MOVE_HYDRO_CANNON,
    MOVE_METEOR_MASH,
    MOVE_ASTONISH,
    MOVE_WEATHER_BALL,
    MOVE_AROMATHERAPY,
    MOVE_FAKE_TEARS,
    MOVE_AIR_CUTTER,
    MOVE_OVERHEAT,
    MOVE_ODOR_SLEUTH,
    MOVE_ROCK_TOMB,
    MOVE_SILVER_WIND,
    MOVE_METAL_SOUND,
    MOVE_GRASSWHISTLE,
    MOVE_TICKLE,
    MOVE_COSMIC_POWER,
    MOVE_WATER_SPOUT,
    MOVE_SIGNAL_BEAM,
    MOVE_SHADOW_PUNCH,
    MOVE_EXTRASENSORY,
    MOVE_SKY_UPPERCUT,
    MOVE_SAND_TOMB,
    MOVE_SHEER_COLD,
    MOVE_MUDDY_WATER,
    MOVE_BULLET_SEED,
    MOVE_AERIAL_ACE,
    MOVE_ICICLE_SPEAR,
    MOVE_IRON_DEFENSE,
    MOVE_BLOCK,
    MOVE_HOWL,
    MOVE_DRAGON_CLAW,
    MOVE_FRENZY_PLANT,
    MOVE_BULK_UP,
    MOVE_BOUNCE,
    MOVE_MUD_SHOT,
    MOVE_POISON_TAIL,
    MOVE_COVET,
    MOVE_VOLT_TACKLE,
    MOVE_MAGICAL_LEAF,
    MOVE_WATER_SPORT,
    MOVE_CALM_MIND,
    MOVE_LEAF_BLADE,
    MOVE_DRAGON_DANCE,
    MOVE_ROCK_BLAST,
    MOVE_SHOCK_WAVE,
    MOVE_WATER_PULSE,
    MOVE_DOOM_DESIRE,
    MOVE_PYSCHO_BOOST,
    MOVE_MAX,
  };

  ASSERT_SIZEOF(enum Move, 2);

  struct MoveDataTarget {
    u8 select: 1; /**< Selected target */
    u8 variable: 1; /**< Depends on the attack */
    u8 unused: 1; /**< Unused
                     @note LIES! More investigation required. Possible effects on trainer ai. */
    u8 random: 1; /**< Random target */
    u8 both: 1; /**< Both foes */
    u8 self: 1; /**< User */
    u8 others: 1; /**< Both foes and partner */
    u8 opponents: 1; /**< Opponent field */
  };

  struct MoveDataFlags {
      u8 contact: 1; /**< This moves makes contact with the target. */
      u8 protect: 1; /**< This move is affected by Protect. */
      u8 magic_coat: 1; /**< This move is affected by Magic Coat. */
      u8 snatch: 1; /**< This move is affected by Snatch.
                       @note Mutually-exclusive with magic_coat */
      u8 mirror_move: 1; /**< This move may be used with Mirror Move */
      u8 kings_rock: 1; /**< This move is affected by the effects of Kings Rock. */
  };

  struct MoveData {
    u8 move_script_id;
    u8 power;
    u8 type;
    u8 accuracy;
    u8 pp;
    u8 effect_accuracy;
    struct MoveDataTarget target;
    u8 priority;
    struct MoveDataFlags flags;
    u8 padding[3];
  };

  ASSERT_SIZEOF(struct MoveData, 0xC);

  extern struct MoveData pokemon_moves[MOVE_MAX];

  extern pchar pokemon_move_names[MOVE_MAX][POKEAGB_MOVE_NAME_LENGTH];

  struct LearnsetEntry {
    enum Move move: 9;
    u8 level: 7;
  };

  extern struct LearnsetEntry* pokemon_learnset[10];

  ASSERT_SIZEOF(struct LearnsetEntry, 2);

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_POKEMON_MOVE_H_ */
