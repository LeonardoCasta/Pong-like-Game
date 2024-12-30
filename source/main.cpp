#include <cstdio>
#include <SFML/Graphics.hpp>
#include "../header/Animation.h"
 
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong", sf::Style::Close, settings);
    window.setFramerateLimit(60); // call it once after creating the window

    //Player
    //sf::Sprite player;
    sf::RectangleShape player(sf::Vector2f(100.0f, 25.0f));
    player.setPosition(840.0f, 300.0f);
    player.setFillColor(sf::Color::Blue);
 
    //ball
    sf::CircleShape ball(20.0f);
    ball.setPosition(300.0f, 300.0f);
    ball.setFillColor(sf::Color::Blue);

    //bomb
    //sf::RectangleShape bomb(sf::Vector2f(100.0f, 100.0f));
    sf::Sprite bomb;
    bomb.setScale(0.1,0.1);
    bomb.setPosition(600.0f, 300.0f);

    //texture
    sf::Texture explosionTexture;
    if(!explosionTexture.loadFromFile("./images/ExplosionAnimation.png")){
        printf("Error load ball texture");
    }
    
    sf::Texture bombTexture;
    if(!bombTexture.loadFromFile("./images/bombNoB.png")){
        printf("Error load ball texture");
    }
    bomb.setTexture(explosionTexture);

    //create the animation object
    Animation animation(&explosionTexture, sf::Vector2u(4, 4), 0.1f);
    //delta time 
    float deltaTime = 0.0f;

    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case  sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))){
            player.move(-15.0f, 0.0f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))){
            player.move(15.0f, 0.0f);
        }

        if(player.getGlobalBounds().intersects(bomb.getGlobalBounds()))
        {
            
        }

        //bomb movement, if bomb hits player explodes animation and game over
        //bomb.move(0.0f, 2.0f);

        animation.update(2, deltaTime);
        bomb.setTextureRect(animation.uvRect);

        window.clear(sf::Color::White);
        window.draw(player);
        window.draw(ball);
        window.draw(bomb);
        window.display();
    }
 
    return 0;
}
