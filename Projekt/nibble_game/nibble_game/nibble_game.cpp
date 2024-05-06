#include <SFML/Graphics.hpp>
#include "snake.h"
#include "frame.h"
#include "game.h"
#include <iostream>
#include <queue>


int main() {
    
    
    // Create frame

    Game gra(32);

    gra.gameStart();
    

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