#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object{
public:
    Object(float x, float y, float thickness);

    void setPosition(float x, float y);
    void setThickness(float thickness);
    sf::Vector2f getPosition() const;
    float getThickness() const;
    virtual void draw(sf::RenderWindow& window) const = 0;
protected:
    sf::Vector2f position;
    float thickness, x,y;
};

#endif