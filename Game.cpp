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
	: menu(1920, 1080), player1(100.0f, 100.0f, 5.0f, { sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T , sf::Keyboard::Y , sf::Keyboard::U }),
      player2(300.0f, 100.0f, 5.0f, { sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::V, sf::Keyboard::B , sf::Keyboard::N , sf::Keyboard::M })
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
        
            case sf::Event::KeyPressed:
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
}

void Game::update()
{
	this->pollEvents();
    if (!isInMenu) {
        float deltaTime = clock.restart().asSeconds();
        player1.update(deltaTime);
        player2.update(deltaTime);
    }

}

void Game::render()
{

    if (isInMenu) {
        this->window->clear(sf::Color::Black);
        menu.draw(*this->window); // Render menu if in menu mode
    }
    else {
        this->window->clear(sf::Color::Black);
        player1.draw(*this->window); // Draw Player 1
        player2.draw(*this->window); // Draw Player 2
    }
	this->window->display();
}