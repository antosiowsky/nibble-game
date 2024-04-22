#ifndef SNAKE_H
#define SNAKE_H

#include "object.h"
#include <deque>

class Snake : public Object {
public:
    Snake(float x, float y, float thickness, float speed);
    ~Snake();

    void move();
    void grow();
    bool checkCollision() const;
    void handleInput(sf::Keyboard::Key key);

    void draw(sf::RenderWindow& window) const override;

private:
    std::deque<sf::RectangleShape> segments;
    float speed;
    sf::Vector2f velocity;
    sf::Keyboard::Key currentDirection;
};

#endif // SNAKE_H
