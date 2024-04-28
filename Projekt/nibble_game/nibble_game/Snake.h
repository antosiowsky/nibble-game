#ifndef SNAKE_H
#define SNAKE_H

#include "object.h"
#include <list>

class Snake : public Object {
public:
    Snake(float x, float y, float thickness, float speed);
    

    void move(char direction);
    void grow();
    bool checkCollision() const;


    void draw(sf::RenderWindow& window) const override;

private:
    int speed;
    std::list <sf::RectangleShape> segments;
    sf::Keyboard::Key direction = sf::Keyboard::Left;//possible bug

};

#endif // SNAKE_H
