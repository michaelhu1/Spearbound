#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:

    struct Controls {
        sf::Keyboard::Key up;
        sf::Keyboard::Key down;
        sf::Keyboard::Key left;
        sf::Keyboard::Key right;
        sf::Keyboard::Key slash; 
        sf::Keyboard::Key roll;
        sf::Keyboard::Key stab; 
        sf::Keyboard::Key parry; 
    };

    Player(float startx, float starty, float speed, Controls controls);

    void draw(sf::RenderWindow& window);

    void move(float dx, float dy);

    void slash();
    void roll();
    void stab();
    void parry();
    
    void update();

 
private:
    float moveSpeed;
    sf::CircleShape player;
    Controls controls;
    float hp;
    float stamina;

};

