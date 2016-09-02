/**
 * @file
 * @brief The overworld map in memory.
 */

#ifndef POKEAGB_OVERWORLD_VIRTUAL_MAP_H_
#define POKEAGB_OVERWORLD_VIRTUAL_MAP_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/overworld/map.h>

POKEAGB_BEGIN_DECL

/**
 * The amount of extra blocks to add to the map height to create a virtual map.
 */
#define VIRTUAL_MAP_VERTICAL_PADDING 14

/**
 * The amount of extra blocks to add to the map width to create a virtual map.
 */
#define VIRTUAL_MAP_HORIZONTAL_PADDING 15

/**
 * The amount of blocks in the border of the virtual map.
 */
#define VIRTUAL_MAP_BORDER_SIZE 7

/**
 * The map loaded in memory. It includes the blocks from adjacent,
 * connected maps in the padding area.
 */
struct VirtualMapHeader {
    u32 width;
    u32 height;
    struct MapTile* data;
};

POKEAGB_END_DECL

#endif /* POKEAGB_OVERWORLD_VIRTUAL_MAP_H_ */
