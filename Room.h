
#ifndef ROOM_H 
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Tile.h"
extern const int TILE_SIZE_TO_PIXELS;
extern const int NUM_ROOMS_PER_FLOOR;
extern const int LENGTH_OF_ROOM;
extern const int WIDTH_OF_ROOM;


class Room{
    private:
        std::vector<std::string> layout_room;
        Tile ***tiles_room;

        void load_room(const std::string& filename);
    

    public:
        Room(const std::string& file_name);
        std::vector<std::string> get_layout_room();
        Tile*** get_tiles();
        ~Room();
};

#endif