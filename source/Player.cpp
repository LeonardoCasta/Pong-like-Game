#include "../header/Player.hpp"

Player::Player(/*sf::Texture* texture, sf::Vector2u imageCount, float switchTime,*/ float speed)/* : animation(texture, imageCount, switchTime)*/
{
    this->speed = speed;
    this->width = 100.0f;
    this->height = 25.0f;

    body.setSize(sf::Vector2f(this->width, this->height));
    body.setPosition(640.0f - this->width/2, 650.0f);
    body.setFillColor(sf::Color::White);
}

void Player::update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
    {
            movement.x -= speed * deltaTime;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
    {
            movement.x += speed * deltaTime;
    }

    body.move(movement);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(body);
}

sf::FloatRect Player::getBounds()
{
    return body.getGlobalBounds();
}

