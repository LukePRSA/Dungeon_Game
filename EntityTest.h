#ifndef ENTITY_TEST_H
#define ENTITY_TEST_H

#include "Entity.h"
#include <iostream>

class EntityTest
{
public:
    void run_tests()
    {
        test_constructor_hp();
        test_take_damage();
        test_heal_hp();
        test_kill_entity();
    }

private:
    void test_constructor_hp()
    {
        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 1.1 (constructor initial max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.1 (constructor initial max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 20)
            {
                std::cout << "Test 1.2 (constructor initial hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 1.2 (constructor initial hp) passed." << std::endl;
            }
        }
    }

    void test_take_damage()
    {
        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            entity.take_damage(10);
            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 2.1 (taking non-lethal damage, max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.1 (taking non-lethal damage, max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 10)
            {
                std::cout << "Test 2.2 (taking non-lethal damage, hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.2 (taking non-lethal damage, hp) passed." << std::endl;
            }
            if (entity.is_alive() != true)
            {
                std::cout << "Test 2.3 (taking non-lethal damage, is alive) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 2.3 (taking non-lethal damage, is alive) passed." << std::endl;
            }
        }

        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            entity.take_damage(20);
            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 3.1 (taking exactly lethal damage, max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.1 (taking exactly lethal damage, max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 0)
            {
                std::cout << "Test 3.2 (taking exactly lethal damage, hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.2 (taking exactly lethal damage, hp) passed." << std::endl;
            }
            if (entity.is_alive() != false)
            {
                std::cout << "Test 3.3 (taking exactly lethal damage, is alive) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3.3 (taking exactly lethal damage, is alive) passed." << std::endl;
            }
        }

        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            entity.take_damage(30);
            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 4.1 (taking more than lethal damage, max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.1 (taking more than lethal damage, max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 0)
            {
                std::cout << "Test 4.2 (taking more than lethal damage, hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.2 (taking more than lethal damage, hp) passed." << std::endl;
            }
            if (entity.is_alive() != false)
            {
                std::cout << "Test 4.3 (taking more than lethal damage, is alive) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4.3 (taking more than lethal damage, is alive) passed." << std::endl;
            }
        }
    }

    void test_heal_hp()
    {
        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            entity.take_damage(10);
            entity.heal_hp(5);
            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 5.1 (healing some hp, max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.1 (healing some hp, max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 15)
            {
                std::cout << "Test 5.2 (healing some hp, hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 5.2 (healing some hp, hp) passed." << std::endl;
            }
        }

        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            entity.take_damage(10);
            entity.heal_hp(10);
            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 6.1 (healing to max, max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 6.1 (healing to max, max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 20)
            {
                std::cout << "Test 6.2 (healing to max, hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 6.2 (healing to max, hp) passed." << std::endl;
            }
        }

        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            entity.take_damage(10);
            entity.heal_hp(20);

            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 7.1 (overhealing past max hp, max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 7.1 (overhealing past max hp, max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 20)
            {
                std::cout << "Test 7.2 (overhealing past max hp, hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 7.2 (overhealing past max hp, hp) passed." << std::endl;
            }
        }

        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            entity.take_damage(20);
            entity.heal_hp(15);

            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 8.1 (healing a dead entity, max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 8.1 (healing a dead entity, max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 0)
            {
                std::cout << "Test 8.2 (healing a dead entity, hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 8.2 (healing a dead entity, hp) passed." << std::endl;
            }
            if (entity.is_alive() != false)
            {
                std::cout << "Test 8.3 (healing a dead entity, is alive) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 8.3 (healing a dead entity, is alive) passed." << std::endl;
            }
        }
    }

    void test_kill_entity()
    {
        {
            Entity entity(2, 5, 20, RoomObject::circle, 5, sf::Color::White, sf::Vector2f(0, 0));
            entity.kill_entity();
            if (entity.get_max_hp() != 20)
            {
                std::cout << "Test 9.1 (killing entity, max_hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.1 (killing entity, max_hp) passed." << std::endl;
            }
            if (entity.get_hp() != 0)
            {
                std::cout << "Test 9.2 (killing entity, hp) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.2 (killing entity, hp) passed." << std::endl;
            }
            if (entity.get_position() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 9.3 (killing entity, attribute position) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.3 (killing entity, attribute position) passed." << std::endl;
            }
            if (entity.is_alive() != false)
            {
                std::cout << "Test 9.4 (killing entity, is alive) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 9.4 (killing entity, is alive) passed." << std::endl;
            }
        }
    }
};

#endif