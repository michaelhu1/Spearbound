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
        sf::Keyboard::Key stab;
        sf::Keyboard::Key parry; 
        sf::Keyboard::Key roll;
    };
    enum AnimationState { IDLE, WALK, SLASH, ROLL, STAB, PARRY };
    void setAnimationState(AnimationState newState);

    Player(float startx, float starty, float speed, Controls controls);

    void draw(sf::RenderWindow& window);

    void move(float dx, float dy);

    void slash();
    void roll();
    void stab();
    void parry();

    void handleInput();
    
    void update(float deltaTime);

 
private:
    float moveSpeed;
    Controls controls;
    float hp;
    float stamina;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect currentFrame;

    AnimationState currentState; // Current animation state
    float animationTimer;
    float animationSpeed;
    int frameCount;    // Number of frames in the current animation
    int frameHeight;   // Height of a single frame
    int frameWidth;    // Width of a single frame

    void updateAnimation(float deltaTime); // Internal method to update animation frames

};

