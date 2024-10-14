#include "Trap.h"

// Creates a trap with given parameters at the given position.
Trap::Trap(int level, int damage, int max_cooldown, ShapeType shape, int width, sf::Color colour, sf::Vector2f position) : RoomObject(shape, width, colour, position), level(level), damage(damage), max_cooldown(max_cooldown) {}

// Creates a default trap off-screen.
Trap::Trap() : RoomObject(), level(0), damage(0), max_cooldown(0) {}

int Trap::get_level() { return level; }

void Trap::set_level(int level) { this->level = level; }

int Trap::get_damage() { return damage; }

void Trap::set_damage(int damage) { this->damage = damage; }

int Trap::get_max_cooldown() { return max_cooldown; }

void Trap::set_max_cooldown(int cooldown) { max_cooldown = cooldown; }

int Trap::get_cooldown() { return cooldown; }

void Trap::set_cooldown(int cooldown) { this->cooldown = cooldown; }

bool Trap::is_active() { return active; }

void Trap::set_active(bool active) { this->active = active; }