#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "../header/Player.hpp"
#include <iostream>

class Collider
{
    public:
        Collider();
        bool rectanglesCollision(sf::RectangleShape* first, sf::RectangleShape* second);
        bool circlesCollision(sf::CircleShape* first, sf::CircleShape* second);
        bool boxCollision(sf::CircleShape* circle, Player* player, float radius);

    private:
};

#endif