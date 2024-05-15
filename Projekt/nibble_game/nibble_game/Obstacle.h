#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "object.h"
#include <SFML/Graphics.hpp>
#include <list>

class Snake;

class Obstacle : public Object {
public:
    Obstacle(float x, float y, float thickness, float length, char direction);

    void draw(sf::RenderWindow& window) const;
    bool checkCollision(sf::Vector2f head) const;
    float getLength() const { return length; }
    char getDirection() const { return direction; }

private:
    float length;
    char direction;
};

#endif 
