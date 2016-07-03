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

#ifndef POKEAGB_TYPES_H_
#define POKEAGB_TYPES_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef unsigned char u8;
  typedef unsigned short int u16;
  typedef unsigned int u32;
  typedef signed char s8;
  typedef signed short int s16;
  typedef signed int s32;
  typedef volatile u8 vu8;
  typedef volatile u16 vu16;
  typedef volatile u32 vu32;
  typedef volatile s8 vs8;
  typedef volatile s16 vs16;
  typedef volatile s32 vs32;

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_TYPES_H_ */
