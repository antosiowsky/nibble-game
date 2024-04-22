#include "frame.h"

Frame::Frame(float x, float y, float length, float thickness)
    : Object(x, y, thickness), length(length) , thickness(thickness) {}

Frame::~Frame() {}

void Frame::draw(sf::RenderWindow& window) const {
    sf::RectangleShape top(sf::Vector2f(length, thickness));
    top.setPosition(position.x, position.y);
    top.setFillColor(sf::Color::Red);

    sf::RectangleShape bottom(sf::Vector2f(length, thickness));
    bottom.setPosition(position.x, position.y + length - thickness);
    bottom.setFillColor(sf::Color::Red);

    sf::RectangleShape left(sf::Vector2f(thickness, length - 2 * thickness));
    left.setPosition(position.x, position.y + thickness);
    left.setFillColor(sf::Color::Red);

    sf::RectangleShape right(sf::Vector2f(thickness, length - 2 * thickness));
    right.setPosition(position.x + length - thickness, position.y + thickness);
    right.setFillColor(sf::Color::Red);

    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
}
