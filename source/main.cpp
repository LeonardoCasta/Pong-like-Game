#include <cstdio>
#include <SFML/Graphics.hpp>
#include "../header/Bomb.hpp"
#include "../header/Player.hpp"
 
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong", sf::Style::Close, settings);
    //window.setFramerateLimit(60); // call it once after creating the window

    //ball
    sf::CircleShape ball(20.0f);
    ball.setPosition(300.0f, 300.0f);
    ball.setFillColor(sf::Color::Blue);

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
            switch(event.type){
                case  sf::Event::Closed:
                    window.close();
                    break;
            }
        }

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
