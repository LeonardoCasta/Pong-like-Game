#include "../header/Collider.hpp"

Collider::Collider()
{
}

bool Collider::rectanglesCollision(sf::RectangleShape* first, sf::RectangleShape* second)
{
    //da fare bene
    // sf::Vector2f secondPosition = second->getPosition();
    // sf::Vector2f secondHalfPosition = second->GetHalfSize();
    // sf::Vector2f firstPosition = first->getPosition();
    // sf::Vector2f firstHalfPosition = first->GetHalfSize();

    // float deltaX = secondHalfPosition.x - firstPosition.x;
    // float deltaY = secondHalfPosition.y - firstPosition.y;

    // float intersectX = abs(deltaX) - (secondHalfPosition.x + firstHalfPosition.x);    
    // float intersectY = abs(deltaY) - (secondHalfPosition.y + firstHalfPosition.y);    

    // if(intersectX < 0.0f && intersectY < 0.0f){
    //     return true;
    // }

    return false;
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

bool Collider::boxCollision(sf::CircleShape* circle, Player* player, float radius)
{
    float cx = circle->getPosition().x;      // circle position (set with mouse)
    float cy = circle->getPosition().y;
    float r = radius;                        // circle radius

    float rx = player->body.getPosition().x;    // square position
    float ry = player->body.getPosition().y;
    float rw = player->body.getPosition().x + player->body.getSize().x;    // and dimensions
    //float rh = player->body.getPosition().y + player->body.getSize().y;
    float rh = player->body.getPosition().y + 1;

    // temporary variables to set edges for testing
    float testX = cx;
    float testY = cy;

    // which edge is closest?
    if (cx < rx){
        testX = rx;      // test left edge
    }
    else if (cx > rx+rw)
    {
        testX = rx+rw;   // right edge
    }         
    
    if (cy < ry)
    {
        testY = ry;      // top edge
    }
    else if (cy > ry+rh)
    {
        testY = ry+rh;   // bottom edge
    } 
    
    // get distance from closest edges
    float distX = cx-testX;
    float distY = cy-testY;
    float distance = sqrt( (distX*distX) + (distY*distY) );

    // if the distance is less than the radius, collision!
    if (distance <= radius) {
      return true;
    }
    return false;


}