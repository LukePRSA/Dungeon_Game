#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Tile.h"



        Tile::Tile(char val_at_pos){
            this->tile_type = val_at_pos;
            tile_rect.setSize(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS));  // Set to the desired tile size
        };

        void Tile::set_position(float x, float y) {
            tile_rect.setPosition(x, y);
        }

        void Tile::set_fill_colour(sf::Color color) {
            tile_rect.setFillColor(color);
        }
        const sf::RectangleShape& Tile::get_shape() const {
            return tile_rect;
        }

        char Tile::get_type() const {
            return tile_type;
        }
