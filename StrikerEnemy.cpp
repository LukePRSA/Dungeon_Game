#include "StrikerEnemy.h"

// Creates striker enemy with damage 6 times level, xp 4 times level, hp 7 times level.
StrikerEnemy::StrikerEnemy(int level, int max_cooldown, int max_range, sf::Vector2f position): Enemy(level * 6, max_cooldown, max_range, level, level * 4, level * 7, square, 50, sf::Color(255, 255, 0), position) {}

// Creates a striker enemy off screen.
StrikerEnemy::StrikerEnemy() : StrikerEnemy(0, 0, 0, sf::Vector2f(-100, -100)) {}

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

// Returns true if the target is active and can deal damage.
bool StrikerEnemy::has_hit(sf::Shape *body)
{
    if (loaded && target.is_active() && target.can_deal_damage() && target.has_collided(body))
    {
        return true;
    }
    return false;
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

// Returns body if loaded and alive. Also, returns striker target body if active.
std::vector<sf::Shape *> StrikerEnemy::get_draw_objects()
{
    std::vector<sf::Shape *> drawable_objects;
    if (loaded && alive)
    {
        drawable_objects.push_back(body);
        if (target.is_active() == true)
        {
            drawable_objects.push_back(target.get_body());
        }
    }
    return drawable_objects;
}

StrikerTarget *StrikerEnemy::get_target() { return &target; }