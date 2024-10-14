
#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Tile.h"
#include "RoomObject.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "MeleeEnemy.h"
#include "StrikerEnemy.h"
#include "BasicBoss.h"
#include "HealthConsumable.h"
#include "Trap.h"
#include "ArrowTrap.h"
#include "SpikeTrap.h"
extern const int TILE_SIZE_TO_PIXELS;
extern const int NUM_ROOMS_PER_FLOOR;
extern const int LENGTH_OF_ROOM;
extern const int WIDTH_OF_ROOM;

class Room
{
private:
    std::vector<std::string> layout_room;
    Tile ***tiles_room;

    void load_room(const std::string &filename);

    RoomObject *walls;
    int num_walls;
    Entity *breakable_walls;
    int num_breakable_walls;
    Enemy *enemies;
    int num_alive_entities;
    int num_enemies;
    Trap *traps;
    int num_traps;
    HealthConsumable *health_consumables;
    int num_consumables;
    Player *player;
    RoomObject entrance;
    sf::Vector2f start_position;
    RoomObject exit;
    sf::Vector2f end_position;

public:
    Room(const std::string &file_name);
    std::vector<std::string> get_layout_room();
    Tile ***get_tiles();

    void load_objects(bool from_next_room);
    void unload_objects();
    void draw_objects(sf::RenderWindow* display);
    void pass_turn();
    void check_player_collisions();
    void check_other_collisions();
    void toggle_traps();
    bool has_hit_walls(sf::Shape *body);
    void check_exit_availability();
    bool has_collided_with_entrance();
    bool has_collided_with_exit();

    ~Room();
};

#endif