#include "Menu.h"

Menu::Menu(sf::RenderWindow& window, int width, int height)
    : window(window), selectedItemIndex(0), lives(1), gameSpeed(1) {
    if (!font.loadFromFile("minecraft.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
    }

    for (int i = 0; i < 4; i++) {
        menu[i].setFont(font);
        menu[i].setFillColor(sf::Color::White);
        menu[i].setString(options[i]);
        menu[i].setPosition(sf::Vector2f(width / 2, height / 4 + i * 50));
    }

    gameSpeedText.setFont(font);
    gameSpeedText.setFillColor(sf::Color::White);
    gameSpeedText.setPosition(sf::Vector2f(width / 2 + 200, height / 4 + 50));
    updateGameSpeedText();

    livesText.setFont(font);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(sf::Vector2f(width / 2 + 200, height / 4 + 100));
    updateLivesText();

}

void Menu::draw() {
    window.clear();

    for (int i = 0; i < 4; i++) {
        window.draw(menu[i]);
    }

    window.draw(livesText);
    window.draw(gameSpeedText);

    window.display();
}

void Menu::MoveUp() {
    if (selectedItemIndex > 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown() {
    if (selectedItemIndex < 3) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::IncreaseValue() {
    if (selectedItemIndex == 1) {
        if (gameSpeed < 30) {
            gameSpeed++;
            updateGameSpeedText();
        }
    }
    else if (selectedItemIndex == 2) {
        if (lives < 15) {
            lives++;
            updateLivesText();
        }
    }
}

void Menu::DecreaseValue() {
    if (selectedItemIndex == 1) {
        if (gameSpeed > 1) {
            gameSpeed--;
            updateGameSpeedText();
        }
    }
    else if (selectedItemIndex == 2) {
        if (lives > 1) {
            lives--;
            updateLivesText();
        }
    }
}

void Menu::updateLivesText() {
    livesText.setString(std::to_string(lives));
}

void Menu::updateGameSpeedText() {
    gameSpeedText.setString(std::to_string(gameSpeed));
}

int Menu::GetPressedItem() {
    return selectedItemIndex;
}

int Menu::GetLives() {
    return lives;
}

int Menu::GetGameSpeed() {
    return gameSpeed;
}