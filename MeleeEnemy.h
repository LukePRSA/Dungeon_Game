#ifndef MELEE_ENEMY_H
#define MELEE_ENEMY_H

#include "Enemy.h"
#include "Projectile.h"

// Represents an enemy that approaches the player when in range and attacks them if close enough.
class MeleeEnemy : public Enemy
{
protected:
    Projectile melee_attack{0, 1, 60, 160, sf::Color(255, 60, 60)};
    int movement_speed = 58;
    Rotation rotation = right;
    void approach_player(sf::Vector2f player_distance_vector);
    void attack();

public:
    MeleeEnemy(int level, int max_cooldown, int max_range, sf::Vector2f position);
    MeleeEnemy();
    void perform_ai(sf::Vector2f player_position);
    void update_attacks();
    bool has_hit(sf::Shape *body);

    void load_object();
    void unload_object();
    void draw_object(sf::RenderWindow *display);

    Projectile *get_melee_attack();
    int get_movement_speed();
    void set_movement_speed(int speed);
    Rotation get_rotation();
    void set_rotation(Rotation rotation);
};

#endif