#include "Menu.h"

Menu::Menu(float width, float height) {
    // Load a font file (e.g., Arial or any other available font file)
    if (!font.loadFromFile("Assets/Fonts/Beyond_Wonderland.ttf")) {
        // Handle font loading error (e.g., throw exception or log error)
    }

    title.setFont(font);                         // Set font for the title
    title.setString("Spearbound");                // Set title text
    title.setCharacterSize(40);                  // Set title font size
    title.setFillColor(sf::Color::White);       // Set title color
    title.setPosition(sf::Vector2f(width / 2 - title.getGlobalBounds().width / 2, height / 8));
    // Define the menu options
    std::vector<std::string> options = { "Play", "Settings", "Exit" };

    // Set up each menu item
    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);                          // Set font
        text.setString(options[i]);                  // Set option text
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White); // Highlight first item
        text.setCharacterSize(30);                   // Set font size for menu items

        // Center each menu item horizontally
        float itemX = width / 2 - text.getGlobalBounds().width / 2;
        float itemY = height / 3 + i * 60;           // Position each item with some spacing below title
        text.setPosition(sf::Vector2f(itemX, itemY));

        menuItems.push_back(text);
    }

    selectedItemIndex = 0; // Start with the first item selected
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(title);
    // Draw each menu item to the window
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

void Menu::moveUp() {
    if (selectedItemIndex > 0) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White); // Reset color of current item
        selectedItemIndex--;                                         // Move selection up
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);   // Highlight new selection
    }
}

void Menu::moveDown() {
    if (selectedItemIndex < menuItems.size() - 1) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White); // Reset color of current item
        selectedItemIndex++;                                         // Move selection down
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);   // Highlight new selection
    }
}

int Menu::getSelectedItemIndex() const {
    return selectedItemIndex;
}
