
#include "Room.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "DungeonFloor.h"

DungeonFloor::DungeonFloor() : active_room(0), player(TILE_SIZE_TO_PIXELS)
{

    floor_one = new Room *[NUM_ROOMS_PER_FLOOR];

    const std::string file_path_rooms[NUM_ROOMS_PER_FLOOR] = {"floor_layout/1.txt", "floor_layout/2.txt", "floor_layout/3.txt", "floor_layout/4.txt", "floor_layout/5.txt"};
    for (int i = 0; i < NUM_ROOMS_PER_FLOOR; i++)
    {
        floor_one[i] = new Room(file_path_rooms[i], &player);
    }
    floor_one[active_room]->load_objects(false);
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
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || complete == true)
            {
                window.close();
            }
            floor_one[active_room]->draw_objects(&window);
            check_user_inputs(event, &window);
            player.update();
            floor_one[active_room]->pass_turn();
            if (floor_one[active_room]->can_player_exit() && floor_one[active_room]->has_collided_with_exit())
            {
                to_next_room();
                if (active_room == NUM_ROOMS_PER_FLOOR)
                {
                    std::cout << "Last room, reach exit to win!" << std::endl;
                }
            }
            else if (floor_one[active_room]->has_collided_with_entrance())
            {
                to_previous_room();
            }
        }
    }
}

// Waits for user input and uses it as a player turn. If the player moves into a wall, they bounce back.
void DungeonFloor::check_user_inputs(sf::Event event, sf::RenderWindow *window)
{
    bool has_user_pressed_key = false;
    while (has_user_pressed_key == false)
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
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
                has_user_pressed_key = true;
                break;
            case sf::Keyboard::A:
                player.move_left();
                if (floor_one[active_room]->has_hit_walls(player.get_body()))
                {
                    player.move_right();
                    std::cout << "A" << std::endl;
                }
                has_user_pressed_key = true;
                break;
            case sf::Keyboard::S:
                player.move_down();
                if (floor_one[active_room]->has_hit_walls(player.get_body()))
                {
                    player.move_up();
                }
                has_user_pressed_key = true;
                break;
            case sf::Keyboard::D:
                player.move_right();
                if (floor_one[active_room]->has_hit_walls(player.get_body()))
                {
                    player.move_left();
                }
                has_user_pressed_key = true;
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
                    has_user_pressed_key = true;
                }
                break;
            case sf::Keyboard::O:
                player.attack_close();
                has_user_pressed_key = true;
                break;
            case sf::Keyboard::P:
                player.attack_long();
                has_user_pressed_key = true;
                break;
            default:
                break;
            }
        }
    }
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
    }
    delete[] floor_one;
}
