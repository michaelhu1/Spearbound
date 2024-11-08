#include "Player.h"

Player::Player(float startx, float starty, float speed, Controls controls)
    : moveSpeed(speed), controls(controls) 
{
    stamina = 100;
    hp = 100;
    this->player.setPosition(startx, starty);
    this->player.setRadius(150);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(this->player);
}

void Player::move(float dx, float dy) {
    this->player.move(dx, dy); // Moves the player shape
}

void Player::slash() {
    
}
void Player::roll() {

}
void Player::stab() {

}
void Player::parry() {

}

void Player::update() {
    // WASD controls for player movement; adjust for each player instance if needed
    if (sf::Keyboard::isKeyPressed(controls.up)) player.move(0, -moveSpeed);
    if (sf::Keyboard::isKeyPressed(controls.down)) player.move(0, moveSpeed);
    if (sf::Keyboard::isKeyPressed(controls.left)) player.move(-moveSpeed, 0);
    if (sf::Keyboard::isKeyPressed(controls.right)) player.move(moveSpeed, 0);

}