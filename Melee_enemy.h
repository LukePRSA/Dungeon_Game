#ifndef MELEE_ENEMY_H
#define MELEE_ENEMY_H

#include "Enemy.h"
#include "Projectile.h"

class Melee_enemy : public Enemy
{
    // represents an enemy that approaches the player when in range and attacks them if close enough
private:
    Projectile melee_attack{0, 1, 60, 160, sf::Vector3<short unsigned int>(255, 60, 60)};
    int movement_speed;
    Rotation rotation = right;
    void approach_player(sf::Vector2f player_distance_vector);
    void attack();

public:
    Melee_enemy(int level, int xp);
    Melee_enemy();
    void perform_ai(sf::Vector2f player_position);
    void update_attacks();

    bool has_collided(sf::Shape *body);
    void load_object();
    void unload_object();

    Projectile *get_melee_attack();
    int get_movement_speed();
    void set_movement_speed(int speed);
    Rotation get_rotation();
    void set_rotation(Rotation rotation);
};

#endif