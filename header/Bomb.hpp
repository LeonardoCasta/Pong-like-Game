#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
#include "../header/Animation.hpp"
#include "../header/Player.hpp"

class Bomb 
{
public:
    //methods
    Bomb(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float x);
    void update(float deltaTime, Player* player);
    void draw(sf::RenderWindow &window);
    sf::FloatRect getBounds();
    void setCollision();

    //variables
    int state = 0;

private:
    //varibles
    sf::Sprite body;
    Animation animation;
    float speed;
    float x;
};

#endif