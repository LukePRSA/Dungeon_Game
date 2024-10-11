#include "Enemy.h"

Enemy::Enemy(int damage, int max_cooldown, int max_range, int level, int xp, Shape shape, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position): damage(damage), max_cooldown(max_cooldown), Entity(level, xp, shape, width, colour, position) {}

Enemy::Enemy(): damage(0), max_cooldown(0), max_range(0), Entity() {}

sf::Vector2f Enemy::find_distance_vector(sf::Vector2f position)
{
    // finds distance of given position from enemy in vector form
    return position - this->position;
}

float Enemy::find_distance(sf::Vector2f position)
{
    // finds scalar distance of enemy from position
    sf::Vector2f distance_vector = find_distance_vector(position);
    return sqrt(pow(distance_vector.x, 2) + pow(distance_vector.y, 2));
}

int Enemy::get_damage() { return damage; }

void Enemy::set_damage(int damage) { this->damage = damage; }

int Enemy::get_max_cooldown() { return max_cooldown; }

void Enemy::set_max_cooldown(int cooldown) { max_cooldown = cooldown; }

int Enemy::get_attack_cooldown() { return attack_cooldown; }

void Enemy::set_attack_cooldown(int cooldown) { attack_cooldown = cooldown; }

int Enemy::get_max_range() { return max_range; }

void Enemy::set_max_range(int range) { max_range = range; }