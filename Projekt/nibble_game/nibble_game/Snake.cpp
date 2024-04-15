#include "snake.h"

Snake::Snake(int initialLength, float segmentSize, float speed) : segmentSize(segmentSize) {
    // Ustaw kolor w�a
    segment.setFillColor(sf::Color::Green);

    // Ustaw rozmiar segmentu w�a
    segment.setSize(sf::Vector2f(segmentSize, segmentSize));

    // Ustaw pozycj� dla ka�dego segmentu w�a
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
    // Aktualizuj zegar ruchu w�a
    timer += dt.asSeconds();

    // Sprawd�, czy up�yn�� wystarczaj�cy czas od ostatniego ruchu w�a
    if (timer >= interval) {
        // Przesu� w�a
        move(direction.x * segmentSize, direction.y * segmentSize);

        // Zresetuj zegar
        timer = 0;
    }
}

void Snake::setDirection(sf::Vector2f newDirection) {
    // Ustawienie kierunku, ale nie pozw�l na cofanie si� w�a
    if (direction.x + newDirection.x != 0 || direction.y + newDirection.y != 0) {
        direction = newDirection;
    }
}

void Snake::draw(sf::RenderWindow& window) {
    for (const auto& segment : segments) {
        window.draw(segment);
    }
}
