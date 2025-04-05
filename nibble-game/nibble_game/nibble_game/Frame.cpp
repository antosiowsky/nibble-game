#include "frame.h"

Frame::Frame(float x, float y, float thickness)
    : Object(x, y, thickness){
}
// //Frame::~Frame() {}

void Frame::draw(sf::RenderWindow& window) const {
    sf::RectangleShape top(sf::Vector2f(x-2*thickness, thickness));
    top.setPosition(thickness, 2*thickness);
    top.setFillColor(sf::Color::Red);

    sf::RectangleShape bottom(sf::Vector2f(x - 2 * thickness, thickness));
    bottom.setPosition(thickness, y-2*thickness);
    bottom.setFillColor(sf::Color::Red);

    sf::RectangleShape left(sf::Vector2f(thickness, y - 3 * thickness));
    left.setPosition(thickness, 2 * thickness);
    left.setFillColor(sf::Color::Red);

    sf::RectangleShape right(sf::Vector2f(thickness, y - 3 * thickness));
    right.setPosition(x-2*thickness, 2 * thickness);
    right.setFillColor(sf::Color::Red);

    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
}
