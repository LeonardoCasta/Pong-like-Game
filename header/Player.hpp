#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/GameState.hpp"

class Player
{
    public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float speed);
    void update(float deltaTime, GameState &gameState);
    void draw(sf::RenderWindow &window);
    void setPosition();
    sf::FloatRect getBounds();

    //variables
    sf::Sprite body;
    sf::IntRect uvRect;

private:
    float speed;
    float width;
    float height;
    sf::Texture* texture;
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
};

#endif 