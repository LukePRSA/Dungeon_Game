#include "DungeonFloor.h"

const int TILE_SIZE_TO_PIXELS = 58;
const int NUM_ROOMS_PER_FLOOR = 5;
const int LENGTH_OF_ROOM = 10;
const int WIDTH_OF_ROOM = 14;

int main()
{
    DungeonFloor dungeon_floor;
    dungeon_floor.run_dungeon();
    return 0;
}
