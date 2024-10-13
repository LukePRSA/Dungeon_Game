#include "HealthConsumable.h"

// Creates a green health consumable at the given position.
HealthConsumable::HealthConsumable(int health_bonus, sf::Vector2f position): health_bonus_percentage(health_bonus), RoomObject(circle, 58*(health_bonus/100), sf::Color(0,255,0), position) {}

// Creates a health consumable that heals nothing and is off-screen.
HealthConsumable::HealthConsumable(): HealthConsumable(0, sf::Vector2f(-1, -1)) {}

// Returns true and destroys consumable if true.
bool HealthConsumable::has_collided(sf::Shape *body)
{
    if (RoomObject::has_collided(body))
    {
        destroy_consumable();
        return true;
    }
    return false;
}

// Darkens consumable and deactivates it.
void HealthConsumable::destroy_consumable()
{
    body->setFillColor(sf::Color(25,25,25));
    active = false;
}

int HealthConsumable::get_health_bonus_percentage() { return health_bonus_percentage; }

void HealthConsumable::set_health_bonus_percentage(int percentage) { health_bonus_percentage = percentage; }

bool HealthConsumable::is_active() { return active; }

bool HealthConsumable::set_active(bool active) { this->active = active; }