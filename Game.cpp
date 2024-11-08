#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
	this->isInMenu = true;
}

void Game::initWindow() 
{
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new sf::RenderWindow(this->videoMode, "Spearbound", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(120);
}


Game::Game()
	: menu(1600, 900) 
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::pollEvents() 
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        }

        if (isInMenu) {
            if (this->ev.key.code == sf::Keyboard::Up) {
                menu.moveUp();
            }
            else if (this->ev.key.code == sf::Keyboard::Down) {
                menu.moveDown();
            }
            else if (this->ev.key.code == sf::Keyboard::Enter) {
                int selectedItem = menu.getSelectedItemIndex();
                if (selectedItem == 0) {
                    isInMenu = false; // Start the game
                }
                else if (selectedItem == 1) {
                        // Go to settings (optional implementation)
                }
                else if (selectedItem == 2) {
                    window->close();
                }
            }
        }

        
    }
}

void Game::update()
{
	this->pollEvents();

}

void Game::render()
{
	this->window->clear();
    if (isInMenu) {
        menu.draw(*this->window); // Render menu if in menu mode
    }
	this->window->display();
}