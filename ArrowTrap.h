#ifndef ARROW_TRAP_H
#define ARROW_TRAP_H

#include "Trap.h"
#include "Projectile.h"

// Represents a trap that passively shoots arrows in a specific direction.
class ArrowTrap : public Trap
{
private:
Projectile arrows[5] = {{58, 5, 35, 10, sf::Color(97, 64, 46)}, {58, 5, 50, 20, sf::Color(97, 64, 46)}, {58, 5, 50, 20, sf::Color(97, 64, 46)}, {58, 5, 50, 20, sf::Color(97, 64, 46)}, {58, 5, 50, 20, sf::Color(97, 64, 46)}};
Rotation direction;
public:
ArrowTrap(int level, int max_cooldown, Rotation direction, sf::Vector2f position);
ArrowTrap();
void update_trap();
bool is_triggered(sf::Shape *body);
void toggle_active();

Projectile* get_arrow();
Rotation get_direction();
void set_direction(Rotation direction);
};

#endif