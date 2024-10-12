#include "ArrowTrap.h"

ArrowTrap::ArrowTrap(int level, int max_cooldown, Rotation direction, sf::Vector2f position) : direction(direction), Trap(level, level * 4, max_cooldown, square, 45, sf::Color(150, 150, 150), position)
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

ArrowTrap::ArrowTrap() : direction(right), Trap() {}

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
    else if (active = false)
    {
        active = true;
        cooldown = 0;
        body->setFillColor(sf::Color(150, 150, 150));
    }
}

Projectile *ArrowTrap::get_arrow() { return arrows; }

Rotation ArrowTrap::get_direction() { return direction; }

void ArrowTrap::set_direction(Rotation direction) { this->direction = direction; }