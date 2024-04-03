#include <SFML/Graphics.hpp>
#include <iostream>

int main(void) {
    int skill_level;
    char increase_speed, mono_colo;

    std::cout << "Skill level (1 to 100)? \n 1 = Novice \n 90 = Expert \n 100 = Twidlle fingers \n";
    std::cin >> skill_level;

    std::cout << "Increase game speed during play (Y or N)? ";
    std::cin >> increase_speed;
    
    std::cout << "Monochrome or color monitor (M or C)? ";
    std::cin >> mono_colo;



    /*
    sf::RenderWindow window(sf::VideoMode(500, 200), "SFML works!"); //rozmiar okna 
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    */
    return 0;
}
