#include "Game.h"

namespace rng = std::ranges;
namespace fs = std::filesystem;


Game::Game(int game_speed, float windowWidth, float windowHeight) : 
    game_speed(game_speed) , windowWidth(windowWidth), windowHeight(windowHeight){};

template<typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

template<FloatingPoint T>
T zaokraglona(T value) {
    int liczba = static_cast<int>(value);
    T zaokraglona;
    int reszta = liczba % 100;
    int setki = liczba / 100 * 100;
    if (reszta < 25)
        zaokraglona = setki;
    else if (reszta < 50)
        zaokraglona = setki + 25;
    else if (reszta < 75)
        zaokraglona = setki + 50;
    else
        zaokraglona = setki + 75;
    return zaokraglona;
}

void Game::gameStart() {

    bool levelChangeFlag = 0;
    float windowHeight = 1600;
    float windowWidth = 900;
  

    float thickness = 25;


    std::cout<<getWindowHeight() << std::endl; 

    std::cout << getWindowWidth() << std::endl;

    

    sf::RenderWindow windowM(sf::VideoMode(800, 600), "Menu");

    Menu menu(windowM, 800, 600);

    while (windowM.isOpen()) {
        sf::Event event;
        while (windowM.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                case sf::Keyboard::Left:
                    menu.DecreaseValue();
                    break;
                case sf::Keyboard::Right:
                    menu.IncreaseValue();
                    break;
                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem()) {
                    case 0:
                        std::cout << "Start Game selected" << std::endl;
                        windowM.close();
                        break;
                    case 1:
                        std::cout << "Game Speed: " << menu.GetGameSpeed() << std::endl;
                        break;
                    case 2:
                        std::cout << "Lives: " << menu.GetLives() << std::endl;
                        break;
                    case 3:
                        std::cout << "Exit Game selected" << std::endl;
                        windowM.close();
                        exit(0);
                        break;
                    }
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::Closed:
                windowM.close();
                exit(0);
                break;
            default:
                break;
            }
        }

        menu.draw();
    }

    game_speed = menu.GetGameSpeed();
    lives = menu.GetLives();

    sf::RenderWindow window(sf::VideoMode(getWindowWidth(), getWindowHeight()), "Snake Game");
    
    //text//

    sf::Font font;
    font.loadFromFile("minecraft.ttf");
    sf::Text text;
    text.setFont(font);

    text.setCharacterSize(1.5*thickness);
    text.setFillColor(sf::Color::White);


    std::stringstream ss;

    //////////////

	//frame//
   
    Frame top(getWindowWidth(), getWindowHeight(), thickness);

	//////////////


    //Obstacles// threads
    
    float centreX, centreY, quaterX, quaterY, oneEightX, oneEightY;
    std::thread t1([&]() { centreX = zaokraglona(top.getCenterPosition().x); });
    std::thread t2([&]() { centreY = zaokraglona(top.getCenterPosition().y); });
    std::thread t3([&]() { quaterX = zaokraglona(top.getCenterPosition().x / 2); });
    std::thread t4([&]() { quaterY = zaokraglona(top.getCenterPosition().y / 2); });
    std::thread t5([&]() { oneEightX = zaokraglona(top.getCenterPosition().x / 4); });
    std::thread t6([&]() { oneEightY = zaokraglona(top.getCenterPosition().y / 4); });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    Obstacle poziom2(centreX, centreY, thickness, 2*centreY, 'h');

    Obstacle poziom3_1(centreX - 13 * thickness, centreY, thickness,  centreY, 'v');
    Obstacle poziom3_2(centreX + 13 * thickness, centreY, thickness,  centreY, 'v');

    Obstacle poziom4_1(quaterX, 2*thickness, thickness, centreY-5*thickness, 'd');
    Obstacle poziom4_2(thickness, 3*quaterY, thickness, centreX-5*thickness, 'r');
    Obstacle poziom4_3(3*quaterX, getWindowHeight() - (2 * thickness), thickness, centreY - 5 * thickness, 'u');
    Obstacle poziom4_4(getWindowWidth()-2*thickness, quaterY, thickness, centreX - 5 * thickness, 'l');

    Obstacle poziom5_1(3*quaterX, centreY, thickness, centreY-2*thickness, 'v');
    Obstacle poziom5_2(quaterX, centreY, thickness, centreY-2*thickness, 'v');
    Obstacle poziom5_3(centreX , quaterY, thickness,  centreX - 4 * thickness, 'h');
    Obstacle poziom5_4(centreX + thickness, 3* quaterY, thickness, centreX - 4 * thickness, 'h');

    Obstacle poziom6_1(oneEightX, 2 * thickness, thickness, quaterY+oneEightY , 'd');
    Obstacle poziom6_2(quaterX, 2 * thickness, thickness, quaterY + oneEightY, 'd');
    Obstacle poziom6_3(quaterX + oneEightX, 2 * thickness, thickness, quaterY + oneEightY, 'd');
    Obstacle poziom6_4(centreX, 2 * thickness, thickness, quaterY + oneEightY, 'd');
    Obstacle poziom6_5(centreX + oneEightX, 2 * thickness, thickness, quaterY + oneEightY, 'd');
    Obstacle poziom6_6(centreX + quaterX, 2 * thickness, thickness, quaterY + oneEightY, 'd');
    Obstacle poziom6_7(centreX + quaterX + oneEightX, 2 * thickness, thickness, quaterY + oneEightY, 'd');

    Obstacle poziom6_8(oneEightX, getWindowHeight() - 2 * thickness, thickness, quaterY + oneEightY, 'u');
    Obstacle poziom6_9(quaterX, getWindowHeight() - 2 * thickness, thickness, quaterY + oneEightY, 'u');
    Obstacle poziom6_10(quaterX+oneEightX, getWindowHeight() - 2 * thickness, thickness, quaterY + oneEightY, 'u');
    Obstacle poziom6_11(centreX, getWindowHeight() - 2 * thickness, thickness, quaterY + oneEightY, 'u');
    Obstacle poziom6_12(centreX + oneEightX, getWindowHeight() - 2 * thickness, thickness, quaterY + oneEightY, 'u');
    Obstacle poziom6_13(centreX + quaterX, getWindowHeight() - 2 * thickness, thickness, quaterY + oneEightY, 'u');
    Obstacle poziom6_14(centreX + quaterX + oneEightX, getWindowHeight() - 2 * thickness, thickness, quaterY + oneEightY, 'u');
    


    std::vector<Obstacle> obstacles;
    
    //snake//

    char dir = 'r';

    float sped = (1.0 / game_speed);


    Snake snake(centreX, centreY-2*thickness, thickness, getWindowWidth(), getWindowHeight()); // Example parameters
    std::queue<char> directionQueue;
    sf::Clock clock;
    float deltaTime = 0.0f;
    float moveTimer = 0.0f;
    float roundTime = 0.0f; 
    float moveInterval = sped; // Adjust the snake's movement speedhere
    bool upKeyPressed = false, downKeyPressed = false, leftKeyPressed = false, rightKeyPressed = false;


    //////////


        //point//

    Point point(thickness, getWindowWidth(), getWindowHeight(), snake);
    point.generatePoint(thickness, getWindowWidth(), getWindowHeight(), snake, obstacles);

    
    //////////////

    int j = 1;
    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        moveTimer += deltaTime;
        roundTime += deltaTime;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
        }
        if (levelChangeFlag==1) {
            
            if (level == 2) {
                obstacles.clear();
                obstacles.push_back(poziom2);
                levelChangeFlag = 0;

                window.clear(sf::Color::Blue);
                top.draw(window);
                snake.draw(window);
                window.draw(text);
                point.draw(window);

                for (auto &o : obstacles)
                    o.draw(window);


                window.display();
                dir = 'r';
                sf::sleep(sf::seconds(1));
                
                
            }
            else if (level == 3) {
                obstacles.clear();
                obstacles.push_back(poziom3_1);
                obstacles.push_back(poziom3_2);
                levelChangeFlag = 0;

                window.clear(sf::Color::Blue);
                top.draw(window);
                snake.draw(window);
                window.draw(text);
                point.draw(window);

                for (auto &o : obstacles)
                    o.draw(window);


                window.display();
                dir = 'u';
                sf::sleep(sf::seconds(1));
            }
            else if (level == 4) {
                obstacles.clear();
                obstacles.push_back(poziom4_1);
                obstacles.push_back(poziom4_2);
                obstacles.push_back(poziom4_3);
                obstacles.push_back(poziom4_4);
                levelChangeFlag = 0;

                window.clear(sf::Color::Blue);
                top.draw(window);
                snake.draw(window);
                window.draw(text);
                point.draw(window);

                for (auto &o : obstacles)
                    o.draw(window);
                window.display();
                dir = 'r';
                sf::sleep(sf::seconds(1));
            
            }
            else if (level == 5) {
                obstacles.clear();
                obstacles.push_back(poziom5_1);
                obstacles.push_back(poziom5_2);
                obstacles.push_back(poziom5_3);
                obstacles.push_back(poziom5_4);
                levelChangeFlag = 0;

                window.clear(sf::Color::Blue);
                top.draw(window);
                snake.draw(window);
                window.draw(text);
                point.draw(window);

                for (auto &o : obstacles)
                    o.draw(window);


                window.display();
                dir = 'r';
                sf::sleep(sf::seconds(1));
            }
            else if (level >= 6) {
                obstacles.clear();
                obstacles.push_back(poziom6_1);
                obstacles.push_back(poziom6_2);
                obstacles.push_back(poziom6_3);
                obstacles.push_back(poziom6_4);
                obstacles.push_back(poziom6_5);
                obstacles.push_back(poziom6_6);
                obstacles.push_back(poziom6_7);

                obstacles.push_back(poziom6_8);
                obstacles.push_back(poziom6_9);
                obstacles.push_back(poziom6_10);
                obstacles.push_back(poziom6_11);
                obstacles.push_back(poziom6_12);
                obstacles.push_back(poziom6_13);
                obstacles.push_back(poziom6_14);
                levelChangeFlag = 0;

                window.clear(sf::Color::Blue);
                top.draw(window);
                snake.draw(window);
                window.draw(text);
                point.draw(window);

                for (auto &o : obstacles)
                    o.draw(window);


                window.display();
                dir = 'r';
                sf::sleep(sf::seconds(1));
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


        //Aktualizacja ruchu w�a
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

        if (point.checkCollision(snake, obstacles)) {
            std::cout << "zebrano";
            score += 100*scoreMultiplier;

            int snakeLength = 3 + 2 * (scoreMultiplier - 1);
            for (int i = 0; i < snakeLength; i++)
                snake.grow();

            scoreMultiplier++;
            if (scoreMultiplier == 10) {
                scoreMultiplier = 1;
                level++;
                levelChangeFlag = 1;
                roundTime = 0.0f;
                snake.resetSnake();
                snake.grow();
                sf::sleep(sf::seconds(0.5));
                
            }
        }

       
        if ((snake.checkCollision() == true && roundTime > 1)|| snake.checkCollisionWithObstacles(obstacles)) {

            snake.resetSnake();
            sf::sleep(sf::seconds(0.5));
            lives--;
            score -= 1000;
            snake.grow();
            dir = 'r';
            point.resetValue();
            point.generatePoint(thickness, getWindowWidth(), getWindowHeight(), snake, obstacles);
            scoreMultiplier = 1;
        }
           
        // Draw text //

        ss.str("");
        ss<< "LEVEL: "<< level << " SAMMY --> lives: " << lives << "     " << score;
        text.setString(ss.str());
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setPosition(window.getSize().x - textBounds.width - thickness / 5, thickness / 5);

        if (lives == 0)
        window.close();

        /////////////////

        // Draw objects //



        window.clear(sf::Color::Blue);
        top.draw(window);
        snake.draw(window);
        window.draw(text);
        point.draw(window);
		/////////////////


        for(auto &o : obstacles) //TEST
        o.draw(window);


        window.display();
    }
}


