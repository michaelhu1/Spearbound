#include "Player.h"
#include <iostream>

Player::Player(float startx, float starty, float speed, Controls controls)
    : moveSpeed(speed), controls(controls), currentState(IDLE), animationTimer(0.0f), animationSpeed(0.1f),
    frameWidth(96), frameHeight(96)
{
    stamina = 100;
    hp = 100;
    if (!texture.loadFromFile("Assets/Sprites/sprite_sheet.png")) {
        std::cerr << "Error: Failed to load sprite_sheet.png" << std::endl;
    }

    sprite.setTexture(texture);

    // Set the initial frame for the idle animation
    currentFrame = sf::IntRect(0, 0, frameWidth, frameHeight);
    sprite.setTextureRect(currentFrame);

    // Set the sprite's starting position
    sprite.setPosition(startx, starty);
}

void Player::setAnimationState(AnimationState newState) {
    if (newState != currentState) {
        currentState = newState;
        currentFrame.left = 0; // Start at the first frame of the row

        // Set the row (Y-coordinate) based on the animation type
        switch (currentState) {
        case IDLE:
            currentFrame.top = 4 * frameHeight;
            frameCount = 5; // Number of frames in this animation
            break;
        case WALK:
            currentFrame.top = 8 * frameHeight;
            frameCount = 6;
            break;
        case SLASH:
            currentFrame.top = 5 * frameHeight;
            frameCount = 9;
            break;
        case ROLL:
            currentFrame.top = 5 * frameHeight;
            frameCount = 8;
            break;
        case STAB:
            currentFrame.top = 0 * frameHeight;
            frameCount = 4;
            break;
        case PARRY:
            currentFrame.top = 6 * frameHeight;
            frameCount = 3;
            break;
        }

        // Update the sprite to show the correct row
        sprite.setTextureRect(currentFrame);
    }
}

void Player::updateAnimation(float deltaTime) {
    animationTimer += deltaTime;

    // Switch frame if timer exceeds animation speed
    if (animationTimer >= animationSpeed) {
        animationTimer = 0.0f;

        // Move to the next frame in the row
        currentFrame.left += frameWidth;

        // If we've reached the end of the animation frames, loop back
        if (currentFrame.left >= frameCount * frameWidth) {
            currentFrame.left = 0; // Loop to the beginning
        }

        // Set the texture rect to the updated frame
        sprite.setTextureRect(currentFrame);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

void Player::move(float dx, float dy) {
    this->sprite.move(dx, dy); // Moves the player shape
}

void Player::slash() {
    
}
void Player::roll() {

}
void Player::stab() {

}
void Player::parry() {

}

void Player::handleInput() {
    bool isMoving = false;

    // Movement and Animation Update
    if (sf::Keyboard::isKeyPressed(controls.up)) {
        sprite.move(0, -moveSpeed);
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(controls.down)) {
        sprite.move(0, moveSpeed);
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(controls.left)) {
        sprite.move(-moveSpeed, 0);
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(controls.right)) {
        sprite.move(moveSpeed, 0);
        isMoving = true;
    }

    // Action-Based Animation States
    if (sf::Keyboard::isKeyPressed(controls.slash)) {
        setAnimationState(SLASH);
    }
    else if (sf::Keyboard::isKeyPressed(controls.stab)) {
        setAnimationState(STAB);
    }
    else if (sf::Keyboard::isKeyPressed(controls.parry)) {
        setAnimationState(PARRY);
    }
    else if (sf::Keyboard::isKeyPressed(controls.roll)) {
        setAnimationState(ROLL);
    }
    else if (isMoving) {
        setAnimationState(WALK);
    }
    else {
        setAnimationState(IDLE);
    }
}


void Player::update(float deltaTime) {
    handleInput();
    updateAnimation(deltaTime);

}