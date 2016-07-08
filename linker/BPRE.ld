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

INCLUDE common.ld

/*
 * include/pokeagb/core/callback.h
 */

set_callback1 = 0x080565E0|1;
set_callback2 = 0x08000544|1;

super = 0x030030F0;

/*
 * include/pokeagb/core/memory.h
 */

malloc = 0x08002B9C|1;
malloc_and_clear = 0x08002BB0|1;
free = 0x08002BC4|1;
memcpy = 0x081E5E78|1;
memset = 0x081E5ED8|1;

/*
 * include/pokeagb/core/random.h
 */

set_rand_seed = 0x08044EE8|1;
rand = 0x08044EC8|1;

/*
 * include/pokeagb/core/task.h
 */

task_add = 0x0807741C|1;
task_del = 0x08077508|1;
task_exec = 0x08077578|1;

tasks = 0x03005090;

/*
 * include/pokeagb/graphics/sprites.h
 */

objects = 0x0202063C;

/*
 * include/pokeagb/overworld/item.h
 */

items = 0x083DB028;

/*
 * include/pokeagb/overworld/npc.h
 */

npc_half_reset_no_checks = 0x08063D34|1;
npc_half_reset = 0x08063D1C|1;
npc_set_state_2 = 0x08063CA4|1;
npc_half_reset_when_bit7_is_set = 0x08063D7C|1;
rom_npc_by_local_id_and_map = 0x0805FD5C|1;
npc_instanciation_something = 0x0805E72C|1;
npc_change_sprite = 0x0805F060|1;
npc_turn = 0x0805F218|1;

walkrun_state = 0x02037078;
npc_states = 0x02036E38;

/*
 * include/pokeagb/pokemon/ability.h
 */

pokemon_ability_names = 0x0824FC40;

/*
 * include/pokeagb/pokemon/base.h
 */

pokemon_base_stats = 0x08254784;
pokemon_names = 0x08245EE0;

/*
 * include/pokeagb/pokemon/move.h
 */

pokemon_moves = 0x08250C04;
pokemon_move_names = 0x08247094;
pokemon_learnset = 0x0825D7B4;

/*
 * include/pokeagb/pokemon/type.h
 */

pokemon_type_names = 0x0824F1A0;
