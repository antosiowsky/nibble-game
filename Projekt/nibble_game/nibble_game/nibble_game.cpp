#include <SFML/Graphics.hpp>
#include <iostream>

class Snake {
public:
    Snake(int initialLength, float segmentSize) : segmentSize(segmentSize) {
        // Ustaw kolor węża
        segment.setFillColor(sf::Color::Green);

        // Ustaw rozmiar segmentu węża
        segment.setSize(sf::Vector2f(segmentSize, segmentSize));

        // Ustaw pozycję dla każdego segmentu węża
        for (int i = 0; i < initialLength; ++i) {
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

    void update(sf::Time dt) {
        // Aktualizuj zegar ruchu węża
        timer += dt.asSeconds();

        // Sprawdź, czy upłynął wystarczający czas od ostatniego ruchu węża
        if (timer >= interval) {
            // Przesuń węża
            move(direction.x * segmentSize, direction.y * segmentSize);

            // Zresetuj zegar
            timer = 0;
        }
    }

    void setDirection(sf::Vector2f newDirection) {
        // Ustawienie kierunku, ale nie pozwól na cofanie się węża
        if (direction.x + newDirection.x != 0 || direction.y + newDirection.y != 0) {
            direction = newDirection;
        }
    }

    void draw(sf::RenderWindow& window) {
        for (const auto& segment : segments) {
            window.draw(segment);
        }
    }

private:
    std::vector<sf::RectangleShape> segments;
    sf::RectangleShape segment;
    sf::Vector2f direction;
    float segmentSize;

    // Zmienne zegara
    float timer = 0.0f;
    const float interval = 0.5f; // Interwał czasowy między ruchami węża (w sekundach)
};

int main(void) {
    // Ustaw odstęp od krawędzi okna
    const float padding = 15.f;
    const float topPadding = 40.f;
    const float thickness = 10.f;

    // Utwórz okno o rozmiarze 1600x1000 pikseli
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Okno SFML z niebieskim tłem");

    // Utworzenie węża (przyjmując szerokość segmentu węża jako 20 pikseli)
    Snake snake(10, 20);

    // Główna pętla programu
    sf::Clock clock;
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
                    snake.setDirection(sf::Vector2f(0, -1)); // Ustaw kierunek węża w górę
                    break;
                case sf::Keyboard::Down:
                    snake.setDirection(sf::Vector2f(0, 1)); // Ustaw kierunek węża w dół
                    break;
                case sf::Keyboard::Left:
                    snake.setDirection(sf::Vector2f(-1, 0)); // Ustaw kierunek węża w lewo
                    break;
                case sf::Keyboard::Right:
                    snake.setDirection(sf::Vector2f(1, 0)); // Ustaw kierunek węża w prawo
                    break;
                default:
                    break;
                }
            }
        }

        // Wyczyść ekran ustawiając tło na kolor niebieski
        window.clear(sf::Color(0, 0, 128));

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

        // Pobierz czas trwania klatki
        sf::Time dt = clock.restart();

        // Aktualizuj ruch węża z uwzględnieniem czasu trwania klatki
        snake.update(dt);

        // Wyświetl zawartość okna
        snake.draw(window);
        window.display();
    }

    return 0;
}
