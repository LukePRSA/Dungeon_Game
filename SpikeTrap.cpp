#include "SpikeTrap.h"

// Creates a grey spike trap with given parameters at the given position.
SpikeTrap::SpikeTrap(int level, int max_cooldown, sf::Vector2f position) : Trap(level, level * 8, max_cooldown, square, 58, sf::Color(50, 50, 50), position) {}

// Creates an inactive spike trap off-screen.
SpikeTrap::SpikeTrap() : SpikeTrap(0, 0, sf::Vector2f(-1, -1))
{
    toggle_active();
}

// Decreases positive cooldowns by one and reactivates it if cooldown is 0.
void SpikeTrap::update_trap()
{
    if (active)
    {
        if (cooldown == 0)
        {
            body->setFillColor(sf::Color(50, 50, 50));
        }
        if (cooldown >= 0)
        {
            cooldown--;
        }
    }
}

// Returns true if loaded, active and has collided with given body and goes on cooldown.
bool SpikeTrap::is_triggered(sf::Shape *body)
{
    if (loaded && active && cooldown <= 0 && has_collided(body))
    {
        body->setFillColor(sf::Color(127, 127, 127));
        cooldown = max_cooldown;
        return true;
    }
    return false;
}

// Toggles active. If deactivated, darkens colour. If activated, lightens colour and sets cooldown to zero.
void SpikeTrap::toggle_active()
{
    if (active)
    {
        active = false;
        body->setFillColor(sf::Color(25, 25, 25));
    }
    else if (active = false)
    {
        active = true;
        cooldown = 0;
        update_trap();
    }
}