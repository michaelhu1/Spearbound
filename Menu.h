#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu 
{
public:
    // Constructor: initializes menu items based on window dimensions
    Menu(float width, float height);

    // Draws the menu items on the given window
    void draw(sf::RenderWindow& window);

    // Move the selection up in the menu
    void moveUp();

    // Move the selection down in the menu
    void moveDown();

    // Returns the index of the currently selected item
    int getSelectedItemIndex() const;

private:
    int selectedItemIndex;              // Index of the currently selected menu item
    sf::Font font;                      // Font for menu text
    std::vector<sf::Text> menuItems;    // List of menu items
};

