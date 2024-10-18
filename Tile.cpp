#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Tile.h"

Tile::Tile(char val_at_pos)
{
    this->tile_type = val_at_pos;
    tile_rect.setSize(sf::Vector2f(TILE_SIZE_TO_PIXELS, TILE_SIZE_TO_PIXELS)); // Set to the desired tile size
    // std::cout << val_at_pos << std::endl;
}

void Tile::set_position(float x, float y)
{
    tile_rect.setPosition(x, y);
    // std::cout << tile_rect.getPosition().x << "," << tile_rect.getPosition().y << std::endl;
}

void Tile::set_fill_colour(sf::Color color)
{
    tile_rect.setFillColor(color);
}
const sf::RectangleShape &Tile::get_shape() const
{
    return tile_rect;
}

char Tile::get_type() const
{
    return tile_type;
}

sf::Vector2f Tile::get_center_pos()
{
    sf::Vector2f size = tile_rect.getSize();
    sf::Vector2f pos = tile_rect.getPosition();

    sf::Vector2f center_of_rect(pos.x + size.x / 2, pos.y + size.y / 2);
    return center_of_rect;
}
