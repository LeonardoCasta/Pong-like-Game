#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Bomb.hpp"
#include "../header/Player.hpp"
#include "../header/Collider.hpp"

#define image "./images/galaxy.jpg"

enum GameState {
    MAIN_MENU,
    GAME,
    GAME_OVER
};

void ballUpdate(float deltaTime, sf::CircleShape* ball, sf::Vector2f* vel, Player* player, Collider* collider);
void mainMenuUpdate(sf::RectangleShape* button, sf::RenderWindow& window);

int main()
{
    GameState gameState = MAIN_MENU;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong", sf::Style::Close, settings);
    
    //button
    sf::RectangleShape button;
    button.setSize(sf::Vector2f(200, 100));
    button.setPosition(640.0f - button.getSize().x/2, 200.0f);
    button.setFillColor(sf::Color::White);
    
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
    ball.setPosition(300.0f, 300.0f);
    ball.setFillColor(sf::Color::White);
    sf::Vector2f vel= {200, 350};
    ball.move(vel);

    //texture
    sf::Texture explosionTexture;
    if(!explosionTexture.loadFromFile("./images/fullAnimation.png")){
        printf("Error load explosionTexture texture");
    }
    //bomb
    Bomb* bomb = new Bomb(&explosionTexture, sf::Vector2u(4,5), 0.1f, 250.0f);

    //player
    Player player(500.0f);

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
                case  sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        switch (gameState)
        {
            case MAIN_MENU:
                //update
                mainMenuUpdate(&button, window);

                //draw
                window.clear();
                window.draw(background);
                window.draw(button);
                window.display();
                break;
            case GAME:
                //update ball and player
                ballUpdate(deltaTime, &ball, &vel, &player, collider);
                player.update(deltaTime);
                
                //draw
                window.clear();
                window.draw(background);
                bomb->update(deltaTime, &player, window);
                window.draw(ball);
                player.draw(window);
                window.display();
                break;
            case GAME_OVER:

                break;
        }
    }
 
    return 0;
}

void ballUpdate(float deltaTime, sf::CircleShape* ball, sf::Vector2f* vel, Player* player, Collider* collider)
{
    vel->x = vel->x + (0 * deltaTime);
    vel->y = vel->y + (0 * deltaTime);

    float posX = ball->getPosition().x + (vel->x * deltaTime);
    float posY = ball->getPosition().y + (vel->y * deltaTime);

    if ((ball->getPosition().x - 20) <= 0 || (ball->getPosition().x + 20) >= 1280)
    {
        vel->x = -vel->x;
    }

    if ((ball->getPosition().y - 20) <= 0 /*|| (ball->getPosition().y + 20) >= 720*/)
    {
        vel->y = -vel->y;
    }

    if ((ball->getPosition().y + 20) >= 720)
    {
        ball->setPosition(640.0f, 200.0f);
    }

    if(collider->boxCollision(ball, player, ball->getRadius()))
    {
        vel->y = -vel->y;
    }

    // vel->x = velX;
    // vel->y = velY;

    float velX = vel->x * deltaTime;
    float velY = vel->y * deltaTime;

    ball->move(velX, velY);
}

void mainMenuUpdate(sf::RectangleShape* button, sf::RenderWindow& window)
{
    sf::Vector2f mp;
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;

    if (button->contains(mp))
    {
        button->setFillColor(sf::Color::Blue);
    } else
    {
        button->setFillColor(sf::Color::White);
    }
}