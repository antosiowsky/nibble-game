#include <SFML/Graphics.hpp>
#include "snake.h"
#include "frame.h"
#include <iostream>
#include <queue>

char dir = 'r';

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Snake Game");
    std::queue<char> directionQueue;
    // Create frame
    Frame frame(0, 0, 40, 100);
    bool upKeyPressed = false, downKeyPressed = false, leftKeyPressed = false, rightKeyPressed = false;
    // Create snake
    Snake snake(100, 100, 30, 10); // Example parameters
    
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

     
         if (directionQueue.size() <= 1)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !upKeyPressed && (directionQueue.empty() || directionQueue.back() != 1))
                {
                    std::cout << "pushed up" << std::endl;
                    directionQueue.push('u');
                    upKeyPressed = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !rightKeyPressed && (directionQueue.empty() || directionQueue.back() != 2))
                {
                    std::cout << "pushed right" << std::endl;
                    directionQueue.push('r');
                    rightKeyPressed = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !downKeyPressed && (directionQueue.empty() || directionQueue.back() != 3))
                {
                    std::cout << "pushed down" << std::endl;
                    directionQueue.push('d');
                    downKeyPressed = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !leftKeyPressed && (directionQueue.empty() || directionQueue.back() != 4))
                {
                    std::cout << "pushed left" << std::endl;
                    directionQueue.push('l');
                    leftKeyPressed = true;
                }
            }
        
       /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != 'd')
            directionQueue.push('u');
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != 'u')
            directionQueue.push('d');
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != 'r')
            directionQueue.push('l');
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != 'l')
            directionQueue.push('r');*/
         
        //Aktualizacja ruchu węża
       if (moveTimer >= moveInterval) {
            if (!directionQueue.empty()) {
                snake.move(directionQueue.front());
                dir = directionQueue.front();
                directionQueue.pop();
                switch (dir)
                {
                    case 'u':
						upKeyPressed = false;
						break;
					case 'd':
						downKeyPressed = false;
						break;
					case 'l':
						leftKeyPressed = false;
                        break;
					case 'r':
						rightKeyPressed = false;
						break;


                default:
                    break;
                }
            }
            else {
            snake.move(dir);
            }
            moveTimer = 0.0f;
       }
      /*  
       if (!directionQueue.empty() && (directionQueue.front() - direction) % 2 == 0 && direction != 0)
               {
                   directionQueue.pop();
               }*/

       // moveTimer += clock.restart().asSeconds();
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