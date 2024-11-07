#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow() 
{
	this->videoMode.height = 900;
	this->videoMode.width = 1600;
	this->window = new sf::RenderWindow(this->videoMode, "Spearbound", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(120);
}

void Game::initOpponents()
{
	//this->opponent.setPosition();
	this->opponent.setSize(sf::Vector2f(100.f, 100.f));
	this->opponent.setFillColor(sf::Color::Red);
	this->opponent.setOutlineColor(sf::Color::Blue);
	this->opponent.setOutlineThickness(1.f);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initOpponents();
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
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
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
	this->window->draw(this->opponent);
	this->window->display();
}