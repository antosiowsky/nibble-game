#include "snake.h"

Snake::Snake(float x, float y, float thickness, float speed)
    : Object(x, y, thickness), speed(speed), currentDirection(sf::Keyboard::Right) {
    sf::RectangleShape segment(sf::Vector2f(thickness, thickness));
    segment.setFillColor(sf::Color::Green);
    segment.setPosition(x, y);
    segments.push_front(segment);
}

Snake::~Snake() {}

void Snake::move() {
    sf::Vector2f newPos = segments.front().getPosition() + velocity;
    segments.front().setPosition(newPos);
}

void Snake::grow() {
    sf::RectangleShape segment(sf::Vector2f(thickness, thickness));
    segment.setFillColor(sf::Color::Green);
    segment.setPosition(segments.back().getPosition());
    segments.push_back(segment);
}

bool Snake::checkCollision() const {
    // Implement collision detection logic
    return false;
}

void Snake::handleInput(sf::Keyboard::Key key) {
    // Implement input handling logic
}

void Snake::draw(sf::RenderWindow& window) const {
    for (const auto& segment : segments) {
        window.draw(segment);
    }
}
