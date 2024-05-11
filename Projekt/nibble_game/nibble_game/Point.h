#ifndef POINT_H
#define POINT_H

#include "object.h"
#include "snake.h"

class Obstacle;

class Point : public Object {
private:
    int value;
  //  sf::RectangleShape shape;
    sf::Text shape;
    sf::Font font;
    char i = 49;

public:
    Point(float thickness, float frameWidth, float frameHeight, const Snake& snake);
    bool checkCollision(const Snake& snake, const std::vector<Obstacle>& obstacles);
    void draw(sf::RenderWindow& window) const override;

//private:
    void generatePoint(float thickness, float frameWidth, float frameHeight, const Snake& snake, const std::vector<Obstacle>& obstacles);
};

#endif // POINT_H
