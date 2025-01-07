#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
#include "../header/Animation.hpp"
#include "../header/Player.hpp"
#include "../header/GameState.hpp"
#include <iostream>
#include <random>

class Bomb 
{
    public:
        //methods
        Bomb(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
        void update(float deltaTime, Player* player, sf::RenderWindow& window, GameState &gameState);
        void draw(sf::RenderWindow &window);
        sf::FloatRect getBounds();
        void setCollision();
        void createBomb();

        //variables
        int state = 0;

    private:
        //varibles
        std::vector<sf::Sprite> bombs;
        sf::Texture* texture;
        Animation animation;
        float speed;
        float totalTime;
};

#endif