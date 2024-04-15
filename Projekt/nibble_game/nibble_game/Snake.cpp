#include "snake.h"

Snake::Snake(int initialLength, float segmentSize, float speed) : segmentSize(segmentSize) {
    // Ustaw kolor wê¿a
    segment.setFillColor(sf::Color::Green);

    // Ustaw rozmiar segmentu wê¿a
    segment.setSize(sf::Vector2f(segmentSize, segmentSize));

    // Ustaw pozycjê dla ka¿dego segmentu wê¿a
    for (int i = 0; i < initialLength; ++i) {
        segment.setPosition(200, 200 + i * segmentSize);
        segments.push_back(segment);
    }
}

void Snake::move(float x, float y) {
    for (int i = segments.size() - 1; i > 0; --i) {
        segments[i].setPosition(segments[i - 1].getPosition());
    }
    segments[0].move(x, y);
}

void Snake::update(sf::Time dt) {
    // Aktualizuj zegar ruchu wê¿a
    timer += dt.asSeconds();

    // SprawdŸ, czy up³yn¹³ wystarczaj¹cy czas od ostatniego ruchu wê¿a
    if (timer >= interval) {
        // Przesuñ wê¿a
        move(direction.x * segmentSize, direction.y * segmentSize);

        // Zresetuj zegar
        timer = 0;
    }
}

void Snake::setDirection(sf::Vector2f newDirection) {
    // Ustawienie kierunku, ale nie pozwól na cofanie siê wê¿a
    if (direction.x + newDirection.x != 0 || direction.y + newDirection.y != 0) {
        direction = newDirection;
    }
}

void Snake::draw(sf::RenderWindow& window) {
    for (const auto& segment : segments) {
        window.draw(segment);
    }
}
