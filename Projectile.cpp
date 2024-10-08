#include "Projectile.h"

Projectile::Projectile(int speed, int lifespan, std::string shape, int size, sf::Vector3<short unsigned int> colour, sf::Vector2f position) : movement_speed(speed), lifespan(lifespan), Room_object(shape, size, colour, position) {}

Projectile::Projectile(int speed, int lifespan, int length, int width, sf::Vector3<short unsigned int> colour, sf::Vector2f position) : movement_speed(speed), lifespan(lifespan), Room_object(length, width, colour, position) {}

Projectile::Projectile() : movement_speed(0), lifespan(0), Room_object() {}

void Projectile::launch_projectile(int direction, sf::Vector2f position)
{
    // spawns projectile at position in given direction
    if (loaded)
    {
        active = true;
        body->setPosition(position);
        this->position = position;
        this->direction = direction;
        turns_since_launch = 0;
    }
}

void Projectile::update()
{
    // causes projectile to move based on its speed in the given direction and increase its turns, or despawn it once it has exceeded them
    if (loaded && active)
    {
        for (int i = 0; i < movement_speed / 5; i++)
        {
            switch (direction)
            {
            case 0:
                body->move(position.x + 5, position.y);
                break;
            case 90:
                body->setPosition(position.x, position.y + 5);
                break;
            case 180:
                body->setPosition(position.x - 5, position.y);
                break;
            case 270:
                body->setPosition(position.x, position.y - 5);
                break;
            }
        }
        position = body->getPosition();
        if (turns_since_launch >= lifespan)
        {
            despawn_projectile();
        }
        turns_since_launch++;
    }
}

void Projectile::despawn_projectile()
{
    // despawns projectile by moving it off-screen
    active = false;
    body->setPosition(-1, -1);
    position = body->getPosition();
}

bool Projectile::has_collided(sf::Shape *body)
{
    // overridden to only work if loaded and active and despawn the projectile if true
    if (loaded && active)
    {
        bool collided = this->body->getGlobalBounds().intersects(body->getGlobalBounds());
        if (collided)
        {
            despawn_projectile();
        }
        return collided;
    }
    return false;
}

int Projectile::get_direction() { return direction; }

void Projectile::set_direction(int direction) { this->direction = direction; }

bool Projectile::is_active() { return active; }

bool Projectile::set_active(bool active) { this->active = active; }

int Projectile::get_movement_speed() { return movement_speed; }

void Projectile::set_movement_speed(int movement_speed) { this->movement_speed = movement_speed; }

int Projectile::get_turns_since_launch() { return turns_since_launch; }

void Projectile::set_turns_since_launch(int turns_since_launch) { this->turns_since_launch = turns_since_launch; }

int Projectile::get_lifespan() { return lifespan; }

void Projectile::set_lifespan(int lifespan) { this->lifespan = lifespan; }