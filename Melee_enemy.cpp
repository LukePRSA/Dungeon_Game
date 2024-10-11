#include "Melee_enemy.h"

Melee_enemy::Melee_enemy(int level, int xp)
{
}

Melee_enemy::Melee_enemy()
{
}

// Approaches player using the shortest distance that is above or equal to its movement speed.
void Melee_enemy::approach_player(sf::Vector2f player_distance_vector)
{
    float shortest_distance = player_distance_vector.x;
    bool is_y_distance = false;
    if ((float)abs(shortest_distance) > (float)abs(player_distance_vector.y) && player_distance_vector.y >= movement_speed)
    {
        shortest_distance = player_distance_vector.y;
        is_y_distance = true;
    }
    if (shortest_distance >= 0 && is_y_distance == false)
    {
        body->move(movement_speed, 0);
        position = body->getPosition();
        rotation = right;
    } else if (shortest_distance < 0 && is_y_distance == false)
    {
        body->move(-movement_speed, 0);
        position = body->getPosition();
        rotation = left;
    } else if (shortest_distance >= 0 && is_y_distance == true)
    {
        body->move(0, movement_speed);
        position = body->getPosition();
        rotation = down;
    } else if (shortest_distance < 0 && is_y_distance == true)
    {
        body->move(0, -movement_speed);
        position = body->getPosition();
        rotation = up;
    } 
}

void Melee_enemy::attack()
{
    // creates melee attack projectile in front of enemy if the melee_attack is not currently active and its attack cooldown is zero or lower
    if (melee_attack.is_active() == false && attack_cooldown <= 0)
    {
        switch (rotation)
        {
        case right:
            melee_attack.launch_projectile(right, position + sf::Vector2f(29, 0));
            break;
        case down:
            melee_attack.launch_projectile(down, position + sf::Vector2f(0, 29));
            break;
        case left:
            melee_attack.launch_projectile(left, position + sf::Vector2f(-29, 0));
            break;
        case up:
            melee_attack.launch_projectile(up, position + sf::Vector2f(0, -29));
            break;
        }
        attack_cooldown = max_cooldown;
    }
}

void Melee_enemy::perform_ai(sf::Vector2f player_position)
{
    // if loaded, attacks player if nearly within melee attack range, else approaches player if within max_range
    if (loaded)
    {
        float player_distance = find_distance(player_position);
        if (player_distance < max_range)
        {
            if (player_distance < 80)
            {
                attack();
            }
            else
            {
                approach_player(find_distance_vector(player_position));
            }
        }
    }
}

void Melee_enemy::update_attacks()
{
    // updates melee_attack projectile
    melee_attack.update();
}

bool Melee_enemy::has_collided(sf::Shape *body)
{
    // returns true if the enemy's attack projectile has hit
    return melee_attack.has_collided(body);
}

void Melee_enemy::load_object()
{
    // also loads enemy projectile
    Enemy::load_object();
    melee_attack.load_object();
}

void Melee_enemy::unload_object()
{
    // also unloads enemy projectile
    Enemy::unload_object();
    melee_attack.unload_object();
}

Projectile *Melee_enemy::get_melee_attack() { return &melee_attack; }

int Melee_enemy::get_movement_speed() { return movement_speed; }

void Melee_enemy::set_movement_speed(int speed) { movement_speed = speed; }

Rotation Melee_enemy::get_rotation() { return rotation; }

void Melee_enemy::set_rotation(Rotation rotation) { this->rotation = rotation; }