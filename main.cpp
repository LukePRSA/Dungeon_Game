
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>


const int TILE_SIZE_TO_PIXELS = 58;
const int NUM_ROOMS_PER_FLOOR = 5;
const int LENGTH_OF_ROOM = 10;
const int WIDTH_OF_ROOM =  14;

class Tile{
    private:
        char tile_type;
        sf::RectangleShape tile_rect;

    public:
        Tile(char val_at_pos){
            this->tile_type = val_at_pos;
            tile_rect.setSize(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS));  // Set to the desired tile size
        };


};
class Room{
    private:
        std::vector<std::string> layout_room;
        std::vector<Tile> tiles_room;

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

            for(int i = 0 ; i < LENGTH_OF_ROOM ; i++){
                for(int j = 0 ; i < WIDTH_OF_ROOM ; j++){
                    tiles_room.push_back(Tile(layout_room[i][j]));  
                }

            }
        }
        std::vector<std::string> get_layout_room(){
            return layout_room;
        }

        std::vector<Tile> get_tiles(){
            return tiles_room;
        }



};

class DungeonFloor{
    private:
        Room **floor_one;
        sf::RenderWindow& window;
    public:
        DungeonFloor(sf::RenderWindow& window) : window(window) {
            floor_one = new Room*[NUM_ROOMS_PER_FLOOR];

            const std::string file_path_rooms[NUM_ROOMS_PER_FLOOR + 1] = {"floor_layout/1.txt","floor_layout/2.txt", "floor_layout/3.txt", "floor_layout/4.txt", "floor_layout/5.txt"};
            for(int i = 0 ; i < NUM_ROOMS_PER_FLOOR ; i ++){
                floor_one[i] = new Room(file_path_rooms[i]);
            }
        
        }

        void draw_room_by_num(int room_num){
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS));
    
            for(size_t i = 0 ; i < floor_one[room_num]->get_layout_room().size(); i ++){
                for(size_t j = 0 ; j < floor_one[room_num]->get_layout_room()[i].size(); j++){
                    sf::RectangleShape tile(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS));
                    tile.setPosition(j * TILE_SIZE_TO_PIXELS, i * TILE_SIZE_TO_PIXELS);

                    if(floor_one[room_num]->get_layout_room()[i][j] == '#'){
                        tile.setFillColor(sf::Color::Blue);    //wall colour
                    } 
                    else if(floor_one[room_num]->get_layout_room()[i][j] == '.'){
                        tile.setFillColor(sf::Color::White);    //free space colour
                    }
                    window.draw(tile);
                }

            }
        }
    ~DungeonFloor() {
            // Clean up dynamically allocated memory
            for (int i = 0; i < NUM_ROOMS_PER_FLOOR; ++i) {
                delete floor_one[i];
            }
            delete[] floor_one;
        }

};





int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template");
    DungeonFloor dungeon_floor(window);


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
