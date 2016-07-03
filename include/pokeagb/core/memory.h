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

#ifndef POKEAGB_CORE_MEMORY_H_
#define POKEAGB_CORE_MEMORY_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>

#ifdef __cplusplus
extern "C" {
#endif

  LONG_CALL void* malloc(u32 size);
  LONG_CALL void* malloc_and_clear(u32 size);
  LONG_CALL void free(void* ptr);
  LONG_CALL void* memcpy(void* dst, const void* src, u32 size);
  LONG_CALL void memset(void* dst, u8 value, u32 size);

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_MEMORY_H_ */
