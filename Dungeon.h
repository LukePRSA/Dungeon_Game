#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Dungeon
{
private:
sf::RenderWindow display;
bool complete;
bool failed;
std::vector<Room> rooms;
int current_room_num;

public:
Dungeon
};

#endif