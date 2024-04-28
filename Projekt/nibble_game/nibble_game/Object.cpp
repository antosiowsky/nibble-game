#include "object.h"

Object::Object(float x, float y, float thickness) : 
    x(x), y(y), thickness(thickness) {}


void Object::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Object::setThickness(float thickness) {
    this->thickness = thickness;
}

sf::Vector2f Object::getPosition() const {
    return position;
}

float Object::getThickness() const {
    return thickness;
}
