#include "../header/Animation.hpp"
#include "iostream"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    this->totalTime = 0.0f;
    currentImage.x = 0;
    currentImage.y = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);

    state = 0;
}

void Animation::update(float deltaTime)
{
    switch (state){
        case 0: //not hit the player 
            currentImage.x = 0;
            currentImage.y = 4;
            break;
        case 1: //hit the player
            this->totalTime += deltaTime;
            if (this->totalTime >= this->switchTime) 
            {
                this->totalTime -= this->switchTime;
                currentImage.x++;
                
                if (currentImage.x >= imageCount.x)
                {
                    currentImage.x = 0;
                    currentImage.y++;

                    if (currentImage.y >= imageCount.y-1)
                    {
                        currentImage.x = 3;
                        currentImage.y = 4;
                        state++; //animation ended
                    }
                }
            }
            break;
        case 2: //end of animation
            currentImage.x = 3;
            currentImage.y = 4;
            break;
    }

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}

void Animation::Collision()
{
    state = 1;
    currentImage.x = 0;
    currentImage.y = 0;
}

void Animation::resetAnimation()
{
    state = 0;
    currentImage.x = 0;
    currentImage.y = 4;
}

bool Animation::animationEnded()
{
    return state == 2;
}