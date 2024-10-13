#ifndef TRAP_H
#define TRAP_H

#include "RoomObject.h"

// Abstract class representing a trap that triggers passively over time.
class Trap : public RoomObject
{
protected:
    int level;
    int damage;
    int max_cooldown;
    int cooldown = 0;
    bool active = true;


public:
    Trap(int level, int damage, int max_cooldown, ShapeType shape, int width, sf::Color colour, sf::Vector2f position);
    Trap();
    virtual void update_trap() = 0;
    virtual bool is_triggered(sf::Shape *body) = 0;
    virtual void toggle_active() = 0;

    int get_level();
    void set_level(int level);
    int get_damage();
    void set_damage(int damage);
    int get_max_cooldown();
    void set_max_cooldown(int cooldown);
    int get_cooldown();
    void set_cooldown(int cooldown);
    bool is_active();
    void set_active(bool active);
};

#endif