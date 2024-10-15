#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <iostream>
#include "Player.h"

const int TILE_SIZE_TO_PIXELS = 58;

class PlayerTest
{
public:
    void run_tests()
    {
        test_movements();
        test_dodge();
        test_melee_attack();
        test_gain_xp();
        test_ranged_attack();
    }

private:
    void test_movements()
    {
        {
            Player player(5);
            player.set_position(sf::Vector2f(50, 55));
            player.move_down();
            if (player.get_position() != sf::Vector2f(50, 60))
            {
                std::cout << "Test 1.1 (moving down, attribute position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.1 (moving down, attribute position) has passed." << std::endl;
            }
            if (player.get_body()->getPosition() != sf::Vector2f(50, 60))
            {
                std::cout << "Test 1.2 (moving down, body position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.2 (moving down, body position) has passed." << std::endl;
            }
            if (player.get_rotation() != RoomObject::down)
            {
                std::cout << "Test 1.3 (moving down, rotation) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.3 (moving down, rotation) has passed." << std::endl;
            }
            if (player.is_loaded() != true)
            {
                std::cout << "Test 1.4 (moving down, is initially loaded) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.4 (moving down, is initially loaded) has passed." << std::endl;
            }
        }

        {
            Player player(5);
            player.set_position(sf::Vector2f(50, 55));
            player.move_left();
            if (player.get_position() != sf::Vector2f(45, 55))
            {
                std::cout << "Test 2.1 (moving left, attribute position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.1 (moving left, attribute position) has passed." << std::endl;
            }
            if (player.get_body()->getPosition() != sf::Vector2f(45, 55))
            {
                std::cout << "Test 2.2 (moving left, body position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.2 (moving left, body position) has passed." << std::endl;
            }
            if (player.get_rotation() != RoomObject::left)
            {
                std::cout << "Test 2.3 (moving left, rotation) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.3 (moving left, rotation) has passed." << std::endl;
            }
        }

        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.move_up();
            if (player.get_position() != sf::Vector2f(50, 45))
            {
                std::cout << "Test 3.1 (moving up with double speed, attribute position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.1 (moving up with double speed, attribute position) has passed." << std::endl;
            }
            if (player.get_body()->getPosition() != sf::Vector2f(50, 45))
            {
                std::cout << "Test 3.2 (moving up with double speed, body position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.2 (moving up with double speed, body position) has passed." << std::endl;
            }
            if (player.get_rotation() != RoomObject::up)
            {
                std::cout << "Test 3.3 (moving up with double speed, rotation) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.3 (moving up with double speed, rotation) has passed." << std::endl;
            }
        }
    }

    void test_dodge()
    {
        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.set_Rotation(RoomObject::left);
            player.dodge();
            if (player.get_position() != sf::Vector2f(40, 55))
            {
                std::cout << "Test 4.1 (dodge left, attribute position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.1 (dodge left, attribute position) has passed." << std::endl;
            }
            if (player.get_body()->getPosition() != sf::Vector2f(40, 55))
            {
                std::cout << "Test 4.2 (dodge left, body position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.2 (dodge left, body position) has passed." << std::endl;
            }
            if (player.get_rotation() != RoomObject::left)
            {
                std::cout << "Test 4.3 (dodge left, rotation) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.3 (dodge left, rotation) has passed." << std::endl;
            }
            if (player.get_dodge_cooldown() != 3)
            {
                std::cout << "Test 4.4 (dodge left, dodge cooldown) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.4 (dodge left, dodge cooldown) has passed." << std::endl;
            }
        }

        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.set_Rotation(RoomObject::left);
            player.set_dodge_cooldown(1);
            player.dodge();
            if (player.get_position() != sf::Vector2f(50, 55))
            {
                std::cout << "Test 5.1 (dodge while on cooldown, attribute position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.1 (dodge while on cooldown, attribute position) has passed." << std::endl;
            }
            if (player.get_body()->getPosition() != sf::Vector2f(50, 55))
            {
                std::cout << "Test 5.2 (dodge while on cooldown, body position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.2 (dodge while on cooldown, body position) has passed." << std::endl;
            }
            if (player.get_rotation() != RoomObject::left)
            {
                std::cout << "Test 5.3 (dodge while on cooldown, rotation) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.3 (dodge while on cooldown, rotation) has passed." << std::endl;
            }
            if (player.get_dodge_cooldown() != 1)
            {
                std::cout << "Test 5.4 (dodge while on cooldown, dodge cooldown) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.4 (dodge while on cooldown, dodge cooldown) has passed." << std::endl;
            }
        }
    }

    void test_melee_attack()
    {
        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.set_Rotation(RoomObject::left);
            sf::RectangleShape body1(sf::Vector2f(25, 25));
            body1.setPosition(30, 55);
            player.attack_close();
            if (player.has_melee_attack_hit(&body1) != true)
            {
                std::cout << "Test 6.1 (collision with melee attack, has attack hit) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 6.1 (collision with melee attack, has attack hit) has passed." << std::endl;
            }
            if (player.get_melee_damage() != player.get_level() * 4)
            {
                std::cout << "Test 6.2 (collision with melee attack, melee damage is level * 4) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 6.2 (collision with melee attack, melee damage is level * 4) has passed." << std::endl;
            }
        }

        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.set_Rotation(RoomObject::left);
            sf::RectangleShape body1(sf::Vector2f(25, 25));
            body1.setPosition(30, 55);
            player.attack_close();
            player.has_melee_attack_hit(&body1);
            if (player.has_melee_attack_hit(&body1) != false)
            {
                std::cout << "Test 7.1 (if melee_attack has despawned after one hit, has attack hit) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 7.1 (if melee_attack has despawned after one hit, has attack hit) has passed." << std::endl;
            }
            if (player.get_melee_damage() != player.get_level() * 4)
            {
                std::cout << "Test 7.2 (if melee_attack has despawned after one hit, melee damage is level * 4) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 7.2 (if melee_attack has despawned after one hit, melee damage is level * 4) has passed." << std::endl;
            }
        }

        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.set_Rotation(RoomObject::left);
            sf::RectangleShape body1(sf::Vector2f(25, 25));
            body1.setPosition(30, 55);
            player.attack_close();
            player.update();
            player.update();
            if (player.has_melee_attack_hit(&body1) != false)
            {
                std::cout << "Test 8 (if melee_attack has despawned after updates, has attack hit) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 8 (if melee_attack has despawned after updates, has attack hit) has passed." << std::endl;
            }
        }
    }

    void test_gain_xp()
    {
        {
            Player player(10);
            player.gain_xp(5);
            if (player.get_xp() != 5)
            {
                std::cout << "Test 9.1 (gaining some xp, xp) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.1 (gaining some xp, xp) has passed." << std::endl;
            }
            if (player.get_level() != 1)
            {
                std::cout << "Test 9.2 (gaining some xp, level) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.2 (gaining some xp, level) has passed." << std::endl;
            }
            if (player.get_melee_damage() != player.get_level() * 4)
            {
                std::cout << "Test 9.3 (gaining some xp, melee_damage) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.3 (gaining some xp, melee_damage) has passed." << std::endl;
            }
            if (player.get_ranged_damage() != player.get_level() * 3)
            {
                std::cout << "Test 9.4 (gaining some xp, ranged_damage) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.4 (gaining some xp, ranged_damage) has passed." << std::endl;
            }
            if (player.get_max_hp() != player.get_level() * 10)
            {
                std::cout << "Test 9.5 (level up, hp) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.5 (level up, hp) has passed." << std::endl;
            }
        }

        {
            Player player(10);
            player.gain_xp(10);
            if (player.get_xp() != 0)
            {
                std::cout << "Test 10.1 (level up, xp) has failed." << player.get_xp() << std::endl;
            }
            else
            {
                std::cout << "Test 10.1 (level up, xp) has passed." << player.get_xp() << std::endl;
            }
            if (player.get_level() != 2)
            {
                std::cout << "Test 10.2 (level up, level) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 10.2 (level up, level) has passed." << std::endl;
            }
            if (player.get_melee_damage() != player.get_level() * 4)
            {
                std::cout << "Test 10.3 (level up, melee_damage) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 10.3 (level up, melee_damage) has passed." << std::endl;
            }
            if (player.get_ranged_damage() != player.get_level() * 3)
            {
                std::cout << "Test 10.4 (level up, ranged_damage) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 10.4 (level up, ranged_damage) has passed." << std::endl;
            }
            if (player.get_max_hp() != player.get_level() * 10)
            {
                std::cout << "Test 10.5 (level up, hp) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 10.5 (level up, hp) has passed." << std::endl;
            }
        }

        {
            Player player(10);
            player.gain_xp(15);
            if (player.get_xp() != 5)
            {
                std::cout << "Test 11.1 (level up + xp, xp) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 11.1 (level up + xp, xp) has passed." << std::endl;
            }
            if (player.get_level() != 2)
            {
                std::cout << "Test 11.2 (level up + xp, level) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 11.2 (level up + xp, level) has passed." << std::endl;
            }
            if (player.get_melee_damage() != player.get_level() * 4)
            {
                std::cout << "Test 11.3 (level up + xp, melee_damage) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 11.3 (level up + xp, melee_damage) has passed." << std::endl;
            }
            if (player.get_ranged_damage() != player.get_level() * 3)
            {
                std::cout << "Test 11.4 (level up + xp, ranged_damage) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 11.4 (level up + xp, ranged_damage) has passed." << std::endl;
            }
            if (player.get_max_hp() != player.get_level() * 10)
            {
                std::cout << "Test 11.5 (level up + xp, hp) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 11.5 (level up + xp, hp) has passed." << std::endl;
            }
        }
    }

    void test_ranged_attack()
    {
        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.set_Rotation(RoomObject::left);
            sf::RectangleShape body1(sf::Vector2f(25, 25));
            body1.setPosition(0, 55);
            player.attack_long();
            player.update();
            if (player.has_ranged_projectile_hit(&body1) != true)
            {
                std::cout << "Test 12.1 (collision with ranged attack, has attack hit) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 12.1 (collision with ranged attack, has attack hit) has passed." << std::endl;
            }
            if (player.get_ranged_damage() != player.get_level() * 3)
            {
                std::cout << "Test 12.2 (collision with ranged attack, ranged damage is level * 3) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 12.2 (collision with ranged attack, ranged damage is level * 3) has passed." << std::endl;
            }
            if (player.get_projectile_cooldown(0) != 9)
            {
                std::cout << "Test 12.3 (collision with ranged attack, cooldown) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 12.3 (collision with ranged attack, cooldown) has passed." << std::endl;
            }
            if (player.get_ranged_projectiles()[0].is_active() != false)
            {
                std::cout << "Test 12.4 (collision with ranged attack, is projectile active) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 12.4 (collision with ranged attack, is projectile active) has passed." << std::endl;
            }
        }

        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.set_Rotation(RoomObject::left);
            player.attack_long();
            player.update();
            player.attack_long();
            player.update();
            if (player.get_projectile_cooldown(0) != 8)
            {
                std::cout << "Test 13.1 (two ranged projectiles, cooldown of first) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 13.1 (two ranged projectiles, cooldown of first) has passed." << std::endl;
            }
            if (player.get_projectile_cooldown(1) != 9)
            {
                std::cout << "Test 13.2 (two ranged projectiles, cooldown of second) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 13.2 (two ranged projectiles, cooldown of second) has passed." << std::endl;
            }
            if (player.get_ranged_projectiles()[0].is_active() != true)
            {
                std::cout << "Test 13.3 (two ranged projectiles, is first projectile active) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 13.3 (two ranged projectiles, is first projectile active) has passed." << std::endl;
            }
            if (player.get_ranged_projectiles()[1].is_active() != true)
            {
                std::cout << "Test 13.4 (two ranged projectiles, is second projectile active) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 13.4 (two ranged projectiles, is second projectile active) has passed." << std::endl;
            }
        }

        {
            Player player(10);
            player.set_position(sf::Vector2f(50, 55));
            player.set_Rotation(RoomObject::left);
            player.attack_long();
            player.update();
            player.move_up();
            player.attack_long();
            player.update();
            if (player.get_projectile_cooldown(0) != 8)
            {
                std::cout << "Test 14.1 (two ranged projectiles where second is up, cooldown of first) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 14.1 (two ranged projectiles where second is up, cooldown of first) has passed." << std::endl;
            }
            if (player.get_projectile_cooldown(1) != 9)
            {
                std::cout << "Test 14.2 (two ranged projectiles where second is up, cooldown of second) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 14.2 (two ranged projectiles where second is up, cooldown of second) has passed." << std::endl;
            }
            if (player.get_ranged_projectiles()[0].get_direction() != RoomObject::left)
            {
                std::cout << "Test 14.3 (two ranged projectiles where second is up, is first projectile left) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 14.3 (two ranged projectiles where second is up, is first projectile left) has passed." << std::endl;
            }
            if (player.get_ranged_projectiles()[1].get_direction() != RoomObject::up)
            {
                std::cout << "Test 14.4 (two ranged projectiles where second is up, is second projectile up) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 14.4 (two ranged projectiles where second is up, is second projectile up) has passed." << std::endl;
            }
        }
    }
};

#endif