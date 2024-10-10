
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>


const int TILE_SIZE_TO_PIXELS = 100;



class Room{
    private:
        std::vector<std::string> layout_room;
        sf::RenderWindow& window;

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
        Room(const std::string& file_name, sf::RenderWindow& window) : window(window){
            load_room(file_name);
        }
        std::vector<std::string> get_layout_room(){
            return layout_room;
        }

        void draw_room(){
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS));

            for(size_t i = 0 ; i < layout_room.size(); i ++){
                for(size_t j = 0 ; j < layout_room[i].size(); j++){
                    sf::RectangleShape tile(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS));
                    tile.setPosition(j * TILE_SIZE_TO_PIXELS, i * TILE_SIZE_TO_PIXELS);

                    if(layout_room[i][j] == '#'){
                        tile.setFillColor(sf::Color::Blue);    //wall colour
                    } 
                    else if(layout_room[i][j] == '.'){
                        tile.setFillColor(sf::Color::White);    //free space colour
                    }
                    window.draw(tile);
                }

            }
        }

};






int main(){
    const std::string file_path_floor_layout = "floor_layout.txt";
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template");
    Room room = Room(file_path_floor_layout, window);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        

        room.draw_room();

        window.display();
    }



    return 0;
}