
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>


const int TILE_SIZE_TO_PIXELS = 58;
const int NUM_ROOMS_PER_FLOOR = 1;


class Room{
    private:
        std::vector<std::string> layout_room;

        void load_room(const std::string& filename) {
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
    

    public:
        Room(const std::string& file_name){
            load_room(file_name);
        }
        std::vector<std::string> get_layout_room(){
            return layout_room;
        }



};

class DungeonFloor{
    private:
        Room **arr_of_rooms;
        sf::RenderWindow& window;
    public:
        DungeonFloor(Room** arr_of_rooms, sf::RenderWindow& window) : arr_of_rooms(arr_of_rooms), window(window) {}

        void draw_room_by_num(int room_num){
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS));
    
            for(size_t i = 0 ; i < arr_of_rooms[room_num]->get_layout_room().size(); i ++){
                for(size_t j = 0 ; j < arr_of_rooms[room_num]->get_layout_room()[i].size(); j++){
                    sf::RectangleShape tile(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS));
                    tile.setPosition(j * TILE_SIZE_TO_PIXELS, i * TILE_SIZE_TO_PIXELS);

                    if(arr_of_rooms[room_num]->get_layout_room()[i][j] == '#'){
                        tile.setFillColor(sf::Color::Blue);    //wall colour
                    } 
                    else if(arr_of_rooms[room_num]->get_layout_room()[i][j] == '.'){
                        tile.setFillColor(sf::Color::White);    //free space colour
                    }
                    window.draw(tile);
                }

            }
        }

};





int main(){
    const std::string file_path_floor_layout = "/home/lukeprsa/Dungeon_game/Dungeon_Game/floor_layout/1.txt";
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template");
    Room** arr_of_rooms = new Room*[NUM_ROOMS_PER_FLOOR];

    arr_of_rooms[0] = new Room(file_path_floor_layout);

    DungeonFloor dungeon_floor(arr_of_rooms, window);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        
    
        dungeon_floor.draw_room_by_num(0);

        window.display();
    }



    return 0;
}