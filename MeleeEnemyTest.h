#ifndef MELEE_ENEMY_TEST_H
#define MELEE_ENEMY_TEST_H

#include "MeleeEnemy.h"
#include <iostream>

class MeleeEnemyTest
{
public:
    void run_tests()
    {
        test_perform_ai();
        test_has_hit();
        test_load_unload();
        test_update_attacks();
    }

private:
    void test_perform_ai()
    {
        {
            MeleeEnemy melee_enemy(3, 3, 350, 5, sf::Vector2f(0, 0));
            melee_enemy.load_object();
            sf::Vector2f position = {400, 400};
            melee_enemy.perform_ai(position);
            if (melee_enemy.get_attack_cooldown() != 0)
            {
                std::cout << "Test 1.1 (testing out of max range, attack_cooldown) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.1 (testing out of max range, attack_cooldown) has passed." << std::endl;
            }
            if (melee_enemy.get_position() != sf::Vector2f(0, 0))
            {
                std::cout << "Test 1.2 (testing out of max range, position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.2 (testing out of max range, position) has passed." << std::endl;
            }
            if (melee_enemy.get_melee_attack()->is_active() != false)
            {
                std::cout << "Test 1.3 (testing out of max range, is projectile active) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.3 (testing out of max range, is projectile active) has passed." << std::endl;
            }
        }

        {
            MeleeEnemy melee_enemy(3, 3, 350, 5, sf::Vector2f(0, 0));
            melee_enemy.load_object();
            sf::Vector2f position = {300, 250};
            melee_enemy.perform_ai(position);
            if (melee_enemy.get_attack_cooldown() != 0)
            {
                std::cout << "Test 2.1 (testing within max range, attack_cooldown) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.1 (testing within max range, attack_cooldown) has passed." << std::endl;
            }
            if (melee_enemy.get_position() != sf::Vector2f(0, 5))
            {
                std::cout << "Test 2.2 (testing within max range, attribute position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.2 (testing within max range, attribute position) has passed." << std::endl;
            }
            if (melee_enemy.get_body()->getPosition() != sf::Vector2f(0, 5))
            {
                std::cout << "Test 2.3 (testing within max range, body position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.3 (testing within max range, body position) has passed." << std::endl;
            }
            if (melee_enemy.get_rotation() != RoomObject::down)
            {
                std::cout << "Test 2.4 (testing within max range, rotation) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.4 (testing within max range, rotation) has passed." << std::endl;
            }
            if (melee_enemy.get_melee_attack()->is_active() != false)
            {
                std::cout << "Test 2.5 (testing within max range, is projectile active) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.5 (testing within max range, is projectile active) has passed." << std::endl;
            }
        }

        {
            MeleeEnemy melee_enemy(3, 3, 350, 5, sf::Vector2f(0, 0));
            melee_enemy.load_object();
            sf::Vector2f position = {50, 50};
            melee_enemy.perform_ai(position);
            if (melee_enemy.get_attack_cooldown() != 3)
            {
                std::cout << "Test 3.1 (testing within attack range, attack_cooldown) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.1 (testing within attack range, attack_cooldown) has passed." << std::endl;
            }
            if (melee_enemy.get_position() != sf::Vector2f(0, 0))
            {
                std::cout << "Test 3.2 (testing within attack range, position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.2 (testing within attack range, position) has passed." << std::endl;
            }
            if (melee_enemy.get_melee_attack()->is_active() != true)
            {
                std::cout << "Test 3.3 (testing within attack range, is projectile active) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.3 (testing within attack range, is projectile active) has passed." << std::endl;
            }
        }
    }

    void test_has_hit()
    {
        {
            MeleeEnemy melee_enemy(3, 3, 350, 5, sf::Vector2f(0, 0));
            melee_enemy.load_object();
            sf::CircleShape body(25);
            body.setPosition(50, 50);
            melee_enemy.perform_ai(body.getPosition());
            if (melee_enemy.has_hit(&body) != true)
            {
                std::cout << "Test 4.1 (testing has_hit, has hit body) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.1 (testing has_hit, has hit body) has passed." << std::endl;
            }
            if (melee_enemy.get_position() != sf::Vector2f(0, 0))
            {
                std::cout << "Test 4.2 (testing has_hit, position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.2 (testing has_hit, position) has passed." << std::endl;
            }
            if (melee_enemy.get_melee_attack()->is_active() != false)
            {
                std::cout << "Test 4.3 (testing has_hit, is projectile inactive after collision) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.3 (testing has_hit, is projectile inactive after collision) has passed." << std::endl;
            }
        }

        {
            MeleeEnemy melee_enemy(3, 3, 350, 5, sf::Vector2f(0, 0));
            melee_enemy.load_object();
            melee_enemy.set_rotation(RoomObject::right); // assurance it is facing right
            sf::CircleShape body(25);
            body.setPosition(-70, 0);
            melee_enemy.perform_ai(body.getPosition());

            if (melee_enemy.has_hit(&body) != false)
            {
                std::cout << "Test 5.1 (close enough to get hit but isn't hit, has hit body) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.1 (close enough to get hit but isn't hit, has hit body) has passed." << std::endl;
            }
            if (melee_enemy.get_position() != sf::Vector2f(0, 0))
            {
                std::cout << "Test 5.2 (close enough to get attacked but isn't hit, position) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.2 (close enough to get attacked but isn't hit, position) has passed." << std::endl;
            }
            if (melee_enemy.get_melee_attack()->is_active() != true)
            {
                std::cout << "Test 5.3 (close enough to get attacked but isn't hit, is projectile inactive after collision) has failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.3 (close enough to get attacked but isn't hit, is projectile inactive after collision) has passed." << std::endl;
            }
        }
    }

    void test_load_unload() {}

    void test_update_attacks() {}
};

#endif