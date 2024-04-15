#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Snake {
public:
    Snake(int initialLength, float segmentSize);

    void move(float x, float y);
    void update(sf::Time dt);
    void setDirection(sf::Vector2f newDirection);
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::RectangleShape> segments;
    sf::RectangleShape segment;
    sf::Vector2f direction;
    float segmentSize;

    // Zmienne zegara
    float timer = 0.0f;
    const float interval = 0.5f; // Interwa� czasowy mi�dzy ruchami w�a (w sekundach)
};

#endif // SNAKE_H
