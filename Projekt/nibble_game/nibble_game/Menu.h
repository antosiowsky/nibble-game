#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Menu {
public:
    Menu(sf::RenderWindow& window, int width, int height);

    void draw();
    void MoveUp();
    void MoveDown();
    void IncreaseValue();
    void DecreaseValue();
    int GetPressedItem() { return selectedItemIndex; }
    int GetLives() { return lives; }
    int GetGameSpeed() { return gameSpeed; }

private:
    sf::RenderWindow& window;
    int selectedItemIndex;
    int lives;
    int gameSpeed;
    sf::Font font;
    sf::Text menu[4];
    sf::Text livesText;
    sf::Text gameSpeedText;
    std::vector<std::string> options = { "Start Game", "Game Speed", "Lives", "Exit Game" };

    void updateLivesText();
    void updateGameSpeedText();
};

#endif // MENU_H
