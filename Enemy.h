#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <cmath>

class Enemy : public Entity
{
    // abstract class representing an enemy in a room
protected:
    int damage;
    int max_cooldown;
    int attack_cooldown = 0;
    int max_range;

public:
    Enemy(int damage, int max_cooldown, int max_range, int level, int xp, Shape shape, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position);
    Enemy();
    virtual void perform_ai(sf::Vector2f player_position) = 0;
    virtual void update_attacks() = 0;
    sf::Vector2f find_distance_vector(sf::Vector2f position);
    float find_distance(sf::Vector2f position);

    int get_damage();
    void set_damage(int damage);
    int get_max_cooldown();
    void set_max_cooldown(int cooldown);
    int get_attack_cooldown();
    void set_attack_cooldown(int cooldown);
    int get_max_range();
    void set_max_range(int range);
};

#endif