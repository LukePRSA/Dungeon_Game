#ifndef HEALTH_CONSUMABLE_TEST_H
#define HEALTH_CONSUMABLE_TEST_H

#include "HealthConsumable.h"
#include <iostream>

class HealthConsumable
{
public:
    void run_tests()
    {
    }

private:
    void test_destroy_consumable()
    {
        {
        }
    }

    void test_has_collided()
    {
        {
            HealthConsumable consumable(0, sf::Vector2f(50, 50));
            consumable.load_object();
            sf::CircleShape body(25);
            body.setPosition(25, 25);
            if (consumable.has_collided(&body) == false)
            {
                std::cout << "Test 4 (collisions on loaded object) failed." << std::endl;
            }
        }

        {
            RoomObject room_object(RoomObject::ShapeType::square, 50, sf::Color(0, 0, 0), sf::Vector2f(50, 50));
            sf::CircleShape body(10);
            body.setPosition(100, 100);
            if (room_object.has_collided(&body))
            {
                std::cout << "Test 5 (non-collision on loaded object) failed." << std::endl;
            }
        }
    }
};

#endif