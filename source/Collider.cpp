#include <../header/Collider.hpp>

Collider::Collider()
{
}

bool Collider::rectanglesCollision(sf::RectangleShape* first, sf::RectangleShape* second)
{
    sf::Vector2f secondPosition = second->getPosition();
    sf::Vector2f secondHalfPosition = second->GetHalfSize();
    sf::Vector2f firstPosition = first->getPosition();
    sf::Vector2f firstHalfPosition = first->GetHalfSize();

    float deltaX = secondHalfPosition.x - firstPosition.x;
    float deltaY = secondHalfPosition.y - firstPosition.Y;

    float intersectX = abs(deltaX) - (secondHalfPosition.x + firstHalfPosition.x);    
    float intersectY = abs(deltaY) - (secondHalfPosition.y + firstHalfPosition.y);    

    if(intersectX < 0,0f && intersectY < 0.0f){
        return true;
    }

    return false
}

bool Collider::circlesCollision(sf::CircleShape* first, sf::CircleShape* second)
{
    sf::FloatRect shape1 = first->getGlobalBounds();
    sf::FloatRect shape2 = second->getGlobalBounds();

    float dx = (first->getPosition().x + (shape1.width / 2) - second->getPosition().x + (shape2.width /2)); 
    float dy = (first->getPosition().y + (shape1.height / 2) - second->getPosition().y + (shape2.height /2)); 

    float distance = std::sqrt((dx * dx) + (dy * dy));

    if (distance <= ((shape1.width / 2) * (shape2.width / 2)))
    {
        return true;
    }

    return false;
}

void Collider::boxCollision(sf::CircleShape* circle, sf::RectangleShape* rectangle, float radius)
{
    float cx = circle->getPosition().x;      // circle position (set with mouse)
    float cy = circle->getPosition().y;
    float r = radius;                        // circle radius

    float sx = 200;    // square position
    float sy = 100;
    float sw = 200;    // and dimensions
    float sh = 200;
}