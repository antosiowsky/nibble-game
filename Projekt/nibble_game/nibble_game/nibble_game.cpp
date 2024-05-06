#include <SFML/Graphics.hpp>
#include "snake.h"
#include "frame.h"
#include <iostream>
#include <queue>

char dir = 'r';

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Snake Game");
    
    // Create frame
    Frame frame(40, 40, 30, 600);
    
    
    
    // Create snake
    Snake snake(100, 100, 30, 10); // Example parameters
    std::queue<char> directionQueue;
    sf::Clock clock;
    float deltaTime = 0.0f;
    float moveTimer = 0.0f;
    float moveInterval = 0.2f; // Adjust the snake's movement speedhere
    bool upKeyPressed = false, downKeyPressed = false, leftKeyPressed = false, rightKeyPressed = false;


    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        moveTimer += deltaTime;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

     
         if (directionQueue.size() <= 1)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !upKeyPressed && dir!='d' && (directionQueue.empty() || directionQueue.back() != '1'))
                {
                    std::cout << "pushed up" << std::endl;
                    directionQueue.push('u');
                    upKeyPressed = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !rightKeyPressed && dir!='l' && (directionQueue.empty() || directionQueue.back() != 2))
                {
                    std::cout << "pushed right" << std::endl;
                    directionQueue.push('r');
                    rightKeyPressed = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !downKeyPressed && dir!='u' && (directionQueue.empty() || directionQueue.back() != 3))
                {
                    std::cout << "pushed down" << std::endl;
                    directionQueue.push('d');
                    downKeyPressed = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !leftKeyPressed && dir!='r' && (directionQueue.empty() || directionQueue.back() != 4))
                {
                    std::cout << "pushed left" << std::endl;
                    directionQueue.push('l');
                    leftKeyPressed = true;
                }
            }
        
        
        //Aktualizacja ruchu węża
       if (moveTimer >= moveInterval) {
            if (!directionQueue.empty()) {
                snake.move(directionQueue.front());
                dir = directionQueue.front();
                directionQueue.pop();
            }
            else {
            snake.move(dir);
            }
            moveTimer = 0.0f;


            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                upKeyPressed = false;

			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				downKeyPressed = false;

			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				leftKeyPressed = false;

			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				rightKeyPressed = false;
       }
      
        window.clear(sf::Color::Blue);

        // Draw objects
        frame.draw(window);
        snake.draw(window);

       /* sf::RectangleShape top(sf::Vector2f(1000, 30));
        top.setPosition(10, 10);
        top.setFillColor(sf::Color::Red);
        window.draw(top);*/

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