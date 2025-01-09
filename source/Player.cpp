#include "../header/Player.hpp"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float speed)
{
    this->speed = speed;
    this->width = 100.0f;
    this->height = 25.0f;
    this->texture = texture;

    body.setTexture(*this->texture);
    body.setPosition(640.0f - this->width/2, 650.0f);

    currentImage.x = 0;
    currentImage.y = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Player::update(float deltaTime, GameState &gameState)
{
    sf::Vector2f movement(0.0f, 0.0f);

    switch(gameState)
    {
        case GAME:
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))) {
                if(body.getPosition().x <= 0){
                    movement.x = 0;
                }else{
                    movement.x -= speed * deltaTime;
                    currentImage.x = 2;
                    currentImage.y = 0;
                }
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))) {
                if((body.getPosition().x + this->width) >= 1280){
                    movement.x = 0;
                }else{
                    movement.x += speed * deltaTime;
                    currentImage.x = 1;
                    currentImage.y = 0;
                }
            } else {
                currentImage.x = 0;
                currentImage.y = 0;
            }
            uvRect.left = currentImage.x * uvRect.width;
            uvRect.top = currentImage.y * uvRect.height;
            break;
        case MAIN_MENU:
        case GAME_OVER:
            break;
    }
    
    body.setTextureRect(uvRect);

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

void Player::setPosition()
{
    body.setPosition(640.0f - this->width/2, 650.0f);
}
