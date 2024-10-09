#ifndef ENTITY_H
#define ENTITY_H

#include "Room_object.h"

class Entity : public Room_object
{
    // general killable entity with hp and level in a room, e.g. a breakable wall, and used for later classes
protected:
    int level;
    int xp;
    int max_hp; // max hp is 5 * level
    int hp;
    bool alive = true;

public:
    Entity(int level, int xp, Shape shape, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position);
    Entity(int level, int xp, int length, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position);
    Entity();
    void take_damage(int damage);
    void heal_hp(int hp_healed);
    virtual void kill_entity();
    std::string save_object(); // add later
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