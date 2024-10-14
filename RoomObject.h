#ifndef ROOM_OBJECT_H
#define ROOM_OBJECT_H

#include <SFML/Graphics.hpp>

// General object in room, e.g. walls, exits and entrances.
class RoomObject
{
protected:
    sf::Shape *body;
    sf::Vector2f position;
    bool loaded;

public:
    // Options for shape of Room_object (aside from rectangle, which is addressed in a separate constructor).
    enum ShapeType
    {
        square,
        circle
    };
    // Rotation or direction of an object
    enum Rotation
    {
        right,
        down,
        left,
        up
    };

    RoomObject(ShapeType shape, int size, sf::Color colour, sf::Vector2f position);
    RoomObject(int length, int width, sf::Color colour, sf::Vector2f position);
    RoomObject();
    virtual void draw_object(sf::RenderWindow *display);
    virtual void load_object();
    virtual void unload_object();
    virtual bool has_collided(sf::Shape *body);

    bool is_loaded();
    void set_loaded(bool loaded);
    sf::Vector2f get_position();
    void set_position(sf::Vector2f position);
    sf::Shape *get_body();
    ~RoomObject();
};

#endif