#ifndef SPIKE_TRAP_H
#define SPIKE_TRAP_H

#include "Trap.h"

// Represents a trap that triggers when stepped on.
class SpikeTrap : public Trap
{
public:
    SpikeTrap(int level, int max_cooldown, sf::Vector2f position);
    SpikeTrap();
    void update_trap();
    bool is_triggered(sf::Shape *body);
    void toggle_active();
};

#endif