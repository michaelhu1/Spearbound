#include "Menu.h"

Menu::Menu(float width, float height) {
    // Load a font file (e.g., Arial or any other available font file)
    if (!font.loadFromFile("Assets/Fonts/Beyond_Wonderland.ttf")) {
        // Handle font loading error (e.g., throw exception or log error)
    }

    // Define the menu options
    std::vector<std::string> options = { "Play", "Settings", "Exit" };

    // Set up each menu item
    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);                          // Set font
        text.setString(options[i]);                  // Set option text
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White); // Highlight first item
        text.setPosition(sf::Vector2f(width / 2, height / (options.size() + 1) * (i + 1))); // Position

        menuItems.push_back(text);
    }

    selectedItemIndex = 0; // Start with the first item selected
}

void Menu::draw(sf::RenderWindow& window) {
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
