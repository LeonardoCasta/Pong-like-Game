#include "../header/Bomb.hpp"

Bomb::Bomb(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float x) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->x = x;
    this->state = 0;

    body.setScale(0.2,0.2);
    body.setPosition(x, 100.0f);
    body.setTexture(*texture);
    body.setOrigin(body.getLocalBounds().width / 2.f, body.getLocalBounds().height / 2.f);
}

void Bomb::update(float deltaTime, Player* player)
{
    sf::Vector2f movement(0.0f, 0.0f);

    switch (state)
    {
        case 0:
            movement.y += speed * deltaTime;
            if (this->getBounds().intersects(player->getBounds()))
            {
                state++;
                this->setCollision();
            }

            // if (this->body.getPosition().y > 750.0f)
            // {
            //     delete this;
            // }
            break;
        case 1:
            movement.y = 0;
            break;
    }

    animation.update(deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

void Bomb::draw(sf::RenderWindow& window)
{
    window.draw(body);
}

sf::FloatRect Bomb::getBounds()
{
    return body.getGlobalBounds();
}

void Bomb::setCollision()
{
    animation.Collision();
}