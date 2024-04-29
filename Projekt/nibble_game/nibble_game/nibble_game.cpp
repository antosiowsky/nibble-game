#include <SFML/Graphics.hpp>
#include "snake.h"
#include "frame.h"
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Snake Game");

    // Create frame
    Frame frame(0, 0, 40, 100);

    // Create snake
    Snake snake(100, 100, 30, 10); // Example parameters
    char dir = 'r';
    sf::Clock clock;
    float deltaTime = 0.0f;
    float moveTimer = 0.0f;
    float moveInterval = 0.5f; // Adjust the snake's movement speedhere
    snake.grow();
    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        moveTimer += deltaTime;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&dir!='d')
            dir='u';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&dir!='u')
            dir = 'd';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&dir!='r')
            dir = 'l';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&dir!='l')
            dir = 'r';
          // dodać kolejkę ruchów 
        // Update snake's movement
        
        if (moveTimer >= moveInterval) {
            snake.move(dir);
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

    int skill_level;
    char increase_speed, mono_colo;

    std::cout << "Skill level (1 to 100)? \n 1 = Novice \n 90 = Expert \n 100 = Twidlle fingers \n";
    std::cin >> skill_level;

    std::cout << "Increase game speed during play (Y or N)? ";
    std::cin >> increase_speed;

    std::cout << "Monochrome or color monitor (M or C)? ";
    std::cin >> mono_colo;

  
*/