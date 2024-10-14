#ifndef ENTITY_H
#define ENTITY_H

#include "RoomObject.h"

// Killable entity with hp and level.
class Entity : public RoomObject
{
protected:
    int level;
    int xp;
    int max_hp;
    int hp;
    bool alive = true;

public:
    Entity(int level, int xp, int max_hp, ShapeType shape, int width, sf::Color colour, sf::Vector2f position);
    Entity(int level, int xp, int max_hp, int length, int width, sf::Color colour, sf::Vector2f position);
    Entity();
    void take_damage(int damage);
    void heal_hp(int hp_healed);
    virtual void kill_entity();

    int get_level();
    void set_level(int level);
    int get_xp();
    void set_xp(int xp);
    int get_max_hp();
    void set_max_hp(int max_hp);
    int get_hp();
    void set_hp(int hp);
    bool is_alive();
    void set_alive(bool alive);
};

#endif