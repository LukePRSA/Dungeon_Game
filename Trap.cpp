#include "Trap.h"

Trap::Trap(int level, int damage, int max_cooldown, Shape shape, int width, sf::Color colour, sf::Vector2f position) : level(level), damage(damage), max_cooldown(max_cooldown), RoomObject(shape, width, colour, position) {}

Trap::Trap() : level(0), damage(0), max_cooldown(0), RoomObject() {}

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