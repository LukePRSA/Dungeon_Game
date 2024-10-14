#include "Entity.h"

// Creates circle/square entity.
Entity::Entity(int level, int xp, int max_hp, ShapeType shape, int width, sf::Color colour, sf::Vector2f position) : RoomObject(shape, width, colour, position), level(level), xp(xp), max_hp(max_hp), hp(max_hp) {}

// Creates rectangular entity.
Entity::Entity(int level, int xp, int max_hp, int length, int width, sf::Color colour, sf::Vector2f position) : RoomObject(length, width, colour, position), level(level), xp(xp), max_hp(max_hp), hp(max_hp) {}

// Creates entity with default RoomObject (0-width circle).
Entity::Entity() : RoomObject(), level(0), xp(0), max_hp(0), hp(0), alive(false) {}

// Reduces Entity's hp if it is alive, and kills it if its hp drops below zero.
void Entity::take_damage(int damage)
{
    if (alive)
    {
        hp -= damage;
        if (hp <= 0)
        {
            kill_entity();
        }
    }
}

// Increases Entity's hp if it is alive and under max_hp.
void Entity::heal_hp(int hp_healed)
{
    if (alive && hp < max_hp)
    {
        hp += hp_healed;
        if (hp > max_hp)
        {
            hp = max_hp;
        }
    }
}

// Moves entity off-screen, sets hp to 0 and sets alive to false.
void Entity::kill_entity()
{
    hp = 0;
    alive = false;
    RoomObject::set_position(sf::Vector2f(-1, -1));
}

int Entity::get_level() { return level; }

void Entity::set_level(int level) { this->level = level; }

int Entity::get_xp() { return xp; }

void Entity::set_xp(int xp) { this->xp = xp; }

int Entity::get_max_hp() { return max_hp; }

void Entity::set_max_hp(int max_hp) { this->max_hp = max_hp; }

int Entity::get_hp() { return hp; }

void Entity::set_hp(int hp) { this->hp = hp; }

bool Entity::is_alive() { return alive; }

void Entity::set_alive(bool alive) { this->alive = alive; }