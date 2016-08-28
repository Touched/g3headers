#ifndef POKEAGB_CORE_CALLBACK_H_
#define POKEAGB_CORE_CALLBACK_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>
#include <pokeagb/graphics/sprites.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef void (*SuperCallback)(void);

  struct Superstate {
    SuperCallback callback1;
    SuperCallback callback2;
    SuperCallback callback2_backup;
    SuperCallback vblank_handler;
    SuperCallback hblank_handler;
    SuperCallback field_14;
    SuperCallback serial_callback;

    u32 bits_to_wait_for;
    u16* vblank_counter;
    u32 field_24;

    struct Buttons {
      u16 held;
      u16 new;
      u16 held_remapped;
      u16 new_remapped;
      u16 new_and_repeated;
      u16 countdown;
    } buttons;

    u32 unused_apparently;
    struct Sprite sprites[128];
    u8 multi_purpose_state_tracker;
    u8 gpu_sprites_upload_skip;
  };

  LONG_CALL void set_callback1(SuperCallback func);
  LONG_CALL void set_callback2(SuperCallback func);

  extern struct Superstate super;

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_CALLBACK_H_ */
