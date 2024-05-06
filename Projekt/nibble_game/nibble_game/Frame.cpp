#include "frame.h"

Frame::Frame(float x, float y, float thickness, float length)
    : Object(x, y, thickness) , length(length)  {
}
// //Frame::~Frame() {}

void Frame::draw(sf::RenderWindow& window) const {
    sf::RectangleShape top(sf::Vector2f(length, thickness));
    top.setPosition(x, y);
    top.setFillColor(sf::Color::Red);

    std::cout << x << " " << y << " " << this->position.x << " " << position.y << std::endl;
    //std::cout<<length<< " " << thickness << std::endl;

    sf::RectangleShape bottom(sf::Vector2f(length, thickness));
    bottom.setPosition(x,y + length - thickness);
    bottom.setFillColor(sf::Color::Red);

    sf::RectangleShape left(sf::Vector2f(thickness, length - 2 * thickness));
    left.setPosition(x, y + thickness);
    left.setFillColor(sf::Color::Red);

    sf::RectangleShape right(sf::Vector2f(thickness, length - 2 * thickness));
    right.setPosition(x + length - thickness, y + thickness);
    right.setFillColor(sf::Color::Red);

    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
}
