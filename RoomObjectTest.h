#ifndef ROOM_OBJECT_TEST_H
#define ROOM_OBJECT_TEST_H

#include "RoomObject.h"
#include <iostream>

class RoomObjectTest
{
public:
    void run_tests()
    {
        test_load();
        test_unload();
        test_has_collided();
        test_set_position();
    }

private:
    void test_load()
    {
        RoomObject room_object(RoomObject::ShapeType::square, 50, sf::Color(0, 0, 0), sf::Vector2f(50, 50));
        room_object.load_object();
        if (room_object.get_body()->getPosition() != sf::Vector2f(50, 50))
        {
            std::cout << "Test 1.1 (load object, position of body) failed." << std::endl;
        }
        else
        {
            std::cout << "Test 1.1 (load object, position of body) passed." << std::endl;
        }
        if (room_object.is_loaded() != true)
        {
            std::cout << "Test 1.2 (load object, loaded attribute) failed." << std::endl;
        }
        else
        {
            std::cout << "Test 1.2 (load object, loaded attribute) passed." << std::endl;
        }
        if (room_object.get_position() != sf::Vector2f(50, 50))
        {
            std::cout << "Test 1.3 (load object, position attribute) failed." << std::endl;
        }
        else
        {
            std::cout << "Test 1.3 (load object, position attribute) passed." << std::endl;
        }
    }

    void test_unload()
    {
        RoomObject room_object(RoomObject::ShapeType::square, 50, sf::Color(0, 0, 0), sf::Vector2f(50, 50));
        room_object.load_object();
        room_object.unload_object();
        if (room_object.get_body()->getPosition() != sf::Vector2f(-1, -1))
        {
            std::cout << "Test 2.1 (unload object, position of body) failed." << std::endl;
        }
        else
        {
            std::cout << "Test 2.1 (unload object, position of body) passed." << std::endl;
        }
        if (room_object.is_loaded() != false)
        {
            std::cout << "Test 2.2 (unload object, loaded attribute) failed." << std::endl;
        }
        else
        {
            std::cout << "Test 2.2 (unload object, loaded attribute) passed." << std::endl;
        }
        if (room_object.get_position() != sf::Vector2f(50, 50))
        {
            std::cout << "Test 2.3 (unload object, position attribute) failed." << std::endl;
        }
        else
        {
            std::cout << "Test 2.3 (unload object, position attribute) passed." << std::endl;
        }
    }

    void test_has_collided()
    {
        {
            RoomObject room_object(RoomObject::ShapeType::square, 50, sf::Color(0, 0, 0), sf::Vector2f(50, 50));
            sf::CircleShape body(25);
            body.setPosition(25, 25);
            if (room_object.has_collided(&body))
            {
                std::cout << "Test 3 (collisions on unloaded object) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 3 (collisions on unloaded object) passed." << std::endl;
            }
        }

        {
            RoomObject room_object(RoomObject::ShapeType::square, 50, sf::Color(0, 0, 0), sf::Vector2f(50, 50));
            room_object.load_object();
            sf::CircleShape body(25);
            body.setPosition(25, 25);
            if (room_object.has_collided(&body) == false)
            {
                std::cout << "Test 4 (collisions on loaded object) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 4 (collisions on loaded object) passed." << std::endl;
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
            else
            {
                std::cout << "Test 5 (non-collision on loaded object) passed." << std::endl;
            }
        }
    }

    void test_set_position()
    {
        {
            RoomObject room_object(RoomObject::ShapeType::square, 50, sf::Color(0, 0, 0), sf::Vector2f(50, 50));
            room_object.set_position(sf::Vector2f(25, 25));
            if (room_object.get_position() != sf::Vector2f(25, 25))
            {
                std::cout << "Test 6.1 (changing position of unloaded object, position attribute) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 6.1 (changing position of unloaded object, position attribute) passed." << std::endl;
            }
            if (room_object.get_body()->getPosition() != sf::Vector2f(-1, -1))
            {
                std::cout << "Test 6.2 (changing position of unloaded object, body position) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 6.2 (changing position of unloaded object, body position) passed." << std::endl;
            }
        }

        {
            RoomObject room_object(RoomObject::ShapeType::square, 50, sf::Color(0, 0, 0), sf::Vector2f(50, 50));
            room_object.load_object();
            room_object.set_position(sf::Vector2f(25, 25));
            if (room_object.get_position() != sf::Vector2f(25, 25))
            {
                std::cout << "Test 7.1 (changing position of loaded object, position attribute) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 7.1 (changing position of loaded object, position attribute) passed." << std::endl;
            }
            if (room_object.get_body()->getPosition() != sf::Vector2f(25, 25))
            {
                std::cout << "Test 7.2 (changing position of loaded object, body position) failed." << std::endl;
            }
            else
            {
                std::cout << "Test 7.2 (changing position of loaded object, body position) passed." << std::endl;
            }
        }
    }
};

#endif