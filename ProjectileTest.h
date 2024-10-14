#ifndef PROJECTILE_TEST_H
#define PROJECTILE_TEST_H

#include <iostream>
#include "Projectile.h"

class ProjectileTest
{
public:
    void run_tests()
    {
        test_launch_projectile();
        test_update();
        test_despawn_projectile();
        test_has_collided();
    }

private:
    void test_launch_projectile()
    {
        {
            Projectile projectile(2, 2, RoomObject::circle, 10, sf::Color(255, 255, 255));
            projectile.load_object();
            projectile.launch_projectile(RoomObject::left, sf::Vector2f(25, 25));
            if (projectile.is_active() != true)
            {
                std::cout << "Test 1.1 (launch loaded projectile, is active) failed." << std::endl;
            }
            if (projectile.get_direction() != RoomObject::left)
            {
                std::cout << "Test 1.2 (launch loaded projectile, right direction) failed." << std::endl;
            }
            if (projectile.get_position() != sf::Vector2f(25, 25))
            {
                std::cout << "Test 1.3 (launch loaded projectile, attribute at position) failed." << std::endl;
            }
            if (projectile.get_body()->getPosition() != sf::Vector2f(25, 25))
            {
                std::cout << "Test 1.4 (launch loaded projectile, body at position) failed." << std::endl;
            }
        }

        {
            Projectile projectile(2, 2, RoomObject::circle, 10, sf::Color(255, 255, 255));
            projectile.launch_projectile(RoomObject::left, sf::Vector2f(25, 25));
            if (projectile.is_active() != false)
            {
                std::cout << "Test 2.1 (launch unloaded projectile, is active) failed." << std::endl;
            }
            if (projectile.get_direction() == RoomObject::left) // default is right
            {
                std::cout << "Test 2.2 (launch unloaded projectile, right direction) failed." << std::endl;
            }
            if (projectile.get_position() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 2.3 (launch unloaded projectile, attribute at position) failed." << std::endl;
            }
            if (projectile.get_body()->getPosition() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 2.4 (launch unloaded projectile, body at position) failed." << std::endl;
            }
        }
    }

    void test_update()
    {
        {
            Projectile projectile(2, 2, RoomObject::circle, 10, sf::Color(255, 255, 255));
            projectile.load_object();
            projectile.launch_projectile(RoomObject::left, sf::Vector2f(25, 25));
            projectile.update();
            if (projectile.get_turns_since_launch() != 1)
            {
                std::cout << "Test 3.1 (update projectile once, turns_since_launch) failed." << std::endl;
            }
            if (projectile.get_position() != sf::Vector2f(23, 25))
            {
                std::cout << "Test 3.2 (update projectile once, expected position) failed." << std::endl;
            }
            if (projectile.is_active() != true)
            {
                std::cout << "Test 3.3 (update projectile once, is active) failed." << std::endl;
            }
        }

        {
            Projectile projectile(2, 2, RoomObject::circle, 10, sf::Color(255, 255, 255));
            projectile.load_object();
            projectile.launch_projectile(RoomObject::left, sf::Vector2f(25, 25));
            for (int i = 0; i < 3; i++)
            {
                projectile.update();
            }
            if (projectile.get_turns_since_launch() != 3)
            {
                std::cout << "Test 4.1 (update projectile until it exceeds lifespan, turns_since_launch) failed." << std::endl;
            }
            if (projectile.get_position() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 4.2 (update projectile until it exceeds lifespan, expected position) failed." << std::endl;
            }
            if (projectile.is_active() != false)
            {
                std::cout << "Test 4.3 (update projectile until it exceeds lifespan, is active) failed." << std::endl;
            }
        }
    }
    void test_despawn_projectile()
    {
        {
            Projectile projectile(2, 2, RoomObject::circle, 10, sf::Color(255, 255, 255));
            projectile.load_object();
            projectile.launch_projectile(RoomObject::left, sf::Vector2f(25, 25));
            projectile.despawn_projectile();
            if (projectile.get_turns_since_launch() != 0)
            {
                std::cout << "Test 5.1 (despawn launched projectile, turns_since_launch) failed." << std::endl;
            }
            if (projectile.get_position() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 5.2 (update projectile until it exceeds lifespan, expected position) failed." << std::endl;
            }
            if (projectile.get_body()->getPosition() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 5.3 (update projectile until it exceeds lifespan, expected body position) failed." << std::endl;
            }
            if (projectile.is_active() != false)
            {
                std::cout << "Test 5.4 (update projectile until it exceeds lifespan, is active) failed." << std::endl;
            }
        }
    }

    void test_has_collided()
    {
        {
            Projectile projectile(2, 2, RoomObject::circle, 10, sf::Color(255, 255, 255));
            projectile.load_object();
            projectile.launch_projectile(RoomObject::left, sf::Vector2f(25, 25));
            sf::RectangleShape body1(sf::Vector2f(5, 5));
            body1.setPosition(25, 25);
            projectile.has_collided(&body1);

            if (projectile.get_position() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 6.1 (test collision, expected position) failed." << std::endl;
            }
            if (projectile.get_body()->getPosition() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 6.2 (test collision, expected body position) failed." << std::endl;
            }
            if (projectile.is_active() != false)
            {
                std::cout << "Test 6.3 (test collision, is active) failed." << std::endl;
            }
        }

        {
            Projectile projectile(2, 2, RoomObject::circle, 10, sf::Color(255, 255, 255));
            projectile.load_object();
            projectile.launch_projectile(RoomObject::left, sf::Vector2f(25, 25));
            sf::RectangleShape body1(sf::Vector2f(5, 5));
            body1.setPosition(0, 0);
            projectile.has_collided(&body1);

            if (projectile.get_position() != sf::Vector2f(25, 25))
            {
                std::cout << "Test 7.1 (test non-collision, expected position) failed." << std::endl;
            }
            if (projectile.get_body()->getPosition() != sf::Vector2f(25, 25))
            {
                std::cout << "Test 7.2 (test non-collision, expected body position) failed." << std::endl;
            }
            if (projectile.is_active() != true)
            {
                std::cout << "Test 7.3 (test non-collision, is active) failed." << std::endl;
            }
        }
    }
};

#endif