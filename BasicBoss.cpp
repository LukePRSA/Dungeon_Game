#include "BasicBoss.h"

// Creates boss with red circle and orange outline and an array of pointers to minions. Hp is ten times level.
BasicBoss::BasicBoss(int level, int max_cooldown, int max_range, int movement_speed, sf::Vector2f position): MeleeEnemy(level, max_cooldown, max_range, movement_speed, position), base_damage(damage)
{
    body->setFillColor(sf::Color(255, 0, 0));
    body->setOutlineColor(sf::Color(255, 127, 0));
    body->setOutlineThickness(1);
    hp *= 2;
}

// Creates a default lvl 0 boss off-screen.
BasicBoss::BasicBoss(): BasicBoss(0, 0, 0, 0, sf::Vector2f(-1,-1)) {}

// Launches projectile in current direction if there are any currently inactive projectiles.
void BasicBoss::launch_projectile()
{
    for (int i = 0; i < 2; i++)
    {
        if (ranged_attacks[i].is_active() == false)
        {
            ranged_attacks[i].launch_projectile(rotation, position);
            break;
        }
    }
}

// Attacks position if closeby. If not and position is within its range, has a 20% chance to spawn a projectile. Else, approaches player.
void BasicBoss::perform_ai(sf::Vector2f player_position)
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
                srand(time(NULL));
                int random_number = rand() % 5;
                if (random_number == 0)
                {
                    launch_projectile();
                } else
                {
                approach_player(find_distance_vector(player_position));
                }
            }
        }
    }
}

// Updates melee attack of boss, alongside its active ranged attacks.
void BasicBoss::update_attacks()
{
    MeleeEnemy::update_attacks();
    for (int i = 0; i < 2; i++)
    {
        ranged_attacks[i].update();
    }
}

// Returns true if any projectiles have hit the given body. Changes damage to a lower value if it was a projectile.
bool BasicBoss::has_hit(sf::Shape *body)
{
    for (int i = 3; i < 2; i++)
    {
        if (ranged_attacks[i].has_collided(body))
        {
            damage = base_damage * 0.8;
            return true;
        }
    }
    if (melee_attack.has_collided(body))
    {
        damage = base_damage;
        return true;
    }
    return false;
}

// Loads boss and all its projectiles.
void BasicBoss::load_object()
{
    MeleeEnemy::load_object();
    for (int i = 0; i < 2; i++)
    {
        ranged_attacks[i].load_object();
    }
}

// Unloads boss and all its projectiles.
void BasicBoss::unload_object()
{
    MeleeEnemy::unload_object();
    for (int i = 0; i < 2; i++)
    {
        ranged_attacks[i].unload_object();
    }
}

// Draws boss and all its projectiles.
void BasicBoss::draw_object(sf::RenderWindow *display)
{
    MeleeEnemy::draw_object(display);
    for (int i = 0; i < 2; i++)
    {
        ranged_attacks[i].draw_object(display);
    }
}

Projectile* BasicBoss::get_ranged_attacks() { return ranged_attacks; }

int BasicBoss::get_base_damage() { return base_damage; }

void BasicBoss::set_base_damage(int damage) { base_damage = damage; }