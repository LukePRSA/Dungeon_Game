#include "MeleeEnemy.h"

// Creates melee enemy with damage 3 times level, xp 4 times level and hp 5 times level.
MeleeEnemy::MeleeEnemy(int level, int max_cooldown, int max_range, sf::Vector2f position) : Enemy(level * 3, max_cooldown, max_range, level, level * 3, level * 5, circle, 50, sf::Color(255, 64, 0), position) {}

MeleeEnemy::MeleeEnemy() : MeleeEnemy(0, 0, 0, sf::Vector2f(-1, -1)) {}

// Approaches player using the shortest distance that is above or equal to its movement speed.
void MeleeEnemy::approach_player(sf::Vector2f player_distance_vector)
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
    }
    else if (shortest_distance < 0 && is_y_distance == false)
    {
        body->move(-movement_speed, 0);
        position = body->getPosition();
        rotation = left;
    }
    else if (shortest_distance >= 0 && is_y_distance == true)
    {
        body->move(0, movement_speed);
        position = body->getPosition();
        rotation = down;
    }
    else if (shortest_distance < 0 && is_y_distance == true)
    {
        body->move(0, -movement_speed);
        position = body->getPosition();
        rotation = up;
    }
}

// Creates melee attack projectile in front of enemy if the melee_attack is not currently active and its attack cooldown is zero or lower.
void MeleeEnemy::attack()
{
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

// If loaded, attacks player if nearly within melee attack range, else approaches player if within max_range.
void MeleeEnemy::perform_ai(sf::Vector2f player_position)
{
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

// Updates melee_attack projectile and decreases positive cooldown by one.
void MeleeEnemy::update_attacks()
{
    melee_attack.update();
    if (attack_cooldown > 0)
    {
        attack_cooldown--;
    }
}

// Returns true if the enemy's attack projectile has hit.
bool MeleeEnemy::has_collided(sf::Shape *body)
{
    return melee_attack.has_collided(body);
}

// Loads enemy and its projectile.
void MeleeEnemy::load_object()
{
    Enemy::load_object();
    melee_attack.load_object();
}

// Unloads enemy and its projectile.
void MeleeEnemy::unload_object()
{
    Enemy::unload_object();
    melee_attack.unload_object();
}

// Draws enemy and its projectiles on the screen
void MeleeEnemy::draw_object(sf::RenderWindow *display)
{
    Enemy::draw_object(display);
    melee_attack.draw_object(display);
}

Projectile *MeleeEnemy::get_melee_attack() { return &melee_attack; }

int MeleeEnemy::get_movement_speed() { return movement_speed; }

void MeleeEnemy::set_movement_speed(int speed) { movement_speed = speed; }

Rotation MeleeEnemy::get_rotation() { return rotation; }

void MeleeEnemy::set_rotation(Rotation rotation) { this->rotation = rotation; }