#ifndef STRIKER_ENEMY_H
#define STRIKER_ENEMY_H

#include <Enemy.h>
#include <StrikerTarget.h>

// Represents an enemy that places a warning at a given position then strikes it with an attack after some turns.
class StrikerEnemy : public Enemy
{
private:
    StrikerTarget target;

public:
    StrikerEnemy(int level, int max_cooldown, int max_range, sf::Vector2f position);
    StrikerEnemy();
    void perform_ai(sf::Vector2f player_position);
    void update_attacks();

    void load_object();
    void unload_object();
    void draw_object(sf::RenderWindow *display);

    StrikerTarget *get_target();
};

#endif