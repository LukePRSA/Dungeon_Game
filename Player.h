#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Projectile.h"

class Player : public Entity
{
    // represents the player in the game, controllable by user input
private:
    int melee_damage;
    int ranged_damage;
    Rotation rotation;
    Projectile melee_attack;
    Projectile ranged_projectiles[3];
    int max_projectile_cooldown = 10;
    int projectile_cooldowns[3] = {0};
    int max_dodge_cooldown = 3;
    int dodge_cooldown = 0;
    int movement_speed;

public:
    Player(int level, int xp, int movement_speed);
    Player();
    void move_right();
    void move_down();
    void move_left();
    void move_up();
    void dodge();
    void gain_xp(int xp);
    void attack_close();
    void attack_long();
    bool has_melee_attack_hit(Shape *body);
    bool has_ranged_projectile_hit(Shape *body);
    void update();
    void despawn_projectiles();

    void draw_object(sf::RenderWindow *display);

    int get_melee_damage();
    void set_melee_damage(int damage);
    int get_ranged_damage();
    void set_ranged_damage(int damage);
    Rotation get_rotation();
    void set_Rotation(Rotation rotation);
    Projectile *get_melee_attack();
    Projectile *get_ranged_projectiles();
    int get_max_projectile_cooldown();
    void set_max_projectile_cooldown(int cooldown);
    int get_projectile_cooldown(int index);
    void set_projectile_cooldown(int index, int cooldown);
    int get_max_dodge_cooldown();
    void set_max_dodge_cooldown(int cooldown);
    int get_dodge_cooldown();
    void set_dodge_cooldown(int cooldown);
    int get_movement_speed();
    void set_movement_speed(int speed);
};

#endif