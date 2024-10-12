
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Room.h"

        void Room::load_room(const std::string& filename) {
            std::ifstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Error opening file!" << std::endl;
                return;
            }

            std::string row;
            while (std::getline(file, row)) {
                layout_room.push_back(row);  
            }

            file.close();
        }
    

        Room::Room(const std::string& file_name){
            load_room(file_name);
            tiles_room = new Tile**[LENGTH_OF_ROOM];

            for(int i = 0 ; i < LENGTH_OF_ROOM ; i++){
                tiles_room[i] = new Tile*[WIDTH_OF_ROOM];

                for(int j = 0 ; j < WIDTH_OF_ROOM ; j++){
                    tiles_room[i][j] = new Tile(layout_room[i][j]);
                }

            }
        }
        std::vector<std::string> Room::get_layout_room(){
            return layout_room;
        }

        Tile*** Room::get_tiles(){
            return tiles_room;
        }


        Room::~Room() {
        // Clean up dynamically allocated memory
        for (int i = 0; i < LENGTH_OF_ROOM; ++i) {
            for (int j = 0; j < WIDTH_OF_ROOM; ++j) {
                delete tiles_room[i][j];  // Delete each Tile
            }
            delete[] tiles_room[i];  // Delete the row
        }
        delete[] tiles_room;  // Delete the array of rows


        }