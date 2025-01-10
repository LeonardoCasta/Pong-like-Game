#include <cstdio>
#include <iostream>
#include <utility> 
#include <memory>
#include <random>
#include <SFML/Graphics.hpp>
#include "../header/Bomb.hpp"
#include "../header/Player.hpp"
#include "../header/Collider.hpp"
#include "../header/Button.hpp"
#include "../header/GameState.hpp"

#define image "./images/galaxy.jpg"
#define buttonImage "./images/button.png"
#define fontFile "./images/PublicPixel.ttf"
#define playerImage "./images/ship_full.png"

void ballUpdate(float deltaTime, sf::CircleShape* ball, sf::Vector2f* vel, Player* player, Collider* collider, GameState &gameState);
void ResetPositions(sf::CircleShape* ball, sf::Vector2f* vel, Player* player);

int main()
{
    GameState gameState = MAIN_MENU;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong", sf::Style::Close, settings);
    
    //button & text
    sf::Texture ButtonTexture;
    if(!ButtonTexture.loadFromFile(buttonImage))
    {
        printf("Error load Button texture");
    }
    sf::Font font;
    if (!font.loadFromFile(fontFile))
    {
        printf("Error load font");
    }
    std::unique_ptr<Button> button = std::make_unique<Button>(ButtonTexture, font, "Play Game", 640.0f, 360.0f, 30.0f);

    std::unique_ptr<Button> buttonGameOver = std::make_unique<Button>(ButtonTexture, font, "Play Again", 640.0f, 270.0f, 30.0f);

    std::unique_ptr<Button> textGameOver = std::make_unique<Button>(font, "Game Over", 640.0f, 145.0f, 60.0f);

    std::unique_ptr<Button> textPressEnter = std::make_unique<Button>(font, "Press Enter to play or click Play button", 640.0f, 45.0f, 20.0f);

    std::unique_ptr<Button> textMove = std::make_unique<Button>(font, "Move with arrow keys or 'a' and 'd'", 640.0f, 75.0f, 20.0f);

    //background
    sf::Texture Background;
    if(!Background.loadFromFile(image))
    {
        printf("Error load Background texture");
    }
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(1280, 720));
    background.setTexture(&Background);
    background.setPosition(0.0f, 0.0f);

    //collider
    Collider* collider = new Collider();

    //ball
    sf::CircleShape ball(20.0f);
    ball.setOrigin(20.0f, 20.0f);
    ball.setFillColor(sf::Color::White);
    sf::Vector2f vel;

    //texture
    sf::Texture explosionTexture;
    if(!explosionTexture.loadFromFile("./images/fullAnimation.png")){
        printf("Error load explosionTexture texture");
    }
    //bomb
    std::unique_ptr<Bomb> bomb = std::make_unique<Bomb>(&explosionTexture, sf::Vector2u(4,5), 0.1f, 250.0f);

    //player
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile(playerImage)){
        printf("Error load player texture");
    }
    Player player(&playerTexture, sf::Vector2u(3,1), 600.0f);

    //delta time 
    float deltaTime = 0.0f;

    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        switch (gameState)
        {
            case MAIN_MENU:
                ResetPositions(&ball, &vel, &player);
                //update
                button->update(window, gameState, GameState::GAME);
                //draw
                window.clear();
                window.draw(background);
                textPressEnter->draw(window);
                textMove->draw(window);
                button->draw(window);
                window.display();
                break;
            case GAME:
                //update ball and player
                ballUpdate(deltaTime, &ball, &vel, &player, collider, gameState);
                player.update(deltaTime, gameState);
                //draw
                window.clear();
                window.draw(background);
                bomb->update(deltaTime, &player, window, gameState);
                window.draw(ball);
                player.draw(window);
                window.display();
                break;
            case GAME_OVER:
                ResetPositions(&ball, &vel, &player);
                //update
                buttonGameOver->update(window, gameState, GameState::GAME);
                //draw
                window.clear();
                window.draw(background);
                player.draw(window);
                bomb->update(deltaTime, &player, window, gameState);
                textPressEnter->draw(window);
                textMove->draw(window);
                textGameOver->draw(window);
                buttonGameOver->draw(window);
                window.display();
                break;
        }
    }
 
    return 0;
}

void ResetPositions(sf::CircleShape* ball, sf::Vector2f* vel, Player* player)
{
    std::random_device rd;  //seed generator
    std::mt19937 gen(rd());  // Mersenne Twister engine seeded with rd()
    std::uniform_int_distribution<> distr(500, 600); //define the range
    int x = distr(gen); //define the rand number
    int y = distr(gen); //define the rand number
    vel->x = x;
    vel->y = y;

    player->setPosition();
    ball->setPosition(640.0f, (player->body.getPosition().y) - 20);
}

void ballUpdate(float deltaTime, sf::CircleShape* ball, sf::Vector2f* vel, Player* player, Collider* collider, GameState &gameState)
{
    vel->x = vel->x + (0 * deltaTime);
    vel->y = vel->y + (0 * deltaTime);

    float posX = ball->getPosition().x + (vel->x * deltaTime);
    float posY = ball->getPosition().y + (vel->y * deltaTime);

    float radius = ball->getRadius();

    if ((ball->getPosition().x - radius) <= 0 || (ball->getPosition().x + radius) >= 1280)
    {
        vel->x = -vel->x;
    }

    if ((ball->getPosition().y - 20) <= 0)
    {
        vel->y = -vel->y;
    }

    if ((ball->getPosition().y) > (player->body.getPosition().y))
    {
        gameState = GameState::GAME_OVER;
    }

    if(collider->boxCollision(ball, player, radius))
    {
        vel->y = -vel->y;
    }

    float velX = vel->x * deltaTime;
    float velY = vel->y * deltaTime;

    ball->move(velX, velY);
}