#ifndef DUNGEONFLOOR_H
#define DUNGEONFLOOR_H


#include "Room.h"
#include "Tile.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
extern const int TILE_SIZE_TO_PIXELS;
extern const int NUM_ROOMS_PER_FLOOR;
extern const int LENGTH_OF_ROOM;
extern const int WIDTH_OF_ROOM;

class DungeonFloor{
    private:
        Room **floor_one;
        sf::RenderWindow& window;
        int active_room;
        Player player;

    public:
        DungeonFloor(sf::RenderWindow& window);
        void draw_room();
        int get_active_room();
        void set_active_room(int room_num);
        bool testing_mouse_collision(sf::Vector2i mouse_pos);
        void run_dungeon();
        void check_user_inputs(sf::Event event);
        void to_next_room();
        void to_previous_room();
        ~DungeonFloor();
};

#endif