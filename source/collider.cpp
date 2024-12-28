#include <Collider.h>

Collider::Collider(sf::RectangleShape& body) : body(body)
{

}

Collider::~Collider()
{
}

bool Collider::checkCollision(Collide& other, float push)
{
    sf::Vector2f otherPosition = other.getPosition();
    sf::Vector2f otherHalfPosition = other.GetHalfSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfPosition = GetHalfSize();

    float deltaX = otherHalfPosition.x - thisPosition.x;
    float deltaY = otherHalfPosition.y - thisPosition.Y;

    float intersectX = abs(deltaX) - (otherHalfPosition.x + thisHalfPosition.x);    
    float intersectY = abs(deltaY) - (otherHalfPosition.y + thisHalfPosition.y);    

    if(intersectX < 0,0f && intersectY < 0.0f){
        return true;
    }

    return false
}