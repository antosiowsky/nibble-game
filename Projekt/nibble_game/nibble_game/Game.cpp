#include "Game.h"

namespace rng = std::ranges;
namespace fs = std::filesystem;


Game::Game(int game_speed, float windowWidth, float windowHeight) : 
    game_speed(game_speed) , windowWidth(windowWidth), windowHeight(windowHeight){};

//to do
    //  
    //
    // add levels
    // add graphic scoreboard
    // add grapic menu
    // 
    // ustawic obstacles w dobrych kratkach 
    // 
    // 
    // zrobic zeby waz respil sie o takiej dlugosci jaki jest
    // obecnie punkt!
    // 
    // na module wystarczy tylko 2 klasy zrobic
    // 
    // przy jeŸdzie np. w prawo i szybkim kliknieciu i trzmaniu 
    // góra dó³ w¹¿ zawraca na 1 kratce



void Game::gameStart() {
    
    

    bool colisionFlag = 0;
    float windowHeight = 1600;
    float windowWidth = 900;
    float thickness = 25;
    std::cout<<getWindowHeight() << std::endl; 

    std::cout << getWindowWidth() << std::endl;

    sf::RenderWindow window(sf::VideoMode(getWindowWidth() ,getWindowHeight() ), "Snake Game");

    //text//

    sf::Font font;
    font.loadFromFile("minecraft.ttf");
    sf::Text text;
    text.setFont(font);

    text.setCharacterSize(1.5*thickness);
    text.setFillColor(sf::Color::White);

    
   /* text.setString("SAMMY --> lives: 5    0000");
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(window.getSize().x - textBounds.width - thickness/5, thickness/5);*/

    std::stringstream ss;

    //////////////

	//frame//
   
    Frame top(getWindowWidth(), getWindowHeight(), thickness);

	//////////////


    //Obstacles//
    float centreX = top.getCenterPosition().x;

    float centreY = top.getCenterPosition().y; 
    /*int liczba = windowHeight;
    float zaokraglona;

    int reszta = liczba % 100;
    int setki = liczba / 100 * 100;

    if (reszta < 25)
        zaokraglona = setki;
    else if (reszta < 50)
        zaokraglona = setki + 25;
    else if (reszta < 75)
        zaokraglona = setki + 50;
    else
        zaokraglona = setki + 75;*/

    Obstacle wall1(centreX, centreY , thickness, 600.0, 'h');
    std::vector<Obstacle> obstacles;
    obstacles.push_back(wall1);
    //snake//

    char dir = 'r';

    float sped = (1.0 / game_speed);


    Snake snake(300, 300, thickness, getWindowWidth(), getWindowHeight()); // Example parameters
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
    point.generatePoint(thickness, getWindowWidth(), getWindowHeight(), snake);

    
    //////////////


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

        if (point.checkCollision(snake)) {
            std::cout << "zebrano";
            score += 1000*scoreMultiplier;

            int snakeLength = 3 + 2 * (scoreMultiplier - 1);
            for (int i = 0; i < snakeLength; i++)
                snake.grow();

            scoreMultiplier++;
            if (scoreMultiplier == 10)
                scoreMultiplier = 1;
            
        }

       
        if ((snake.checkCollision() == true && roundTime > 0.5)|| snake.checkCollisionWithObstacles(obstacles)) {
            std::cout << "uderzenie";

            colisionFlag = 1;

            snake.resetSnake();
            sf::sleep(sf::seconds(0.5));
            lives--;
            score -= 1000;
            int snakeLength = 3 + 2 * (scoreMultiplier - 1);
            for (int i = 0; i < snakeLength; i++)
                snake.grow();
            dir = 'r';
        }
           
        //std::cout << roundTime;
        // Draw text //

        ss.str("");
        ss<< "SAMMY --> lives: " << lives << "     " << score;
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

        wall1.draw(window);


        window.display();
    }
}



void Game::gameEnd() {

   /* sf::Music music;
    if (!music.openFromFile("champions.ogg")) {
        std::cerr << "Error: Unable to load music." << std::endl;
        return;
    }
    music.play();*/



   // Sprawdzanie i tworzenie pliku leaderboards.txt
    fs::path currentPath = fs::current_path();
    fs::path leaderboardFilePath = currentPath / "leaderboards.txt";

    std::vector<std::tuple<std::string, std::string, int>> leaderboardData;

    // Odczytanie poprzednich wyników z pliku
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

    // Dodanie nowego wyniku
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm parts;
    localtime_s(&parts, &now_c);

    std::ostringstream dateStream;
    dateStream << std::put_time(&parts, "%d-%m-%Y");
    std::ostringstream timeStream;
    timeStream << std::put_time(&parts, "%H:%M:%S");

    leaderboardData.push_back({ dateStream.str(), timeStream.str(), score });

    // Sortowanie danych
    rng::sort(leaderboardData, [](const auto& a, const auto& b) {
        return std::get<2>(a) > std::get<2>(b);
        });

    // Zapisywanie danych do pliku
    std::ofstream file(leaderboardFilePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open leaderboard file." << std::endl;
        return;
    }
    for (const auto& entry : leaderboardData) {
        file << std::get<0>(entry) << " " << std::get<1>(entry) << " " << std::get<2>(entry) << std::endl;
    }
    file.close();

    // Wyœwietlanie posortowanych wyników
    std::cout << "Leaderboard:" << std::endl;
    for (const auto& entry : leaderboardData) {
        std::cout << std::get<0>(entry) << " " << std::get<1>(entry) << " - " << std::get<2>(entry) << std::endl;
    }


}