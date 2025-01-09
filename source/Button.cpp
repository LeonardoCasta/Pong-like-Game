#include "../header/Button.hpp"

Button::Button(sf::Texture &texture, sf::Font &font, std::string string, float posX, float posY, float carSize)
{
    //sprite
    this->texture = texture;
    this->body.setTexture(this->texture);
    this->body.setOrigin(this->body.getLocalBounds().width / 2.0f, this->body.getLocalBounds().height / 2.0f);
    this->body.setPosition(posX, posY);

    //text
    this->font = font;
    this->text.setFont(font); 
    this->text.setString(string);
    this->text.setCharacterSize(carSize); // in pixels, not points!
    this->text.setFillColor(sf::Color::White);
    this->text.setOrigin(this->text.getLocalBounds().width / 2.0f, this->text.getLocalBounds().height / 2.0f);
    this->text.setPosition(posX, posY);
}

Button::Button(sf::Font &font, std::string string, float posX, float posY, float carSize)
{
    //sprite
    // this->texture = texture;
    // this->body.setTexture(this->texture);
    // this->body.setOrigin(this->body.getLocalBounds().width / 2.0f, this->body.getLocalBounds().height / 2.0f);
    // this->body.setPosition(posX, posY);

    //text
    this->font = font;
    this->text.setFont(font); 
    this->text.setString(string);
    this->text.setCharacterSize(carSize); // in pixels, not points!
    this->text.setFillColor(sf::Color::White);
    this->text.setOrigin(this->text.getLocalBounds().width / 2.0f, this->text.getLocalBounds().height / 2.0f);
    this->text.setPosition(posX, posY);
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(this->body);
    window.draw(this->text);
}

void Button::update(sf::RenderWindow& window, GameState &gameState, GameState nextState)
{
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
            gameState = nextState;
    }

    //mouse over control
    if (body.getGlobalBounds().contains(mp))
    {
        this->body.setColor(sf::Color(128, 128, 128));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            gameState = nextState;
        }
    } else
    {
        this->body.setColor(sf::Color::White);
    }
}