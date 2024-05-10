#ifndef SNAKE_H
#define SNAKE_H

#include "object.h"
#include <list>
#include "Obstacle.h"

class Snake : public Object {
public:
    Snake(float x, float y, float thickness, float windowWidth, float windowHeight);
    

    void move(char direction);
    void grow();
    void resetSnake();
    bool checkCollision() const;
    const std::list<sf::RectangleShape>& getSegments() const;

    void draw(sf::RenderWindow& window) const override;
    bool checkCollisionWithObstacles(const std::vector<Obstacle>& obstacles) const;
private:

    std::list <sf::RectangleShape> segments;
    sf::Keyboard::Key direction = sf::Keyboard::Left;//possible bug
    float windowWidth;
	float windowHeight;
};

#endif // SNAKE_H
