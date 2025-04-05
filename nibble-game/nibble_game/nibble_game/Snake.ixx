export module Snake;

import <SFML/Graphics.hpp>;
import <iostream>;
import <vector>;

export class Snake {
public:
    Snake(int initialLength, float segmentSize, float speed);

    void move(float x, float y);
    void update(sf::Time dt);
    void setDirection(sf::Vector2f newDirection);
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::RectangleShape> segments;
    sf::RectangleShape segment;
    sf::Vector2f direction;
    float segmentSize;
    
    // Zmienne zegara
    float timer = 0.0f;
    const float interval = 0.5f; // Interwa³ czasowy miêdzy ruchami wê¿a (w sekundach)
};
