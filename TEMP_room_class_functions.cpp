#include "RoomObject.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "MeleeEnemy.h"
#include "StrikerEnemy.h"
#include "BasicBoss.h"
#include "HealthConsumable.h"
#include "Trap.h"
#include "ArrowTrap.h"
#include "SpikeTrap.h"
#include <SFML/Graphics.hpp>

class Room
{
private:
    RoomObject *walls;
    int num_walls;
    Entity *breakable_walls;
    int num_breakable_walls;
    Enemy *enemies;
    int num_alive_entities;
    int num_enemies;
    Trap *traps;
    int num_traps;
    HealthConsumable *health_consumables;
    int num_consumables;
    Player *player;
    RoomObject entrance;
    sf::Vector2f start_position;
    RoomObject exit;
    sf::Vector2f end_position;

public:
    // Loads all objects in room. If from_next_room is true, the player teleports near the exit. Else, near the entrance.
    void load_room(bool from_next_room)
    {
        for (int i = 0; i < num_walls; i++)
        {
            walls[i].load_object();
        }
        for (int i = 0; i < num_breakable_walls; i++)
        {
            breakable_walls[i].load_object();
        }
        for (int i = 0; i < num_enemies; i++)
        {
            enemies[i].load_object();
        }
        for (int i = 0; i < num_traps; i++)
        {
            traps[i].load_object();
        }
        for (int i = 0; i < num_consumables; i++)
        {
            health_consumables[i].load_object();
        }
        if (from_next_room)
        {
            player->set_position(end_position);
        }
        else
        {
            player->set_position(start_position);
        }
    }

    // Unloads all objects in room.
    void unload_room()
    {
        for (int i = 0; i < num_walls; i++)
        {
            walls[i].unload_object();
        }
        for (int i = 0; i < num_breakable_walls; i++)
        {
            breakable_walls[i].unload_object();
        }
        for (int i = 0; i < num_enemies; i++)
        {
            enemies[i].unload_object();
        }
        for (int i = 0; i < num_traps; i++)
        {
            traps[i].unload_object();
        }
        for (int i = 0; i < num_consumables; i++)
        {
            health_consumables[i].unload_object();
        }
    }

    // Passes a turn for all the enemies and traps in the room.
    void pass_turn() // fix
    {
        for (int i = 0; i < num_enemies; i++)
        {
            sf::Vector2f initial_position = enemies[i].get_position();
            enemies[i].perform_ai(player->get_position());
            if (has_hit_walls(enemies[i].get_body()))
            {
                enemies[i].set_position(initial_position);
            }
            enemies[i].update_attacks();
            for (int i = 0; i < num_walls; i++) // removes enemy projectiles upon hitting a wall
            {
                if (enemies[i].has_hit(walls[i].get_body()))
                {
                    break;
                }
            }
            for (int i = 0; i < num_breakable_walls; i++)
            {
                if (enemies[i].has_hit(breakable_walls[i].get_body()))
                {
                    break;
                }
            }
        }
        for (int i = 0; i < num_traps; i++)
        {
            traps[i].update_trap();
        }
        check_player_collisions();
        check_other_collisions();
        check_exit_availability();
    }

    // Checks player collisions with objects in room, dealing or healing the player as a result.
    void check_player_collisions()
    {
        for (int i = 0; i < num_enemies; i++)
        {
            if (enemies[i].has_hit(player->get_body()))
            {
                player->take_damage(enemies[i].get_damage());
            }
        }
        for (int i = 0; i < num_traps; i++)
        {
            if (traps[i].is_triggered(player->get_body()))
            {
                player->take_damage(traps[i].get_damage());
            }
        }
        for (int i = 0; i < num_consumables; i++)
        {
            if (health_consumables[i].has_collided(player->get_body()))
            {
                player->heal_hp(health_consumables[i].get_health_bonus_percentage() * player->get_max_hp());
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (has_hit_walls(player->get_ranged_projectiles()[i].get_body()))
            {
                player->get_ranged_projectiles()[i].despawn_projectile();
            }
        }
    }

    // Checks collisions and interactions of enemies and traps with the other objects.
    void check_other_collisions()
    {
        for (int i = 0; i < num_enemies; i++)
        {
            if (player->has_melee_attack_hit(enemies[i].get_body()))
            {
                enemies[i].take_damage(player->get_melee_damage());
                if (enemies[i].is_alive() == false)
                {
                    player->gain_xp(enemies[i].get_xp());
                    num_alive_entities--;
                }
            }
            if (player->has_ranged_projectile_hit(enemies[i].get_body()))
            {
                enemies[i].take_damage(player->get_melee_damage());
                if (enemies[i].is_alive() == false)
                {
                    player->gain_xp(enemies[i].get_xp());
                }
            }
        }
        for (int i = 0; i < num_traps; i++)
        {
            for (int j = 0; j < num_enemies; j++)
            {
                if (traps[i].is_triggered(enemies[j].get_body()))
                {
                    enemies[j].take_damage(traps[i].get_damage());
                }
            }
            for (int i = 0; i < num_walls; i++) // causes arrow trap projectiles to delete arrows when coliided with walls
            {
                if (traps[i].is_triggered(walls[i].get_body()))
                {
                    break;
                }
            }
            for (int i = 0; i < num_breakable_walls; i++) // causes arrow trap projectiles to delete arrows when coliided with breakable walls
            {
                if (traps[i].is_triggered(breakable_walls[i].get_body()))
                {
                    break;
                }
            }
        }
    }

    // Toggles all traps' active state.
    void toggle_traps()
    {
        for (int i = 0; i < num_traps; i++)
        {
            traps[i].toggle_active();
        }
    }

    // Returns true if the given body has collided with any active walls in the room.
    bool has_hit_walls(sf::Shape *body)
    {
        bool has_hit_wall = false;
        for (int i = 0; i < num_walls; i++)
        {
            if (walls[i].has_collided(body))
            {
                has_hit_wall = true;
                break;
            }
        }
        for (int i = 0; i < num_breakable_walls; i++)
        {
            if (has_hit_wall = true)
            {
                break;
            }
            else if (breakable_walls[i].has_collided(body))
            {
                has_hit_wall = true;
                break;
            }
        }
        return has_hit_wall;
    }

    // Reveals exit if there are 0 or less enemies present.
    void check_exit_availability()
    {
        if (num_alive_entities <= 0)
        {
            exit.get_body()->setFillColor(sf::Color(0, 127, 0, 255));
        }
    }

    // Returns true if player has collided with entrance.
    bool has_collided_with_entrance()
    {
        return player->has_collided(entrance.get_body());
    }

    // Returns true if player has collided with exit.
    bool has_collided_with_exit()
    {
        return player->has_collided(exit.get_body());
    }

};