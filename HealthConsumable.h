#ifndef HEALTH_CONSUMABLE_H
#define HEALTH_CONSUMABLE_H

#include "RoomObject.h"

// Represents a health consumable that restores a percentage of the player's health upon usage.
class HealthConsumable : public RoomObject
{
private:
    int health_bonus_percentage;
    bool active = true;

public:
    HealthConsumable(int health_bonus, sf::Vector2f position);
    HealthConsumable();
    bool has_collided(sf::Shape *body);
    void destroy_consumable();

    int get_health_bonus_percentage();
    void set_health_bonus_percentage(int percentage);
    bool is_active();
    bool set_active(bool active);
};

#endif