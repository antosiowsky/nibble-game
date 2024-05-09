#include "point.h"
#include <random>
#include <iostream>

Point::Point(float thickness, float frameWidth, float frameHeight, const Snake& snake)
    : Object(frameWidth, frameHeight, thickness), value(0) {
    generatePoint(thickness, frameWidth, frameHeight, snake);
}

bool Point::checkCollision(const Snake& snake) {
    sf::FloatRect pointBounds = shape.getGlobalBounds();
    for (const auto& segment : snake.getSegments()) {
        sf::FloatRect segmentBounds = segment.getGlobalBounds();
        if (pointBounds.intersects(segmentBounds)) {
            value++;
            generatePoint(thickness, this->x, this->y, snake);
            std::cout << thickness << std::endl;
            return true;
        }
    }
    return false;
}

void Point::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

void Point::generatePoint(float thickness, float frameWidth, float frameHeight, const Snake& snake) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(1, (int)((frameWidth - 2 * thickness) / thickness));
    std::uniform_int_distribution<int> disY(1, (int)((frameHeight - 2 * thickness) / thickness));


    bool validPosition = false;
    while (!validPosition) {
        validPosition = true;
        int x = disX(gen) * thickness;
        int y = disY(gen) * thickness;
        position.x = x;
        position.y = y;
        if (position.x < thickness && position.y < 2*thickness)
            validPosition = false;
        if (position.x > frameWidth - thickness && position.y > frameHeight - 2*thickness)
            validPosition = false;
        for (const auto& segment : snake.getSegments()) {
            sf::FloatRect segmentBounds = segment.getGlobalBounds();
            if (segmentBounds.contains(position)) {
                validPosition = false;
                break;
            }
        }
    }

    shape.setSize(sf::Vector2f(thickness, thickness));
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Yellow);
}
