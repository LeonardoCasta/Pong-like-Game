#include <SFML/Graphics.hpp>

class Animation 
{
    public:
        //functions
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        ~Animation();
        void update(int row, float deltaTime);

        //variables
        sf::IntRect uvRect;
        int collision;

    private:
        //variables
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
};