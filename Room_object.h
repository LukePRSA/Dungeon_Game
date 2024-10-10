#ifndef ROOM_OBJECT_H
#define ROOM_OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Enums.h"

class Room_object
{
    // general object in room, e.g. walls, exits and entrances
protected:
    sf::Shape *body;
    sf::Vector2f position;
    bool loaded;

public:
    Room_object(Shape shape, int size, sf::Vector3<short unsigned int> colour, sf::Vector2f position);
    Room_object(int length, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position);
    Room_object();
    virtual void draw_object(sf::RenderWindow *display);
    virtual void load_object();
    virtual void unload_object();
    virtual bool has_collided(sf::Shape *body);

    bool is_loaded();
    void set_loaded(bool loaded);
    sf::Vector2f get_position();
    void set_position(sf::Vector2f position);
    sf::Shape *get_body();
    void change_body_colour(sf::Vector3i colour);
    ~Room_object();
};

#endif