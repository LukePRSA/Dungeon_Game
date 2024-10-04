#ifndef ROOM_OBJECT_H
#define ROOM_OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class Room_object
{
    // general object in room, e.g. walls, exits and entrances
protected:
    sf::Shape *body;
    sf::Vector2f position;
    bool loaded;

public:
    Room_object(std::string shape, int size, sf::Vector3<short unsigned int> colour, sf::Vector2f position);
    Room_object(int length, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position);
    Room_object();
    virtual void draw_object(sf::RenderWindow display);
    virtual void load_object();
    virtual void unload_object();
    bool is_loaded();
    std::string save_object(); // add later
    virtual bool has_collided(sf::Shape *body);
    sf::Vector2f get_position();
    void set_position(sf::Vector2f position);
    sf::Shape* get_body();
    void change_body_colour(sf::Vector3i colour);
};

#endif