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

#ifndef POKEAGB_CORE_CALLBACK_H_
#define POKEAGB_CORE_CALLBACK_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>
#include <pokeagb/graphics/sprites.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef void (*super_callback)(void);

  struct superstate {
    super_callback callback1;
    super_callback callback2;
    super_callback callback2_backup;
    super_callback vblank_handler;
    super_callback hblank_handler;
    super_callback field_14;
    super_callback serial_callback;

    u32 bits_to_wait_for;
    u16 *vblank_counter;
    u32 field_24;

    struct buttons {
      u16 held;
      u16 new;
      u16 held_remapped;
      u16 new_remapped;
      u16 new_and_repeated;
      u16 countdown;
    } buttons;

    u32 unused_apparently;
    struct sprite sprites[128];
    u8 multi_purpose_state_tracker;
    u8 gpu_sprites_upload_skip;
  };

  LONG_CALL void set_callback1(super_callback func);
  LONG_CALL void set_callback2(super_callback func);

  extern struct superstate super;

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_CALLBACK_H_ */
