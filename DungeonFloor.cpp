
#include "Room.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "DungeonFloor.h"

// Creates dungeon floor, its rooms and player then loads the active 1st room.
DungeonFloor::DungeonFloor() : active_room(0), player(TILE_SIZE_TO_PIXELS)
{
    floor_one = new Room *[NUM_ROOMS_PER_FLOOR];

    // uses file data to individually create each room
    const std::string file_path_rooms[NUM_ROOMS_PER_FLOOR] = {"floor_layout/1.txt", "floor_layout/2.txt", "floor_layout/3.txt", "floor_layout/4.txt", "floor_layout/5.txt"};
    floor_one[0] = new Room(file_path_rooms[0], &player, 0);
    floor_one[1] = new Room(file_path_rooms[1], &player, 0);
    floor_one[2] = new Room(file_path_rooms[2], &player, 1);
    floor_one[3] = new Room(file_path_rooms[3], &player, 1);
    floor_one[4] = new Room(file_path_rooms[4], &player, 2);

    floor_one[active_room]->load_objects(false);

    std::cout << "Basic Dungeon Game." << std::endl;
}

// Displays all info about game.
void DungeonFloor::spam_how_to_play()
{
    std::cout << std::endl;
    std::cout << "Tutorial" << std::endl;
    std::cout << "Aim: reach end of game (last room) without dying." << std::endl;
    std::cout << "Player is a teal circle. WASD to move. Space to dodge in direction." << std::endl;
    std::cout << "O to melee attack, P to ranged attack, N to bring up tutorial." << std::endl;
    std::cout << std::endl;
    std::cout << "Enemies block your path and attack you. Defeat all of them in a room to progress." << std::endl;
    std::cout << "Melee enemies (orange circles) approach player and attack." << std::endl;
    std::cout << "Striker enemies (yellow squares) summon strikes from the sky." << std::endl;
    std::cout << "Basic boss (red circle) appears in last room and has a multitude of attacks. Beware!" << std::endl;
    std::cout << std::endl;
    std::cout << "Be careful! There are traps present throughout the dungeon." << std::endl;
    std::cout << "Arrow traps (light grey squares) shoot brown arrows periodically." << std::endl;
    std::cout << "Spike traps (dark grey squares) trigger when stepped on." << std::endl;
    std::cout << "There are also health consumables (green circles) that heal hp throughout the dungeon." << std::endl;
    std::cout << "Good luck!" << std::endl << std::endl;
}

// unused? for testing?
/*
void DungeonFloor::draw_room()
{

    for (int i = 0; i < LENGTH_OF_ROOM; i++)
    {
        for (int j = 0; j < WIDTH_OF_ROOM; j++)
        {

            Tile *tile_in_loop = floor_one[active_room]->get_tiles()[i][j];

            tile_in_loop->set_position(j * TILE_SIZE_TO_PIXELS, i * TILE_SIZE_TO_PIXELS);

            if (tile_in_loop->get_type() == '#')
            {
                tile_in_loop->set_fill_colour(sf::Color::Blue); // wall colour
            }
            else if (tile_in_loop->get_type() == '.')
            {
                tile_in_loop->set_fill_colour(sf::Color::White); // free space colour
            }
            else if (tile_in_loop->get_type() == 'E')
            {
                tile_in_loop->set_fill_colour(sf::Color::Red); // enemy colour
            }
            else if (tile_in_loop->get_type() == 'L')
            {
                tile_in_loop->set_fill_colour(sf::Color::Green); // exit colour
            }
            else if (tile_in_loop->get_type() == 'C')
            {
                tile_in_loop->set_fill_colour(sf::Color::Magenta); // chest colour
            }
            else if (tile_in_loop->get_type() == 'P')
            {
                tile_in_loop->set_fill_colour(sf::Color::Black); // player colour
            }
            window.draw(tile_in_loop->get_shape());
        }
    }
}
*/

int DungeonFloor::get_active_room()
{
    return active_room;
}

void DungeonFloor::set_active_room(int room_num)
{
    this->active_room = room_num;
}

bool DungeonFloor::testing_mouse_collision(sf::Vector2i mouse_pos)
{

    for (int i = 0; i < LENGTH_OF_ROOM; i++)
    {
        for (int j = 0; j < WIDTH_OF_ROOM; j++)
        {
            if (floor_one[active_room]->get_tiles()[i][j]->get_shape().getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_pos)))
            {

                std::cout << "COLLIDE" << "Rect at central pos (x,y): " << "  (" << floor_one[active_room]->get_tiles()[i][j]->get_center_pos().x << ", " << floor_one[active_room]->get_tiles()[i][j]->get_center_pos().y << ")" << std::endl;
                return true;
            }
            else
            {

                // std::cout << "NOPE";
            }
        }
    }
    return false;
}

