#include <SFML/Graphics.hpp>
#include <iostream>

class Snake {
public:
    Snake(int initialLength, float segmentSize) {
        for (int i = 0; i < initialLength; ++i) {
            sf::RectangleShape segment(sf::Vector2f(segmentSize, segmentSize));
            segment.setFillColor(sf::Color::Green);
            segment.setPosition(200, 200 + i * segmentSize);
            segments.push_back(segment);
        }
    }

    void move(float x, float y) {
        for (int i = segments.size() - 1; i > 0; --i) {
            segments[i].setPosition(segments[i - 1].getPosition());
        }
        segments[0].move(x, y);
    }

    void draw(sf::RenderWindow& window) {
        for (const auto& segment : segments) {
            window.draw(segment);
        }
    }

private:
    std::vector<sf::RectangleShape> segments;
};

int main(void) {
    // Ustaw odstęp od krawędzi okna
    const float padding = 15.f;
    const float topPadding = 40.f;
    const float thickness = 10.f;
    int initialWidth = 1600;
    int initialHeight = 1000;

    // Utwórz okno o rozmiarze 1600x1000 pikseli
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Okno SFML z niebieskim tłem");

    Snake snake(10, 20); // Utworzenie węża

    // Główna pętla programu
    while (window.isOpen()) {
        // Sprawdź wszystkie zdarzenia, które wystąpiły od ostatniego cyklu pętli
        sf::Event event;
        while (window.pollEvent(event)) {
            // Obsłuż zamknięcie okna
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Obsługa ruchu węża za pomocą strzałek
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    snake.move(0, -20); // Ruch węża w górę
                    break;
                case sf::Keyboard::Down:
                    snake.move(0, 20); // Ruch węża w dół
                    break;
                case sf::Keyboard::Left:
                    snake.move(-20, 0); // Ruch węża w lewo
                    break;
                case sf::Keyboard::Right:
                    snake.move(20, 0); // Ruch węża w prawo
                    break;
                default:
                    break;
                }
            }
        }

        // Wyczyść ekran ustawiając tło na kolor niebieski
        sf::Color bG(0, 0, 128);
        window.clear(bG);

        // Rysuj ramki dookoła okna
        sf::RectangleShape topBorder(sf::Vector2f(window.getSize().x - 2 * padding, thickness));
        topBorder.setPosition(padding, topPadding);
        topBorder.setFillColor(sf::Color::Red);

        sf::RectangleShape bottomBorder(sf::Vector2f(window.getSize().x - 2 * padding, thickness));
        bottomBorder.setPosition(padding, window.getSize().y - thickness - padding);
        bottomBorder.setFillColor(sf::Color::Red);

        sf::RectangleShape leftBorder(sf::Vector2f(thickness, window.getSize().y - 2 * padding - topPadding / 1.5));
        leftBorder.setPosition(padding, topPadding);
        leftBorder.setFillColor(sf::Color::Red);

        sf::RectangleShape rightBorder(sf::Vector2f(thickness, window.getSize().y - 2 * padding - topPadding / 1.5));
        rightBorder.setPosition(window.getSize().x - thickness - padding, topPadding);
        rightBorder.setFillColor(sf::Color::Red);

        window.draw(topBorder);
        window.draw(bottomBorder);
        window.draw(leftBorder);
        window.draw(rightBorder);

        // Wyświetl zawartość okna
        snake.draw(window);
        window.display();
    }

    return 0;
}
