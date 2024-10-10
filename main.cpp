
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

        void set_position(float x, float y) {
            tile_rect.setPosition(x, y);
        }

        void set_fill_colour(sf::Color color) {
            tile_rect.setFillColor(color);
        }
        const sf::RectangleShape& get_shape() const {
            return tile_rect;
        }

        char get_type() const {
            return tile_type;
        }

};
class Room{
    private:
        std::vector<std::string> layout_room;
        Tile ***tiles_room;

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
            tiles_room = new Tile**[LENGTH_OF_ROOM];

            for(int i = 0 ; i < LENGTH_OF_ROOM ; i++){
                tiles_room[i] = new Tile*[WIDTH_OF_ROOM];

                for(int j = 0 ; j < WIDTH_OF_ROOM ; j++){
                    tiles_room[i][j] = new Tile(layout_room[i][j]);
                }

            }
        }
        std::vector<std::string> get_layout_room(){
            return layout_room;
        }

        Tile*** get_tiles(){
            return tiles_room;
        }


        ~Room() {
        // Clean up dynamically allocated memory
        for (int i = 0; i < LENGTH_OF_ROOM; ++i) {
            for (int j = 0; j < WIDTH_OF_ROOM; ++j) {
                delete tiles_room[i][j];  // Delete each Tile
            }
            delete[] tiles_room[i];  // Delete the row
        }
        delete[] tiles_room;  // Delete the array of rows


        }
};

class DungeonFloor{
    private:
        Room **floor_one;
        sf::RenderWindow& window;
        int active_room;

    public:
        DungeonFloor(sf::RenderWindow& window) : window(window) {
            floor_one = new Room*[NUM_ROOMS_PER_FLOOR];

            const std::string file_path_rooms[NUM_ROOMS_PER_FLOOR] = {"floor_layout/1.txt","floor_layout/2.txt", "floor_layout/3.txt", "floor_layout/4.txt", "floor_layout/5.txt"};
            for(int i = 0 ; i < NUM_ROOMS_PER_FLOOR ; i ++){
                floor_one[i] = new Room(file_path_rooms[i]);
            }

            this->active_room = 0;
        
        }

        void draw_room(){
    
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
                    window.draw(tile_in_loop->get_shape());
                }

            }
            
        }

    
    int get_active_room(){
        return active_room;
    }

    void set_active_room(int room_num){
        this-> active_room = room_num;
    }


    bool testing_mouse_collision(sf::Vector2i mouse_pos){
            
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

        
    
        dungeon_floor.draw_room();

        //testing
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window); // mouse pos for testing.
        dungeon_floor.testing_mouse_collision(mouse_pos);



        window.display();
    }



    return 0;
}
