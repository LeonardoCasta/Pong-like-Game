#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Collider
{
    public:
        Collider();
        bool rectanglesCollision(Collider& other);
        bool circlesCollision(sf::CircleShape first, sf::CircleShape second)

    private:
}

#endif