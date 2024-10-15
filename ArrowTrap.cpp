#include "ArrowTrap.h"

// Creates a light grey arrow trap that shoots arrows in the given direction from the given position.
ArrowTrap::ArrowTrap(int level, int max_cooldown, int projectile_speed, Rotation direction, sf::Vector2f position) : Trap(level, level * 3, max_cooldown, square, 45, sf::Color(150, 150, 150), position), direction(direction), projectile_speed(projectile_speed)
{
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

// Creates an inactive arrow trap off-screen in the right direction.
ArrowTrap::ArrowTrap() : ArrowTrap(0, 0, 0, right, sf::Vector2f(-1, -1))
{
    toggle_active();
}

// Updates all active arrows, decreases cooldown if above 0, else launches arrow and resets cooldown.
void ArrowTrap::update_trap()
{
    if (loaded && active)
    {
        if (cooldown > 0)
        {
            cooldown--;
        }
        else
        {
            cooldown = max_cooldown;
            for (int i = 0; i < 5; i++)
            {
                if (arrows[i].is_active() == false)
                {
                    arrows[i].launch_projectile(direction, position);
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            arrows[i].update();
        }
    }
}

// Returns true if any active arrows have hit the given body.
bool ArrowTrap::is_triggered(sf::Shape *body)
{
    if (active && loaded)
    {
        bool has_hit = false;
        for (int i = 0; i < 5; i++)
        {
            if (arrows[i].has_collided(body))
            {
                has_hit = true;
            }
        }
        return has_hit;
    }
    return false;
}

// Toggles active state. If deactivated, darkens colour and despawns projectiles. If reactivated, cooldown is set to 0 and brightens colour.
void ArrowTrap::toggle_active()
{
    if (active)
    {
        active = false;
        body->setFillColor(sf::Color(25, 25, 25));
        for (int i = 0; i < 5; i++)
        {
            arrows[i].despawn_projectile();
        }
    }
    else if (active == false)
    {
        active = true;
        cooldown = 0;
        body->setFillColor(sf::Color(150, 150, 150));
    }
}

// Loads arrow trap and its arrows.
void ArrowTrap::load_object()
{
    Trap::load_object();
    for (int i = 0; i < 5; i++)
    {
        arrows[i].load_object();
    }
}

// Unloads arrow trap and its arrows.
void ArrowTrap::unload_object()
{
    Trap::unload_object();
    for (int i = 0; i < 5; i++)
    {
        arrows[i].unload_object();
    }
}

// Draws arrow trap and its arrows.
void ArrowTrap::draw_object(sf::RenderWindow *display)
{
    Trap::draw_object(display);
    for (int i = 0; i < 5; i++)
    {
        arrows[i].draw_object(display);
    }
}

Projectile *ArrowTrap::get_arrow() { return arrows; }

RoomObject::Rotation ArrowTrap::get_direction() { return direction; }

void ArrowTrap::set_direction(Rotation direction) { this->direction = direction; }

int ArrowTrap::get_speed() { return projectile_speed; }

void ArrowTrap::set_speed(int speed) { projectile_speed = speed; }