void Game::gameEnd() {
    
    sf::RenderWindow window(sf::VideoMode(400, 300), "Hall of Fame");

    //// filesystem
    fs::path currentPath = fs::current_path();
    fs::path leaderboardFilePath = currentPath / "leaderboards.txt";

    std::vector<std::tuple<std::string, std::string, int>> leaderboardData;

    // odczytanie poprzednich wynik�w z pliku // regex
    std::ifstream readFile(leaderboardFilePath);
    if (readFile.is_open()) {
        std::string line;
        while (std::getline(readFile, line)) {
            std::regex pattern(R"((\d{2}-\d{2}-\d{4}) (\d{2}:\d{2}:\d{2}) (\d+))");
            std::smatch matches;
            if (std::regex_match(line, matches, pattern)) {
                leaderboardData.push_back({ matches[1], matches[2], std::stoi(matches[3]) });
            }
        }
        readFile.close();
    }

    // dodanie nowego wyniku
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm parts;
    localtime_s(&parts, &now_c);

    std::ostringstream dateStream;
    dateStream << std::put_time(&parts, "%d-%m-%Y");
    std::ostringstream timeStream;
    timeStream << std::put_time(&parts, "%H:%M:%S");

    leaderboardData.push_back({ dateStream.str(), timeStream.str(), score });

    
    leaderboardData.insert(leaderboardData.begin(), { "         Hall of Fame            ", "                ", INT_MAX });

    // sortowanie danych // ranges
    rng::sort(leaderboardData, [](const auto& a, const auto& b) {
        return std::get<2>(a) > std::get<2>(b);
        });

    std::ofstream file(leaderboardFilePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open leaderboard file." << std::endl;
        return;
    }
    for (const auto& entry : leaderboardData) {
        file << std::get<0>(entry) << " " << std::get<1>(entry) << " " << std::get<2>(entry) << std::endl;
    }
    file.close();

    sf::Font font;
    if (!font.loadFromFile("minecraft.ttf")) {
        std::cout << "FONT LOAD FAILURE";
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // pozycja wynik�w
    int displayStartIndex = 0;
    int displayEndIndex = std::min(static_cast<int>(leaderboardData.size()), 10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0 && displayStartIndex > 0) {
                    --displayStartIndex;
                    --displayEndIndex;
                }
                else if (event.mouseWheelScroll.delta < 0 && displayEndIndex < leaderboardData.size()) {
                    ++displayStartIndex;
                    ++displayEndIndex;
                }
            }
        }

        window.clear();

        for (int i = displayStartIndex; i < displayEndIndex; ++i) {
            text.setString(std::get<0>(leaderboardData[i]) + " " + std::get<1>(leaderboardData[i]) + " - " + std::to_string(std::get<2>(leaderboardData[i])));
            text.setPosition(10.f, 10.f + 30.f * (i - displayStartIndex));
            window.draw(text);
        }

        window.display();
    }
}