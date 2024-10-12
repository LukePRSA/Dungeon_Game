#ifndef STRIKER_TARGET_H
#define STRIKER_TARGET_H

#include "RoomObject.h"

// Represents a warning target for the StrikerEnemy class.
class StrikerTarget : public RoomObject
{
private:
    bool active = false;
    bool deal_damage = false;
    int attack_countdown;

public:
    StrikerTarget();
    void place_target(sf::Vector2f position);
    void update_target();
    void remove_target();

    bool is_active();
    void set_active(bool active);
    bool can_deal_damage();
    void set_deal_damage(bool deal_damage);
    int get_attack_countdown();
    void set_attack_countdown(int attack_countdown);
};

#endif