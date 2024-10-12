#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "RoomObject.h"

// A projectile used by entities as a ranged attack to deal damage.
class Projectile : public RoomObject
{
private:
    Rotation direction = right;
    int movement_speed;
    bool active = false;
    int turns_since_launch;
    int lifespan;

public:
    Projectile(int speed, int lifespan, Shape shape, int size, sf::Color colour);
    Projectile(int speed, int lifespan, int length, int width, sf::Color colour);
    Projectile();
    void launch_projectile(Rotation direction, sf::Vector2f position);
    void update();
    void despawn_projectile();
    
    bool has_collided(sf::Shape *body);

    Rotation get_direction();
    void set_direction(Rotation direction);
    bool is_active();
    bool set_active(bool active);
    int get_movement_speed();
    void set_movement_speed(int movement_speed);
    int get_turns_since_launch();
    void set_turns_since_launch(int turns_since_launch);
    int get_lifespan();
    void set_lifespan(int lifespan);
};

#endif