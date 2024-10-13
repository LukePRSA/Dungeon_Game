#include "StrikerEnemy.h"

// Creates striker enemy with damage 6 times level, xp 4 times level, hp 7 times level.
StrikerEnemy::StrikerEnemy(int level, int max_cooldown, int max_range, sf::Vector2f position): Enemy(level * 6, max_cooldown, max_range, level, level * 4, level * 7, square, 50, sf::Color(255, 255, 0), position) {}

// Creates a striker enemy off screen.
StrikerEnemy::StrikerEnemy() : StrikerEnemy(0, 0, 0, sf::Vector2f(-1, -1)) {}

// If loaded, the player is within max range and the attack cooldown is 0 or less, places a target on the enemy.
void StrikerEnemy::perform_ai(sf::Vector2f player_position)
{
    if (loaded)
    {
        if (find_distance(player_position) <= max_range && target.is_active() && attack_cooldown <= 0)
        {
            target.place_target(player_position);
            attack_cooldown = max_cooldown;
        }
    }
}

// Updates target if loaded, reduces cooldown by 1 if above 0.
void StrikerEnemy::update_attacks()
{
    if (loaded)
    {
        target.update_target();
    }
    if (attack_cooldown > 0)
    {
        attack_cooldown--;
    }
}

// Loads enemy and its target.
void StrikerEnemy::load_object()
{
    Enemy::load_object();
    target.load_object();
}

// Unloads enemy and its target.
void StrikerEnemy::unload_object()
{
    Enemy::unload_object();
    target.unload_object();
}

// Draws enemy and its target.
void StrikerEnemy::draw_object(sf::RenderWindow *display)
{
    Enemy::draw_object(display);
    target.draw_object(display);
}

StrikerTarget *StrikerEnemy::get_target() { return &target; }