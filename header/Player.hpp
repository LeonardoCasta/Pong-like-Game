#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
    public:
    Player(/*sf::Texture* texture, sf::Vector2u imageCount, float switchTime,*/ float speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    sf::FloatRect getBounds();

private:
    sf::RectangleShape body;
    //Animation animation;
    float speed;
};

#endif 