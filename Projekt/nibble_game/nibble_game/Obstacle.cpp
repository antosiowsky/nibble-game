#include "obstacle.h"

Obstacle::Obstacle(float x, float y, float thickness, float length, char direction)
    : Object(x, y, thickness), length(length), direction(direction) {
}

void Obstacle::draw(sf::RenderWindow& window) const {
    sf::RectangleShape obstacle;

    switch (direction) {
    case 'r': // right
        obstacle.setSize(sf::Vector2f(length, thickness));
        obstacle.setPosition(x, y - thickness / 2);
        break;
    case 'd': // down
        obstacle.setSize(sf::Vector2f(thickness, length));
        obstacle.setPosition(x - thickness / 2, y);
        break;
    case 'v': // vertical
        obstacle.setSize(sf::Vector2f(thickness, length));
        obstacle.setPosition(x - thickness / 2, y - length / 2);
        break;
    case 'h': // horizontal
        obstacle.setSize(sf::Vector2f(length, thickness));
        obstacle.setPosition(x - length / 2, y - thickness / 2);
        break;
    default:
        // Default to right direction
        obstacle.setSize(sf::Vector2f(length, thickness));
        obstacle.setPosition(x, y - thickness / 2);
        break;
    }

    obstacle.setFillColor(sf::Color::Red);
    window.draw(obstacle);
}

bool Obstacle::checkCollision(sf::RectangleShape snakeHead) const {
     sf::Vector2f  head=snakeHead.getPosition();
        switch (direction) {
        case 'r': // right
            if (head.x + thickness > x &&
                head.y > y - thickness / 2 &&
                head.y < y + thickness - thickness / 2) {
                return true;
            }
            break;
        case 'd': // down
            if (head.x > x - thickness / 2 &&
                head.x < x + thickness - thickness / 2 &&
                head.y + thickness > y &&
                head.y < y + length) {
                return true;
            }
            break;
        case 'v': // vertical
            if (head.x > x - thickness / 2 &&
                head.x < x + thickness - thickness / 2 &&
                head.y > y - length / 2 - thickness / 2 &&
                head.y < y + length / 2 + thickness / 2) {
                return true;
            }
            break;
        case 'h': // horizontal
            if (head.x > x - length / 2 - thickness / 2 &&
                head.x < x + length / 2 + thickness / 2 &&
                head.y > y - thickness / 2 &&
                head.y < y + thickness - thickness / 2) {
                return true;
            }
            break;
        default:
            break;
        }
    

    return false;
}
