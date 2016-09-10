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

/**
 * Fetch the block index at the given position for the current map.
 * Uses virtual map coordinates.
 * @address{BPRE,08058E48}
 */
POKEAGB_EXTERN u16 cur_mapdata_get_blockid_at(u16 x, u16 y);

/**
 * Set the block index and permissions at the given position for the
 * current map.  Uses virtual map coordinates.
 * @address{BPRE,08058FEC}
 * @see MapTile
 */
POKEAGB_EXTERN void setmaptile_four_nibbles(u16 x, u16 y, u16 tile);

/**
 * Redraw the tile at the given position.
 * Uses virtual map coordinates.
 * @address{BPRE,0805A8E8}
 */
POKEAGB_EXTERN void cur_mapdata_draw_block_at(u16 x, u16 y);

/**
 * Redraw the tiles visible from the camera's current position.
 * @address{BPRE,0805A684}
 */
POKEAGB_EXTERN void cur_mapdata_full_redraw(void);

POKEAGB_END_DECL

#endif /* POKEAGB_OVERWORLD_VIRTUAL_MAP_H_ */
