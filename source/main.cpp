#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Bomb.hpp"
#include "../header/Player.hpp"
#include "../header/Collider.hpp"
 
void ballUpdate(float deltaTime, sf::CircleShape* ball, sf::Vector2f* vel);

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong", sf::Style::Close, settings);
    window.setFramerateLimit(60); // call it once after creating the window
    
    //collider
    Collider* collider = new Collider();

    //ball
    sf::CircleShape ball(20.0f);
    ball.setOrigin(20.0f, 20.0f);
    ball.setPosition(300.0f, 300.0f);
    ball.setFillColor(sf::Color::Blue);
    sf::Vector2f vel= {5.1, 8.2};
    ball.move(vel);

    //texture
    sf::Texture explosionTexture;
    if(!explosionTexture.loadFromFile("./images/ExplosionAnimation2.png")){
        printf("Error load ball texture");
    }
    //bomb
    Bomb* bomb = new Bomb(&explosionTexture, sf::Vector2u(4,5), 0.3f, 250.0f, 600.0f);

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

        ballUpdate(deltaTime, &ball, &vel);

        player.update(deltaTime);
        bomb->update(deltaTime, &player);

        window.clear(sf::Color::White);
        window.draw(ball);
        bomb->draw(window);
        player.draw(window);
        window.display();
    }
 
    return 0;
}

void ballUpdate(float deltaTime, sf::CircleShape* ball, sf::Vector2f* vel)
{
    float velX = vel->x + (0*deltaTime);
    float velY = vel->y + (0*deltaTime);

    float posX = ball->getPosition().x + (velX * deltaTime);
    float posY = ball->getPosition().y + (velY * deltaTime);

    if ((ball->getPosition().x - 20) <= 0 || (ball->getPosition().x + 20) >= 1280)
    {
        std::cout << "Sopra";
        velX = -velX;
    }

    if ((ball->getPosition().y - 20) <= 0 /*|| (ball->getPosition().y + 20) >= 720*/)
    {
        std::cout << "Sotto";
        velY = -velY;
    }

    if ((ball->getPosition().y + 20) >= 720)
    {
        ball->setPosition(640.0f, 200.0f);
    }

    vel->x = velX;
    vel->y = velY;

    ball->move(*vel);
}
