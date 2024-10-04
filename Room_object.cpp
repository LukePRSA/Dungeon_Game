#include "Room_object.h"

Room_object::Room_object(std::string shape, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position): position(position)
{
    // creates body as a square or circle, based on option
    if (shape == "square")
    {
        body = new sf::RectangleShape(sf::Vector2f(width, width));
    }
    if (shape == "circle")
    {
        body = new sf::CircleShape(width/2);
    }

    body->setFillColor(sf::Color(colour.x, colour.y, colour.z));
    body->setOrigin(sf::Vector2f(width/2, width/2));
    unload_object();
}

Room_object::Room_object(int length, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position): position(position)
{
    // used for creating rectangular objects
    body = new sf::RectangleShape(sf::Vector2f(length,width));
    body->setFillColor(sf::Color(colour.x, colour.y, colour.z));
    body->setOrigin(sf::Vector2f(width/2, width/2));
    unload_object();
}

Room_object::Room_object(): Room_object("square", 0, sf::Vector3<short unsigned int>(255, 255, 255), sf::Vector2f(0,0)) {}

void Room_object::draw_object(sf::RenderWindow display)
{
    display.draw(*body);
}

void Room_object::load_object()
{
    // loads the Room_object in the current room
    body->setPosition(position);
    loaded = true;
}

void Room_object::unload_object()
{
    // moves the Room_object off-screen
    body->setPosition(sf::Vector2f(-1,-1));
    loaded = false;
}

bool Room_object::is_loaded() { return loaded;}

std::string Room_object::save_object() {}

bool Room_object::has_collided(sf::Shape *body)
{
    // returns true if Room_object has collided with the given body
    if (loaded)
    {
    this->body->getGlobalBounds().intersects(body->getGlobalBounds());
    }
}

sf::Vector2f Room_object::get_position() { return position;}

void Room_object::set_position(sf::Vector2f position)
{
    this->position = position;
}

sf::Shape* Room_object::get_body() { return body;}

void Room_object::change_body_colour(sf::Vector3i colour)
{
    body->setFillColor(sf::Color(colour.x, colour.y, colour.z));
}