#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object{
public:
    Object(float x, float y, float thickness);
    //virtual ~Object();

    void setPosition(float x, float y);
    void setThickness(float thickness);
    sf::Vector2f getPosition() const;
    float getThickness() const;

    virtual void draw(sf::RenderWindow& window) const = 0;

protected:
    sf::Vector2f position;
    float thickness, x,y;
};

#endif // OBJECT_H

//
////Movement controls
//if (directionQueue.size() <= 1)
//{
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !upKeyPressed && (directionQueue.empty() || directionQueue.back() != 1))
//    {
//        std::cout << "pushed up" << std::endl;
//        directionQueue.push(1);
//        upKeyPressed = true;
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !rightKeyPressed && (directionQueue.empty() || directionQueue.back() != 2))
//    {
//        directionQueue.push(2);
//        rightKeyPressed = true;
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !downKeyPressed && (directionQueue.empty() || directionQueue.back() != 3))
//    {
//        directionQueue.push(3);
//        downKeyPressed = true;
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !leftKeyPressed && (directionQueue.empty() || directionQueue.back() != 4))
//    {
//        directionQueue.push(4);
//        leftKeyPressed = true;
//    }
//}
//
//
//
//if (cooldownClock.getElapsedTime().asSeconds() > cooldownDuration)
//{
//    //Reposition rest of the body
//    for (auto i = snakeBody.size() - 1; i >= 1; i--)
//    {
//        snakeBody[i].setPosition(snakeBody[i - 1].getX(), snakeBody[i - 1].getY());
//    }
//
//    //Drop bad movements like turns in the opposite direction
//    if (!directionQueue.empty() && (directionQueue.front() - direction) % 2 == 0 && direction != 0)
//    {
//        directionQueue.pop();
//    }
//
//    //Change direction based on movement
//    if (!directionQueue.empty())
//    {
//        direction = directionQueue.front();
//        directionQueue.pop();
//    }
//
//    //Move the head
//    if (direction == 1 && snakeBody[0].getY() > movementLimitUp)
//    {
//        snakeBody[0].move(0, -1);
//        cooldownClock.restart();
//    }
//    else if (direction == 2 && snakeBody[0].getX() < movementLimitRight)
//    {
//        snakeBody[0].move(1, 0);
//        cooldownClock.restart();
//    }
//    else if (direction == 3 && snakeBody[0].getY() < movementLimitDown)
//    {
//        snakeBody[0].move(0, 1);
//        cooldownClock.restart();
//    }
//    else if (direction == 4 && snakeBody[0].getX() > movementLimitLeft)
//    {
//        snakeBody[0].move(-1, 0);
//        cooldownClock.restart();
//    }
//}