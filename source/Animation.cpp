#include "../header/Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;
    currentImage.y = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);

    collision = 1;
}

void Animation::update(int row, float deltaTime)
{
    //currentImage.y = row;

    if (collision == 0)
    {
        
    }
    else if (collision == 1)
    {
        totalTime += deltaTime;

        if (totalTime >= switchTime) 
        {
            totalTime -= switchTime;
            currentImage.x++;
            
            if (currentImage.x >= imageCount.x)
            {
                currentImage.x = 0;
                currentImage.y++;

                if (currentImage.y >= imageCount.y)
                {
                    currentImage.y = 0;
                }
            }
        }
    }
        

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}

Animation::~Animation()
{

}