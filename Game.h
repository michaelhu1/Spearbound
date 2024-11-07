#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu.h"


class Game
{
private:
	//Variables
	bool isInMenu;

	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	Menu menu;

	//Game objects
	sf::RectangleShape opponent;

	//Private functions
	void initVariables();
	void initWindow();


public:
	Game();
	virtual ~Game();

	const bool getWindowIsOpen() const;

	void pollEvents();
	void update();
	void render();
};

