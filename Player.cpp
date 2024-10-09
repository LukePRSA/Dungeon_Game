#include "Player.h"

Player::Player(int level, int xp, int movement_speed, sf::Vector2f position); // make sure to load object
Player::Player(); // make sure to load object

void Player::move_right()
{
    // move player to the right by their movement speed and rotate body to that direction
    body->move(movement_speed, 0);
    position = body->getPosition();
    body->setRotation(0);
    rotation = right;
}

void Player::move_down()
{
    // move player downward by their movement speed and rotate body to that direction
    body->move(0, movement_speed);
    position = body->getPosition();
    body->setRotation(90);
    rotation = down;
}

void Player::move_left()
{
    // move player to the left by their movement speed and rotate body to that direction
    body->move(-movement_speed, 0);
    position = body->getPosition();
    body->setRotation(180);
    rotation = left;
}

void Player::move_up()
{
    // move player upward by their movement speed and rotate body to that direction
    body->move(0, -movement_speed);
    position = body->getPosition();
    body->setRotation(270);
    rotation = up;    
}

void Player::dodge()
{
    // move player by double their movement speed in their current direction
    int speed_multiplier = 2;
    switch (rotation)
    {
        case right:
        body->move(speed_multiplier*movement_speed, 0);
        break;
        case down:
        body->move(0, speed_multiplier*movement_speed);
        break;
        case left:
        body->move(-speed_multiplier*movement_speed, 0);
        break;
        case up:
        body->move(0, -speed_multiplier*movement_speed);
        break;
    }
    position = body->getPosition();
}

void Player::gain_xp(int xp)
{
    // increase xp by given amount. If above 10 times level, levels up, increasing stats
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

void Player::attack_close();
void Player::attack_long();
bool Player::has_melee_attack_hit(Shape *body);
bool Player::has_ranged_projectile_hit(Shape *body);
void Player::update();

void Player::despawn_projectiles()
{
    // despawns all active player projectiles
    melee_attack.despawn_projectile();
    for (int i = 0; i < 3; i++)
    {
        ranged_projectiles[i].despawn_projectile();
    }
}

void Player::draw_object(sf::RenderWindow *display)
{
    // overridden to also include projectiles
    Room_object::draw_object(display);
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

Projectile* Player::get_melee_attack() { return &melee_attack; }

Projectile* Player::get_ranged_projectiles() { return ranged_projectiles; }

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