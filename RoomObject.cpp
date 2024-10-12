#include "RoomObject.h"

// Creates the body as a square or circle, based on chosen Shape.
RoomObject::RoomObject(Shape shape, int width, sf::Color colour, sf::Vector2f position) : position(position)
{
    if (shape == square)
    {
        body = new sf::RectangleShape(sf::Vector2f(width, width));
    }
    if (shape == circle)
    {
        body = new sf::CircleShape(width / 2);
    }

    body->setFillColor(sf::Color(colour));
    body->setOrigin(sf::Vector2f(width / 2, width / 2));
    unload_object();
}

// Creates a rectangle with given parameters.
RoomObject::RoomObject(int length, int width, sf::Color colour, sf::Vector2f position) : position(position)
{
    body = new sf::RectangleShape(sf::Vector2f(length, width));
    body->setFillColor(sf::Color(colour));
    body->setOrigin(sf::Vector2f(length / 2, width / 2));
    unload_object();
}

// Creates a 0-width white square.
RoomObject::RoomObject() : RoomObject(square, 0, sf::Color(255, 255, 255), sf::Vector2f(0, 0)) {}

// Draws object on given display.
void RoomObject::draw_object(sf::RenderWindow *display)
{
    display->draw(*body);
}

// Loads the object at its given position.
void RoomObject::load_object()
{
    body->setPosition(position);
    loaded = true;
}

// Unloads the object by moving it offscreen.
void RoomObject::unload_object()
{
    body->setPosition(sf::Vector2f(-1, -1));
    loaded = false;
}

// Returns true if the object has collided with the given body.
bool RoomObject::has_collided(sf::Shape *body)
{
    if (loaded)
    {
        bool collided = this->body->getGlobalBounds().intersects(body->getGlobalBounds());
        return collided;
    }
    return false;
}

bool RoomObject::is_loaded() { return loaded; }

void RoomObject::set_loaded(bool loaded) { this->loaded = loaded; }

sf::Vector2f RoomObject::get_position() { return position; }

// Changes position of object. If loaded, it will also change its position on the display.
void RoomObject::set_position(sf::Vector2f position)
{
    this->position = position;
    if (loaded)
    {
        body->setPosition(position);
    }
}

sf::Shape *RoomObject::get_body() { return body; }

RoomObject::~RoomObject()
{
    delete body;
}