
#include "Room.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "DungeonFloor.h"





        DungeonFloor::DungeonFloor(sf::RenderWindow& window) : window(window) {
            floor_one = new Room*[NUM_ROOMS_PER_FLOOR];

            const std::string file_path_rooms[NUM_ROOMS_PER_FLOOR] = {"floor_layout/1.txt","floor_layout/2.txt", "floor_layout/3.txt", "floor_layout/4.txt", "floor_layout/5.txt"};
            for(int i = 0 ; i < NUM_ROOMS_PER_FLOOR ; i ++){
                floor_one[i] = new Room(file_path_rooms[i]);
            }

            this->active_room = 0;
        
        }

        void DungeonFloor::draw_room(){
    
            for(int i = 0 ; i < LENGTH_OF_ROOM ; i ++){
                for(int j = 0 ; j < WIDTH_OF_ROOM ; j++){
                    
                    Tile* tile_in_loop = floor_one[active_room]->get_tiles()[i][j];

                    tile_in_loop->set_position(j * TILE_SIZE_TO_PIXELS, i * TILE_SIZE_TO_PIXELS);

                    if(tile_in_loop->get_type() == '#'){
                        tile_in_loop->set_fill_colour(sf::Color::Blue);    //wall colour
                    } 
                    else if(tile_in_loop->get_type() == '.'){
                        tile_in_loop->set_fill_colour(sf::Color::White);    //free space colour
                    }
                    else if(tile_in_loop->get_type() == 'E'){
                        tile_in_loop->set_fill_colour(sf::Color::Red); // enemy colour
                    }
                    else if(tile_in_loop->get_type() == 'L'){
                        tile_in_loop->set_fill_colour(sf::Color::Green); // exit colour
                    }
                    else if(tile_in_loop->get_type() == 'C'){
                        tile_in_loop->set_fill_colour(sf::Color::Magenta); // chest colour
                    }
                    else if(tile_in_loop->get_type() == 'P'){
                        tile_in_loop->set_fill_colour(sf::Color::Black); // player colour
                    }
                    window.draw(tile_in_loop->get_shape());
                }

            }
            
        }

    
    int DungeonFloor::get_active_room(){
        return active_room;
    }

    void DungeonFloor::set_active_room(int room_num){
        this-> active_room = room_num;
    }


    bool DungeonFloor::testing_mouse_collision(sf::Vector2i mouse_pos){
            
            for(int i = 0 ; i < LENGTH_OF_ROOM ; i++){
                for(int j = 0 ; j < WIDTH_OF_ROOM; j++){
                    if (floor_one[active_room]->get_tiles()[i][j]->get_shape().getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_pos))){

                        std::cout << "COLLIDE";
                        return true;
                    }    
                    else{

                        //std::cout << "NOPE";
                    }
                }
            }
            return false;
        }

    DungeonFloor::~DungeonFloor() {
            // Clean up dynamically allocated memory
            for (int i = 0; i < NUM_ROOMS_PER_FLOOR; ++i) {
                delete floor_one[i];
            }
            delete[] floor_one;
        }


