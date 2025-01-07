#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "../header/GameState.hpp"

class Button
{
    public:
        Button(sf::Texture &texture, sf::Font &font, std::string string, float posX, float posY, float carSize);
        Button(sf::Font &font, std::string string, float posX, float posY, float carSize);
        void draw(sf::RenderWindow &window);
        void update(sf::RenderWindow &window, GameState &gameState, GameState nextState);

    private:
        sf::Sprite body;
        sf::Texture texture;
        sf::Font font;
        sf::Text text;
        sf::Vector2f mp; //for update
};

#endif