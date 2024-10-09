#include "Entity.h"

Entity::Entity(int level, int xp, Shape shape, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position) : level(level), xp(xp), hp(5 * level), max_hp(5 * level), Room_object(shape, width, colour, position) {}

Entity::Entity(int level, int xp, int length, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position) : level(level), xp(xp), hp(5 * level), max_hp(5 * level), Room_object(length, width, colour, position) {}

Entity::Entity() : level(0), xp(0), hp(0), max_hp(0), Room_object() {}

void Entity::take_damage(int damage)
{
    // reduces Entity's hp if it is alive, and kills it if its hp drops below zero
    if (alive)
    {
        hp -= damage;
        if (hp <= 0)
        {
            kill_entity();
        }
    }
}
void Entity::heal_hp(int hp_healed)
{
    // increases Entity's hp if it is alive and under max_hp
    if (alive && hp < max_hp)
    {
        hp += hp_healed;
        if (hp > max_hp)
        {
            hp = max_hp;
        }
    }
}

void Entity::kill_entity()
{
    // moves entity off-screen, sets hp to 0 and sets alive to false
    hp = 0;
    alive = false;
    position = sf::Vector2f(-1, -1);
    body->setPosition(sf::Vector2f(-1, -1));
}

std::string Entity::save_object() {}

int Entity::get_level() { return level; }

void Entity::set_level(int level)
{
    // sets level to given level and updates xp
    this->level = level; 
    max_hp = level * 5;
}

int Entity::get_xp() { return xp; }

void Entity::set_xp(int xp) { this->xp = xp; }

int Entity::get_max_hp() { return max_hp; }

void Entity::set_max_hp(int max_hp) { this->max_hp = max_hp; }

int Entity::get_hp() { return hp; }

void Entity::set_hp(int hp) { this->hp = hp; }

bool Entity::is_alive() { return alive; }

void Entity::set_alive(bool alive) { this->alive = alive; }