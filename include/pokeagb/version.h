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

#ifndef POKEAGB_VERSION_H_
#define POKEAGB_VERSION_H_

/* Derive version from ROM code */
#if defined(ROM_AXPD) || defined(ROM_AXPE) || defined(ROM_AXPF) || \
  defined(ROM_AXPI) || defined(ROM_AXPJ) || defined(ROM_AXPS)
#define VERSION_SAPPHIRE
#endif

#if defined(ROM_AXVD) || defined(ROM_AXVE) || defined(ROM_AXVF) || \
  defined(ROM_AXVI) || defined(ROM_AXVJ) || defined(ROM_AXVS)
#define VERSION_RUBY
#endif

#if defined(ROM_BPED) || defined(ROM_BPEE) || defined(ROM_BPEF) || \
  defined(ROM_BPEI) || defined(ROM_BPEJ) || defined(ROM_BPES)
#define VERSION_EMERALD
#endif

#if defined(ROM_BPGD) || defined(ROM_BPGE) || defined(ROM_BPGF) || \
  defined(ROM_BPGI) || defined(ROM_BPGJ) || defined(ROM_BPGS)
#define VERSION_LEAFGREEN
#endif

#if defined(ROM_BPRD) || defined(ROM_BPRE) || defined(ROM_BPRF) || \
  defined(ROM_BPRI) || defined(ROM_BPRJ) || defined(ROM_BPRS)
#define VERSION_FIRERED
#endif

/* Derive language from ROM code */
#if defined(ROM_AXPD) || defined(ROM_AXVD) || defined(ROM_BPED) || \
  defined(ROM_BPGD) || defined(ROM_BPRD)
#define LANGUAGE_GERMAN
#endif

#if defined(ROM_AXPE) || defined(ROM_AXVE) || defined(ROM_BPEE) || \
  defined(ROM_BPGE) || defined(ROM_BPRE)
#define LANGUAGE_ENGLISH
#endif

#if defined(ROM_AXPF) || defined(ROM_AXVF) || defined(ROM_BPEF) || \
  defined(ROM_BPGF) || defined(ROM_BPRF)
#define LANGUAGE_FRENCH
#endif

#if defined(ROM_AXPI) || defined(ROM_AXVI) || defined(ROM_BPEI) || \
  defined(ROM_BPGI) || defined(ROM_BPRI)
#define LANGUAGE_ITALIAN
#endif

#if defined(ROM_AXPJ) || defined(ROM_AXVJ) || defined(ROM_BPEJ) || \
  defined(ROM_BPGJ) || defined(ROM_BPRJ)
#define LANGUAGE_JAPANESE
#endif

#if defined(ROM_AXPS) || defined(ROM_AXVS) || defined(ROM_BPES) || \
  defined(ROM_BPGS) || defined(ROM_BPRS)
#define LANGUAGE_SPANISH
#endif

/* Group versions */
#if defined(VERSION_FIRERED) || defined(VERSION_LEAFGREEN)
#define VERSION_FRLG
#endif

#if defined(VERSION_RUBY) || defined(VERSION_SAPPHIRE) || \
  defined(VERSION_EMERALD)
#define VERSION_RSE
#endif

#endif /* POKEAGB_VERSION_H_ */