// Dungeon loop going through user inputs then allowing everything in the room update and collisions to be detected.
void DungeonFloor::run_dungeon()
{
    spam_how_to_play();
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dungeon");
    floor_one[active_room]->draw_objects(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || complete == true)
            {
                window.close();
            }

            if (check_user_inputs(event) == true)
            {
                player.update();
                floor_one[active_room]->pass_turn();
                if (floor_one[active_room]->can_player_exit() && floor_one[active_room]->has_collided_with_exit())
                {
                    if (active_room == NUM_ROOMS_PER_FLOOR - 1)
                    {
                        std::cout << "Treasure obtained! Dungeon Complete!" << std::endl;
                        complete = true;
                    }
                    else
                    {
                        to_next_room();
                        if (active_room == NUM_ROOMS_PER_FLOOR - 1)
                        {
                            std::cout << "Last room, reach exit to win!" << std::endl;
                        }
                    }
                }
                else if (floor_one[active_room]->has_collided_with_entrance())
                {
                    to_previous_room();
                }
                window.clear();
                floor_one[active_room]->draw_objects(&window);

                if (player.is_alive() == false)
                {
                    std::cout << "Player has died! Game over!" << std::endl;
                    complete = true;
                }
            }
        }
    }
}

// Waits for user input and uses it as a player turn. If the player moves into a wall, they bounce back.
bool DungeonFloor::check_user_inputs(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::W:
            player.move_up();
            if (floor_one[active_room]->has_hit_walls(player.get_body()))
            {
                player.move_down();
            }
            return true;
            break;
        case sf::Keyboard::A:
            player.move_left();
            if (floor_one[active_room]->has_hit_walls(player.get_body()))
            {
                player.move_right();
            }
            return true;
            break;
        case sf::Keyboard::S:
            player.move_down();
            if (floor_one[active_room]->has_hit_walls(player.get_body()))
            {
                player.move_up();
            }
            return true;
            break;
        case sf::Keyboard::D:
            player.move_right();
            if (floor_one[active_room]->has_hit_walls(player.get_body()))
            {
                player.move_left();
            }
            return true;
            break;
        case sf::Keyboard::Space:
            if (player.get_dodge_cooldown() <= 0)
            {
                for (int i = 0; i < player.get_dodge_distance_multiplier(); i++)
                {
                    player.dodge();
                    // reverses movement if dodging into a wall
                    if (floor_one[active_room]->has_hit_walls(player.get_body()))
                    {
                        switch (player.get_rotation())
                        {
                        case RoomObject::up:
                            player.move_down();
                            break;
                        case RoomObject::right:
                            player.move_left();
                            break;
                        case RoomObject::left:
                            player.move_right();
                            break;
                        case RoomObject::down:
                            player.move_up();
                            break;
                        }
                    }
                }
                player.set_dodge_cooldown(player.get_max_dodge_cooldown());
            }
            else
            {
                std::cout << "Dodge is on cooldown for " << player.get_dodge_cooldown() << " turns." << std::endl;
            }
            return true;
            break;
        case sf::Keyboard::O:
            player.attack_close();
            return true;
            break;
        case sf::Keyboard::P:
            player.attack_long();
            return true;
            break;
        case sf::Keyboard::N:
            spam_how_to_play();
            break;
        default:
            break;
        }
    }
    return false;
}

// Unloads current room and loads next one
void DungeonFloor::to_next_room()
{
    if (active_room == NUM_ROOMS_PER_FLOOR)
    {
        complete = true;
    }
    else
    {
        floor_one[active_room]->unload_objects();
        active_room++;
        floor_one[active_room]->load_objects(false);
    }
}

// Unloads current room and loads previous one
void DungeonFloor::to_previous_room()
{
    floor_one[active_room]->unload_objects();
    active_room--;
    floor_one[active_room]->load_objects(true);
}

DungeonFloor::~DungeonFloor()
{
    // Clean up dynamically allocated memory
    for (int i = 0; i < NUM_ROOMS_PER_FLOOR; ++i)
    {
        delete floor_one[i];
        // std::cout << "Deleted Room " << i + 1 << std::endl;
    }
    delete[] floor_one;
    // std::cout << "Deleted Dungeon Floor" << std::endl;
}
