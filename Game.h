#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//Game objects
	sf::RectangleShape opponent;

	//Private functions
	void initVariables();
	void initWindow();
	void initOpponents();


public:
	Game();
	virtual ~Game();

	const bool getWindowIsOpen() const;

	void pollEvents();
	void update();
	void render();
};

