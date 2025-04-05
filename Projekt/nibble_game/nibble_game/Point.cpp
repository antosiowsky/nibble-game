#include "point.h"
#include <random>
#include <iostream>

Point::Point(float thickness, float frameWidth, float frameHeight, const Snake& snake)
    : Object(frameWidth, frameHeight, thickness) {
    font.loadFromFile("minecraft.ttf");
    shape.setFont(font);
}

bool Point::checkCollision(const Snake& snake, const std::vector<Obstacle>& obstacles) {
    sf::FloatRect pointBounds = shape.getGlobalBounds();
    for (const auto& segment : snake.getSegments()) {
        sf::FloatRect segmentBounds = segment.getGlobalBounds();
        if (pointBounds.intersects(segmentBounds)) {
            
            generatePoint(thickness, this->x, this->y, snake, obstacles);
            return true;
        }
    }
    return false;
}

void Point::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

void Point::generatePoint(float thickness, float frameWidth, float frameHeight, const Snake& snake, const std::vector<Obstacle>& obstacles) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(2, (int)((frameWidth - 4 * thickness) / thickness)); // Zmiana zakresu dla X
    std::uniform_int_distribution<int> disY(2, (int)((frameHeight - 4 * thickness) / thickness)); // Zmiana zakresu dla Y

    bool validPosition = false;
    while (!validPosition) {
        validPosition = true;
        int x = disX(gen) * thickness + thickness; // Dodanie dodatkowego odstêpu od obramowania
        int y = disY(gen) * thickness + thickness; // Dodanie dodatkowego odstêpu od obramowania
        position.x = x;
        position.y = y;
        for (const auto& segment : snake.getSegments()) {
            sf::FloatRect segmentBounds = segment.getGlobalBounds();
            if (segmentBounds.contains(position)) {
                validPosition = false;
                break;
            }
        }
        for (const auto& obstacle : obstacles) {
            if (obstacle.checkCollision(position)) {
                validPosition = false;
                break;
            }
        }
    }
    
    if (i == 58) i = 49;

    shape.setCharacterSize(thickness); // Ustawienie rozmiaru tekstu
    shape.setFont(font); // Ustawienie czcionki
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position);

    shape.setString(i); // Ustawienie tekstu na "1"
    i++;
}
void Point::resetValue() {
    i = 49;
}