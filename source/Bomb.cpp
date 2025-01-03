#include "../header/Bomb.hpp"

Bomb::Bomb(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->state = 0;
    this->texture = texture;
    this->totalTime = 0.0f;
    createBomb();
}

void Bomb::update(float deltaTime, Player* player, sf::RenderWindow& window)
{
    sf::Vector2f movement(0.0f, 0.0f);

    switch (state)
    {
        case 0:
            createBomb();     //create the bomb
            state = 1;
            this->totalTime = 0.0f; //reset the timer
            break;
        case 1:
            movement.y += speed * deltaTime;

            bombs.front().setTextureRect(animation.uvRect);
            bombs.front().move(movement);
            this->draw(window);

            //intersects with the player
            if (this->getBounds().intersects(player->getBounds()))
            {
                state = 2;
                this->setCollision();
            }

            //out of field
            if (this->bombs.front().getPosition().y > 900.0f)
            {
                state = 3;
            }
            break;
        case 2:
            movement.y = 0;

            bombs.front().setTextureRect(animation.uvRect);
            bombs.front().move(movement);
            this->draw(window);
            break;
        case 3:
            bombs.erase(bombs.begin());
            animation.resetAnimation();
            state = 999;
            break;
        case 999:
            this->totalTime += deltaTime;
            //after x sec creates a new bomb
            if (this->totalTime >= 5.0f)
                state = 0;
            break;
    }

    //animation is indipendent from the bomb
    animation.update(deltaTime);
}

void Bomb::createBomb()
{
    std::random_device rd;  //seed generator
    std::mt19937 gen(rd());  // Mersenne Twister engine seeded with rd()
    std::uniform_int_distribution<> distr(200, 1000); //define the range
    int random_number = distr(gen); //define the rand number

    sf::Sprite body;
    body.setScale(0.2,0.2);
    body.setTexture(*this->texture);
    body.setPosition(random_number, 50.0f);
    body.setOrigin(body.getLocalBounds().width / 2.f, body.getLocalBounds().height / 2.f);

    bombs.push_back(body);
}

void Bomb::draw(sf::RenderWindow& window)
{
    window.draw(bombs.front());
}

sf::FloatRect Bomb::getBounds()
{
    return bombs.front().getGlobalBounds();
}

void Bomb::setCollision()
{
    animation.Collision();
}