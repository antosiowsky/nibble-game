#ifndef POINT_H
#define POINT_H

#include "object.h"
#include "snake.h"

class Point : public Object {
private:
    int value;
  //  sf::RectangleShape shape;
    sf::Text shape;
    sf::Font font;
    char i = 49;

public:
    Point(float thickness, float frameWidth, float frameHeight, const Snake& snake);
    bool checkCollision(const Snake& snake);
    void draw(sf::RenderWindow& window) const override;

//private:
    void generatePoint(float thickness, float frameWidth, float frameHeight, const Snake& snake);
};

#endif // POINT_H
