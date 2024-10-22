#include "StrikerTarget.h"

// Creates a translucent StrikerTarget off-screen for StrikerEnemy.
StrikerTarget::StrikerTarget() : RoomObject(circle, 65, sf::Color(255, 255, 255, 127), sf::Vector2f(-100, -100))
{
    body->setOutlineColor(sf::Color(255, 255, 255, 127));
    body->setOutlineThickness(0);
}

// Places a yellow target at position and starts a countdown from 3.
void StrikerTarget::place_target(sf::Vector2f position)
{
    if (loaded)
    {
        body->setPosition(position);
        this->position = position;
        body->setFillColor(sf::Color(255, 255, 0, 127));
        body->setOutlineThickness(0);
        attack_countdown = 3;
        active = true;
    }
}

// Decreases countdown by 1 and changes its colour. Allows it to deal damage at 0 and removes it if below 0.
void StrikerTarget::update_target()
{
    if (active && loaded)
    {
        attack_countdown--;
        if (attack_countdown >= 3)
        {
            body->setFillColor(sf::Color(255, 255, 0, 127));
        }
        else if (attack_countdown == 2)
        {
            body->setFillColor(sf::Color(255, 127, 0, 127));
        }
        else if (attack_countdown == 1)
        {
            body->setFillColor(sf::Color(255, 0, 0, 127));
        }
        else if (attack_countdown == 0)
        {
            body->setFillColor(sf::Color(127, 0, 0, 127));
            body->setOutlineThickness(1);
            deal_damage = true;
        }
        else
        {
            remove_target();
        }
    }
}

// Removes target by moving it off screen and deactivating it.
void StrikerTarget::remove_target()
{
    body->setPosition(-100, -100);
    position = body->getPosition();
    active = false;
    deal_damage = false;
}

// Returns body if loaded and alive.
std::vector<sf::Shape *> StrikerTarget::get_draw_objects()
{
    std::vector<sf::Shape *> drawable_objects;
    if (loaded && active)
    {
        drawable_objects.push_back(body);
    }
    return drawable_objects;
}

bool StrikerTarget::is_active() { return active; }

void StrikerTarget::set_active(bool active) { this->active = active; }

bool StrikerTarget::can_deal_damage() { return deal_damage; }

void StrikerTarget::set_deal_damage(bool deal_damage) { this->deal_damage = deal_damage; }

int StrikerTarget::get_attack_countdown() { return attack_countdown; }

void StrikerTarget::set_attack_countdown(int countdown) { attack_countdown = countdown; }