#include "HealthConsumable.h"

// Creates a green health consumable with variable size based on health_bonus_percentage at the given position.
HealthConsumable::HealthConsumable(int health_bonus_percentage, sf::Vector2f position) : RoomObject(circle, (float)58 * ((float)health_bonus_percentage / (float)100), sf::Color(0, 255, 0), position), health_bonus_percentage(health_bonus_percentage) {}

// Creates a health consumable that heals nothing and is off-screen.
HealthConsumable::HealthConsumable() : HealthConsumable(0, sf::Vector2f(-100, -100)) {}

// Returns true and destroys consumable if it has collided with the body and active.
bool HealthConsumable::has_collided(sf::Shape *body)
{
    if (active && RoomObject::has_collided(body))
    {
        destroy_consumable();
        return true;
    }
    return false;
}

// Darkens consumable and deactivates it.
void HealthConsumable::destroy_consumable()
{
    body->setFillColor(sf::Color(25, 25, 25));
    active = false;
}

// Returns body if loaded and alive.
std::vector<sf::Shape *> HealthConsumable::get_draw_objects()
{
    std::vector<sf::Shape *> drawable_objects;
    if (loaded && active)
    {
        drawable_objects.push_back(body);
    }
    return drawable_objects;
}

int HealthConsumable::get_health_bonus_percentage() { return health_bonus_percentage; }

void HealthConsumable::set_health_bonus_percentage(int percentage) { health_bonus_percentage = percentage; }

bool HealthConsumable::is_active() { return active; }

void HealthConsumable::set_active(bool active) { this->active = active; }