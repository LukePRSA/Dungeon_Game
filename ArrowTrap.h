#ifndef ARROW_TRAP_H
#define ARROW_TRAP_H

#include "Trap.h"
#include "Projectile.h"

extern const int TILE_SIZE_TO_PIXELS;

// Represents a trap that passively shoots arrows in a specific direction.
class ArrowTrap : public Trap
{
private:
    Projectile arrows[5] = {{TILE_SIZE_TO_PIXELS, 5, 35, 10, sf::Color(97, 64, 46)}, {TILE_SIZE_TO_PIXELS, 5, 50, 20, sf::Color(97, 64, 46)}, {TILE_SIZE_TO_PIXELS, 5, 50, 20, sf::Color(97, 64, 46)}, {TILE_SIZE_TO_PIXELS, 5, 50, 20, sf::Color(97, 64, 46)}, {TILE_SIZE_TO_PIXELS, 5, 50, 20, sf::Color(97, 64, 46)}};
    Rotation direction;
    int projectile_speed;

public:
    ArrowTrap(int level, int max_cooldown, int projectile_speed, Rotation direction, sf::Vector2f position);
    ArrowTrap();
    void update_trap();
    bool is_triggered(sf::Shape *body);
    void toggle_active();

    void load_object();
    void unload_object();
    void draw_object(sf::RenderWindow* display);

    Projectile *get_arrow();
    Rotation get_direction();
    void set_direction(Rotation direction);
    int get_speed();
    void set_speed(int speed);
};

#endif