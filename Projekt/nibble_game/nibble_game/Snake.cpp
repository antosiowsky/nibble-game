#include "snake.h"

Snake::Snake(float x, float y, float thickness, float windowWidth, float windowHeight)
    : Object(x, y, thickness), windowWidth(windowWidth), windowHeight(windowHeight) {
    sf::RectangleShape segment(sf::Vector2f(thickness, thickness));
    segment.setFillColor(sf::Color::Green);
    segment.setPosition(x, y);
    segments.push_front(segment);
    segments.push_front(segment);
}

void Snake::move(char direction) {

    // Zapisujemy pozycjê poprzedniego segmentu
    sf::Vector2f prevPos = segments.front().getPosition();
    // Obliczamy now¹ pozycjê g³owy wê¿a
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
        segments.front().setPosition(newPos);
        break;
    }
    
    // Przechowujemy pozycjê poprzedniego segmentu przed poruszeniem wê¿a
    sf::Vector2f tempPos = prevPos;

    // Przechodzimy przez pozosta³e segmenty wê¿a
    std::list <sf::RectangleShape>::iterator it = segments.begin();
    ++it; // Przesuwamy iterator na drugi segment
    for (; it != segments.end(); ++it) {
        // Zapisujemy aktualn¹ pozycjê segmentu
        sf::Vector2f currentPos = it->getPosition();
        // Ustawiamy pozycjê segmentu na pozycjê poprzedniego segmentu
        it->setPosition(prevPos);
        // Aktualizujemy pozycjê poprzedniego segmentu na poprzedni¹ pozycjê aktualnego segmentu
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

    // Pobieramy pozycjê g³owy wê¿a
    sf::Vector2f headPos = segments.front().getPosition();
    // Sprawdzamy kolizjê z samym sob¹
    for (auto it = std::next(segments.begin()); it != segments.end(); ++it) {
        if (headPos == it->getPosition()) {
            // Jeœli g³owa wê¿a koliduje z którymkolwiek z segmentów cia³a, zwracamy true
            return true;
        }
    }
    float frameLeft = thickness +1 ;
    float frameRight = windowWidth - 2 * thickness;  //x 
    float frameTop = 2 * thickness +1;
    float frameBottom = windowHeight - 2 * thickness; //y 

    if (headPos.x < frameLeft || headPos.x >= frameRight || headPos.y < frameTop || headPos.y >= frameBottom) {
        return true;
    }

    return false;
    
}

void Snake::draw(sf::RenderWindow& window) const {
    for (const auto& segment : segments) {
        window.draw(segment);
    }
}

const std::list<sf::RectangleShape>& Snake::getSegments() const {
    return segments;
}

void Snake::resetSnake() {
    // Usuwamy wszystkie segmenty wê¿a oprócz g³owy
    segments.erase(std::next(segments.begin()), segments.end());
    
    segments.front().setPosition(x, y);

    
    // Ustawiamy kierunek ruchu na domyœlny ('r')
}

bool Snake::checkCollisionWithObstacles(const std::vector<Obstacle>& obstacles) const {
    sf::Vector2f headPos = segments.front().getPosition();
    
    for (const auto& segment : segments) {
        for (const auto& obstacle : obstacles) {
            if (obstacle.checkCollision(headPos))
                return true;
        }
    }
    return false;
}