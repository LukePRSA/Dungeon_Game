#ifndef BASIC_BOSS_H
#define BASIC_BOSS_H

#include <stdlib.h>
#include<time.h>
#include "Enemy.h"
#include "Projectile.h"
#include "MeleeEnemy.h"

// Represents a powerful boss enemy that has melee and ranged attacks and minions.
class BasicBoss : public MeleeEnemy
{
private:
    Projectile ranged_attacks[2];
    MeleeEnemy **minions;
    int num_minions;
    int base_damage;
    void launch_projectile();

public:
    BasicBoss(int level, int max_cooldown, int max_range, int num_minions, sf::Vector2f position, sf::Vector2f minion_positions[]);
    BasicBoss();
    void perform_ai(sf::Vector2f player_position);
    void update_attacks();
    bool has_hit(sf::Shape *body);

    void load_object();
    void unload_object();
    void draw_object(sf::RenderWindow *display);
    void kill_entity();

    Projectile *get_ranged_attacks();
    MeleeEnemy **get_minions();
    int get_base_damage();
    void set_base_damage(int damage);
    ~BasicBoss();
};

#endif