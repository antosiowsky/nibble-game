#include "snake.h"

Snake::Snake(float x, float y, float thickness, float speed)
    : Object(x, y, thickness), speed(game_speed) {
    sf::RectangleShape segment(sf::Vector2f(thickness, thickness));
    segment.setFillColor(sf::Color::Green);
    segment.setPosition(x, y);
    segments.push_front(segment);
    segments.push_front(segment);
    segments.push_front(segment);
}


void Snake::move(char direction) {

   
    // Zapisujemy pozycj� poprzedniego segmentu
    sf::Vector2f prevPos = segments.front().getPosition();
    // Obliczamy now� pozycj� g�owy w�a
    sf::Vector2f newPos;
    switch (direction)
    {
    case 'r':
        newPos = prevPos + sf::Vector2f(thickness, 0);
        segments.front().setPosition(newPos);
        break;
    case 'd':
        newPos = prevPos + sf::Vector2f(0,thickness);
        segments.front().setPosition(newPos);
        break;
    case 'u':
        newPos = prevPos - sf::Vector2f(0, thickness);
        segments.front().setPosition(newPos);
        break;
    case 'l':
        newPos = prevPos - sf::Vector2f(thickness,0);
        segments.front().setPosition(newPos);
        break;
    default:
        //newPos = prevPos + sf::Vector2f(thickness, 0);
        segments.front().setPosition(newPos);
        break;
    }
    
    // Przechowujemy pozycj� poprzedniego segmentu przed poruszeniem w�a
    sf::Vector2f tempPos = prevPos;

    // Przechodzimy przez pozosta�e segmenty w�a
    std::list <sf::RectangleShape>::iterator it = segments.begin();
    ++it; // Przesuwamy iterator na drugi segment
    for (; it != segments.end(); ++it) {
        // Zapisujemy aktualn� pozycj� segmentu
        sf::Vector2f currentPos = it->getPosition();
        // Ustawiamy pozycj� segmentu na pozycj� poprzedniego segmentu
        it->setPosition(prevPos);
        // Aktualizujemy pozycj� poprzedniego segmentu na poprzedni� pozycj� aktualnego segmentu
        prevPos = currentPos;
    }
}

void Snake::grow() {
    sf::RectangleShape segment(sf::Vector2f(thickness, thickness));
    segment.setFillColor(sf::Color::Green);
    segment.setPosition(segments.back().getPosition());
    segments.push_back(segment);
}

bool Snake::checkCollision() const {
    // Implement collision detection logic
    return false;
}


void Snake::draw(sf::RenderWindow& window) const {
    for (const auto& segment : segments) {
        window.draw(segment);
    }
}
