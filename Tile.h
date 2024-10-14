
#ifndef TILE_H
#define TILE_H


#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

extern const int TILE_SIZE_TO_PIXELS;
extern const int NUM_ROOMS_PER_FLOOR;
extern const int LENGTH_OF_ROOM;
extern const int WIDTH_OF_ROOM;

class Tile{
    private:
        char tile_type;
        sf::RectangleShape tile_rect;

    public:
        Tile(char val_at_pos);

        void set_position(float x, float y);
        void set_fill_colour(sf::Color color);
        const sf::RectangleShape& get_shape() const;

        char get_type() const;
        sf::Vector2f get_center_pos();
};


#endif