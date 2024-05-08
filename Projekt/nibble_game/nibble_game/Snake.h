#ifndef SNAKE_H
#define SNAKE_H

#include "object.h"
#include <list>

class Snake : public Object {
public:
    Snake(float x, float y, float thickness, float windowWidth, float windowHeight);
    

    void move(char direction);
    void grow();
    void resetSnake();
    bool checkCollision() const;


    void draw(sf::RenderWindow& window) const override;

private:

    std::list <sf::RectangleShape> segments;
    sf::Keyboard::Key direction = sf::Keyboard::Left;//possible bug
    float windowWidth;
	float windowHeight;
};

#endif // SNAKE_H
