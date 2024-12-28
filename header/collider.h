#include <SFML/Graphics.hpp>

class Collider
{
    public:
        Collider(sf::RectangleShape& body);
        ~Collider();

        bool Move(float dx, float dy) { body.move(dx, dy); }

        bool checkCollision(Collider& other, float push);
        sf::Vector2f GetPosition() { return body.getPosition(); }
        sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

    private:
        sf::RectangleShape& body;

}