#include "Player.h"

// 
Player::Player(int level, int xp, sf::Vector2f position) : Entity(level, xp, level * 10, circle, 50, sf::Vector3<short unsigned int>(0, 255, 255), position)
{
    melee_damage = level * 4;
    ranged_damage = level * 3;
    load_object();
    melee_attack.load_object();
    for (int i = 0; i < 3; i++)
    {
        ranged_projectiles[i].load_object();
    }
    body->setOutlineThickness(1);
}

// Initial level 1 player. Must set position afterwards.
Player::Player() : Player(1, 0, sf::Vector2f(-1, -1))
{
    load_object();
}

// Move player to the right by their movement speed and rotate body to that direction.
void Player::move_right()
{
    body->move(movement_speed, 0);
    position = body->getPosition();
    body->setRotation(0);
    rotation = right;
}

// Move player downward by their movement speed and rotate body to that direction.
void Player::move_down()
{
    body->move(0, movement_speed);
    position = body->getPosition();
    body->setRotation(90);
    rotation = down;
}

// Move player to the left by their movement speed and rotate body to that direction.
void Player::move_left()
{
    body->move(-movement_speed, 0);
    position = body->getPosition();
    body->setRotation(180);
    rotation = left;
}

// Move player upward by their movement speed and rotate body to that direction.
void Player::move_up()
{
    body->move(0, -movement_speed);
    position = body->getPosition();
    body->setRotation(270);
    rotation = up;
}

// Move player by double their movement speed in their current direction if dodge is off cooldown.
void Player::dodge()
{
    int speed_multiplier = 2;
    if (dodge_cooldown <= 0)
    {
        switch (rotation)
        {
        case right:
            body->move(speed_multiplier * movement_speed, 0);
            break;
        case down:
            body->move(0, speed_multiplier * movement_speed);
            break;
        case left:
            body->move(-speed_multiplier * movement_speed, 0);
            break;
        case up:
            body->move(0, -speed_multiplier * movement_speed);
            break;
        }
        position = body->getPosition();
    }
}

// Increase xp by given amount. If above 10 times level, levels up, increasing stats.
void Player::gain_xp(int xp)
{
    this->xp += xp;
    if (this->xp >= 10 * level)
    {
        level++;
        xp = xp - 10 * level;
        hp += 5;
        melee_damage += 3;
        ranged_damage += 2;
    }
}

// Spawns a melee attack in the direction of the player.
void Player::attack_close()
{
    if (melee_attack.is_active() == false)
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
    }
}

// Spawns a ranged projectile in current one if there is one inactive and without cooldown.
void Player::attack_long()
{
    for (int i = 0; i < 3; i++)
    {
        if (projectile_cooldowns[i] <= 0 && ranged_projectiles[i].is_active() == false)
        {
            ranged_projectiles[i].launch_projectile(rotation, position);
            projectile_cooldowns[i] = max_projectile_cooldown;
            break;
        }
    }
}

// Returns true if the player's active melee attack has hit.
bool Player::has_melee_attack_hit(sf::Shape *body)
{
    return melee_attack.has_collided(body);
}

// Returns true if any of the player's active ranged projectiles has hit.
bool Player::has_ranged_projectile_hit(sf::Shape *body)
{
    bool hit = false;
    for (int i = 0; i < 3; i++)
    {
        hit = ranged_projectiles[i].has_collided(body);
    }
    return hit;
}

// Updates movements of projectiles and decreases cooldowns if above 0.
void Player::update()
{
    melee_attack.update();
    for (int i = 0; i < 3; i++)
    {
        ranged_projectiles[i].update();
    }
    if (dodge_cooldown > 0)
    {
        dodge_cooldown--;
    }
    for (int i = 0; i < 3; i++)
    {
        if (projectile_cooldowns[i] > 0)
        {
            projectile_cooldowns[i]--;
        }
    }
}

// Despawns all active player projectiles
void Player::despawn_projectiles()
{
    melee_attack.despawn_projectile();
    for (int i = 0; i < 3; i++)
    {
        ranged_projectiles[i].despawn_projectile();
    }
}

// Draws player and all their projectiles onto given display.
void Player::draw_object(sf::RenderWindow *display)
{
    RoomObject::draw_object(display);
    melee_attack.draw_object(display);
    for (int i = 0; i < 3; i++)
    {
        ranged_projectiles[i].draw_object(display);
    }
}

int Player::get_melee_damage() { return melee_damage; }

void Player::set_melee_damage(int damage) { melee_damage = damage; }

int Player::get_ranged_damage() { return ranged_damage; }

void Player::set_ranged_damage(int damage) { ranged_damage = damage; }

Rotation Player::get_rotation() { return rotation; }

void Player::set_Rotation(Rotation rotation) { this->rotation = rotation; }

Projectile *Player::get_melee_attack() { return &melee_attack; }

Projectile *Player::get_ranged_projectiles() { return ranged_projectiles; }

int Player::get_max_projectile_cooldown() { return max_projectile_cooldown; }

void Player::set_max_projectile_cooldown(int cooldown) { max_projectile_cooldown = cooldown; }

int Player::get_projectile_cooldown(int index) { return projectile_cooldowns[index]; }

void Player::set_projectile_cooldown(int index, int cooldown) { projectile_cooldowns[index] = cooldown; }

int Player::get_max_dodge_cooldown() { return max_dodge_cooldown; }

void Player::set_max_dodge_cooldown(int cooldown) { max_dodge_cooldown = cooldown; }

int Player::get_dodge_cooldown() { return dodge_cooldown; }

void Player::set_dodge_cooldown(int cooldown) { dodge_cooldown = cooldown; }

int Player::get_movement_speed() { return movement_speed; }

void Player::set_movement_speed(int speed) { movement_speed = speed; }