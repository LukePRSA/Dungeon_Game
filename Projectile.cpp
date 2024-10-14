#include "Projectile.h"

// Creates a circular/square projectile.
Projectile::Projectile(int speed, int lifespan, ShapeType shape, int size, sf::Color colour) : movement_speed(speed), lifespan(lifespan), RoomObject(shape, size, colour, sf::Vector2f(-1,-1)) {}

// Creates a rectangular projectile.
Projectile::Projectile(int speed, int lifespan, int length, int width, sf::Color colour) : movement_speed(speed), lifespan(lifespan), RoomObject(length, width, colour, sf::Vector2f(-1,-1)) {}

Projectile::Projectile() : movement_speed(0), lifespan(0), RoomObject() {}

// Spawns projectile at given position in given direction.
void Projectile::launch_projectile(Rotation direction, sf::Vector2f position)
{
    if (loaded)
    {
        active = true;
        turns_since_launch = 0;

        this->position = position;
        body->setPosition(position);
        
        this->direction = direction;
        switch (direction)
        {
        case right:
            body->setRotation(0);
            break;
        case down:
            body->setRotation(90);
            break;
        case left:
            body->setRotation(180);
            break;
        case up:
            body->setRotation(270);
            break;
        }
    }
}

// Causes projectile to move based on its speed in the given direction and increase its number of turns since launch, or despawn it once it has exceeded its lifespan.
void Projectile::update()
{
    if (loaded && active)
    {
        switch (direction)
        {
        case right:
            body->move(movement_speed, 0);
            break;
        case down:
            body->move(0, movement_speed);
            break;
        case left:
            body->move(-movement_speed, 0);
            break;
        case up:
            body->move(0, -movement_speed);
            break;
        }
        position = body->getPosition();
        if (turns_since_launch >= lifespan)
        {
            despawn_projectile();
        }
        turns_since_launch++;
    }
}

// Despawns projectile by moving it off-screen and setting its position to (-1, -1).
void Projectile::despawn_projectile()
{
    active = false;
    body->setPosition(-1, -1);
    position = sf::Vector2f(-1, -1);
}

// Returns true if collided with body and active, also despawns projectile if true.
bool Projectile::has_collided(sf::Shape *body)
{
    if (loaded && active)
    {
        bool collided = this->body->getGlobalBounds().intersects(body->getGlobalBounds());
        if (collided)
        {
            despawn_projectile();
        }
        return collided;
    }
}

RoomObject::Rotation Projectile::get_direction() { return direction; }

// Changes direction of projectile. If loaded and active, it also changes its direction on the display.
void Projectile::set_direction(Rotation direction)
{
    this->direction = direction;
    if (active && loaded)
    {
        switch (direction)
        {
        case right:
            body->move(movement_speed, 0);
            break;
        case down:
            body->move(0, movement_speed);
            break;
        case left:
            body->move(-movement_speed, 0);
            break;
        case up:
            body->move(0, -movement_speed);
            break;
        }
    }
}

bool Projectile::is_active() { return active; }

bool Projectile::set_active(bool active) { this->active = active; }

int Projectile::get_movement_speed() { return movement_speed; }

void Projectile::set_movement_speed(int movement_speed) { this->movement_speed = movement_speed; }

int Projectile::get_turns_since_launch() { return turns_since_launch; }

void Projectile::set_turns_since_launch(int turns_since_launch) { this->turns_since_launch = turns_since_launch; }

int Projectile::get_lifespan() { return lifespan; }

void Projectile::set_lifespan(int lifespan) { this->lifespan = lifespan; }