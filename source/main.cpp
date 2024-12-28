#include <SFML/Graphics.hpp>
 
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong", sf::Style::Close, settings);
    window.setFramerateLimit(60); // call it once after creating the window
    // window.setFillColor(sf::Color::Blue);

    //Player
    sf::RectangleShape player(sf::Vector2f(150.0f, 20.0f));
    player.setFillColor(sf::Color::White);
    player.setOrigin(75.0f, 10.0f);
    player.setPosition(640.0f, 680.0f);
 
    //ball
    sf::CircleShape ball(20.0f);
    ball.setPosition(300.0f, 300.0f);


    //bomb
    sf::RectangleShape bomb(sf::Vector2f(100.0f, 100.0f));
    bomb.setPosition(600.0f, 300.0f);

    //texture
    sf::Texture bombTexture;
    if(!bombTexture.loadFromFile("bombNoB.png")){
        printf("Error load ball texture");
    }
    bomb.setTexture(&bombTexture);
    //test in case we need to cut a texture
    //sf::Vector2u textureSize = bombTexture.getSize();
    // textureSize.x /= 2;
    // textureSize.y /= 4;
    //player.setTextureRect(sf::IntRect(0,0, textureSize.x, textureSize.y));

    //bomb.setTextureRect(sf::IntRect({10, 10}, {100, 100}));

    while (window.isOpen())
    {
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

        //bomb movement, if bomb hits player explodes animation and game over
        bomb.move(0.0f, 2.0f);

        window.clear();
        window.draw(player);
        window.draw(ball);
        window.draw(bomb);
        window.display();
    }
 
    return 0;
}
