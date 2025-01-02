#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Collider
{
    public:
        Collider();
        bool rectanglesCollision(Collider& other);
        bool circlesCollision(sf::CircleShape first, sf::CircleShape second);
        void boxCollision();

    private:
};

#endif