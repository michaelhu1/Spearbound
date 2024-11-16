#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu.h"
#include "Player.h"


class Game
{
private:
	//Variables
	bool isInMenu;
	Player player1;
	Player player2;
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	Menu menu;
	sf::Clock clock;

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

