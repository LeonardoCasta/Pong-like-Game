#include "../header/Collider.hpp"

Collider::Collider()
{
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
    float rw = player->body.getPosition().x + 100.0f;    // and dimensions
    float rh = player->body.getPosition().y + 25.0f;

    if(!(cx >= rx && cx <= rw)){  //if not over the bar skipp the control
        return false;
    }

    if(cy+radius < ry){
        return false;
    }
    
    float distance = abs(cy - ry);

    // if the distance is less than the radius, collision!
    if (distance <= radius) {
      return true;
    }
    return false;


}