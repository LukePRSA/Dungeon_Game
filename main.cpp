
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "DungeonFloor.h"
#include "Room.h"
#include "Tile.h"

const int TILE_SIZE_TO_PIXELS = 58;
const int NUM_ROOMS_PER_FLOOR = 5;
const int LENGTH_OF_ROOM = 10;
const int WIDTH_OF_ROOM =  14;








int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template");
    DungeonFloor dungeon_floor(window);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::W){
                    std::cout << "next room" << std::endl;
                    if(dungeon_floor.get_active_room() + 1 < 5){
                        dungeon_floor.set_active_room(dungeon_floor.get_active_room() + 1);
                    }
                    else{
                        dungeon_floor.set_active_room(0);
                    }
                }
            }
        }


        window.clear();

        
    
        dungeon_floor.draw_room();

        //testing
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window); // mouse pos for testing.
        dungeon_floor.testing_mouse_collision(mouse_pos);
        std::cout << "Currently on floor: " << dungeon_floor.get_active_room() + 1<< std::endl;


        window.display();
    }



    return 0;
}
