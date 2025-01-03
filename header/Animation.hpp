#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation 
{
    public:
        //functions
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        void update(float deltaTime);
        void Collision();
        void resetAnimation();

        //variables
        sf::IntRect uvRect;
        

    private:
        //variables
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
        int state;
};

#endif