#include "Game.h"

Game::Game(int game_speed) : game_speed(game_speed) {};

void Game::gameStart() {
    
    //to do
    //  
    // add points remember to eliminate spawn bug 
    // add score and lives counter (stringstream in game loop)
    // add collision with walls and with snake itself 
    // 

    float windowHeight = 1600;
    float windowWidth = 900;
    float thickness = 25;

    sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Snake Game");

    //text//

    sf::Font font;
    font.loadFromFile("minecraft.ttf");
    sf::Text text;
    text.setFont(font);

    text.setCharacterSize(1.5*thickness);
    text.setFillColor(sf::Color::White);


    text.setString("SAMMY --> lives: 5    0000");
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(window.getSize().x - textBounds.width - thickness/5, thickness/5);

    //////////////

	//frame//
   
    Frame top(windowHeight, windowWidth, thickness);

	//////////////

    //snake//

    char dir = 'r';

    float sped = (1.0 / game_speed);
    std::cout<<game_speed << std::endl;
    std::cout << sped << std::endl;

    Snake snake(100, 100, thickness); // Example parameters
    std::queue<char> directionQueue;
    sf::Clock clock;
    float deltaTime = 0.0f;
    float moveTimer = 0.0f;
    float moveInterval = sped; // Adjust the snake's movement speedhere
    bool upKeyPressed = false, downKeyPressed = false, leftKeyPressed = false, rightKeyPressed = false;

    //////////

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        moveTimer += deltaTime;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
        }


        if (directionQueue.size() <= 1)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !upKeyPressed && dir != 'd' && (directionQueue.empty() || directionQueue.back() != '1'))
            {
                std::cout << "pushed up" << std::endl;
                directionQueue.push('u');
                upKeyPressed = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !rightKeyPressed && dir != 'l' && (directionQueue.empty() || directionQueue.back() != 2))
            {
                std::cout << "pushed right" << std::endl;
                directionQueue.push('r');
                rightKeyPressed = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !downKeyPressed && dir != 'u' && (directionQueue.empty() || directionQueue.back() != 3))
            {
                std::cout << "pushed down" << std::endl;
                directionQueue.push('d');
                downKeyPressed = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !leftKeyPressed && dir != 'r' && (directionQueue.empty() || directionQueue.back() != 4))
            {
                std::cout << "pushed left" << std::endl;
                directionQueue.push('l');
                leftKeyPressed = true;
            }
        }


        //Aktualizacja ruchu wê¿a
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


            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                upKeyPressed = false;

            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                downKeyPressed = false;

            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                leftKeyPressed = false;

            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                rightKeyPressed = false;
        }

       

        // Draw objects //

        window.clear(sf::Color::Blue);
        top.draw(window);
        snake.draw(window);
        window.draw(text);

		/////////////////

        window.display();
    }
}