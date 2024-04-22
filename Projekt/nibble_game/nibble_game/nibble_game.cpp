#include <SFML/Graphics.hpp>
#include "snake.h"
#include "frame.h"
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Snake Game");

    // Create frame
    Frame frame(50, 50, 70, 10);

    // Create snake
    Snake snake(100, 100, 20, 5); // Example parameters

    sf::Clock clock;
    float deltaTime = 0.0f;
    float moveTimer = 0.0f;
    float moveInterval = 0.1f; // Adjust the snake's movement speed here

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        moveTimer += deltaTime;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            snake.handleInput(sf::Keyboard::Up);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            snake.handleInput(sf::Keyboard::Down);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            snake.handleInput(sf::Keyboard::Left);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            snake.handleInput(sf::Keyboard::Right);

        // Update snake's movement
        if (moveTimer >= moveInterval) {
            snake.move();
            moveTimer = 0.0f;
        }

        window.clear(sf::Color::Black);

        // Draw objects
        frame.draw(window);
        snake.draw(window);

        window.display();
    }

    return 0;
}



/*
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Snake.h"


int main(void) {

    int skill_level;
    char increase_speed, mono_colo;

    std::cout << "Skill level (1 to 100)? \n 1 = Novice \n 90 = Expert \n 100 = Twidlle fingers \n";
    std::cin >> skill_level;

    std::cout << "Increase game speed during play (Y or N)? ";
    std::cin >> increase_speed;

    std::cout << "Monochrome or color monitor (M or C)? ";
    std::cin >> mono_colo;

    // Ustaw odstęp od krawędzi okna
    const float padding = 15.f;
    const float topPadding = 40.f;
    const float thickness = 10.f;

    // Utwórz okno o rozmiarze 1600x1000 pikseli
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Okno SFML z niebieskim tłem");

    // Utworzenie węża (przyjmując szerokość segmentu węża jako 20 pikseli)
    Snake snake(10, 20, 10);

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
*/