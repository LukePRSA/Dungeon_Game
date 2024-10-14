#include "Enemy.h"

// Creates a circular/square enemy with given parameters.
Enemy::Enemy(int damage, int max_cooldown, int max_range, int level, int xp, int hp, ShapeType shape, int width, sf::Color colour, sf::Vector2f position): Entity(level, xp, hp, shape, width, colour, position), damage(damage), max_cooldown(max_cooldown) {}

// Creates a default 0-width circle enemy.
Enemy::Enemy(): Entity(), damage(0), max_cooldown(0), max_range(0) {}

// Finds vector displacement of given position from enemy.
sf::Vector2f Enemy::find_distance_vector(sf::Vector2f position)
{
    return (position - this->position);
}

// Finds scalar distance of enemy from position.
float Enemy::find_distance(sf::Vector2f position)
{
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