﻿#include <SFML/Graphics.hpp>
#include "snake.h"
#include "frame.h"
#include "game.h"
#include <iostream>
#include <queue>
#include "menu.h"


int main() {


    // Create frame
    //1600x900
    Game gra(16,1600,900); // 1 to 50 skill level , windowWidth, widnowHeight



    gra.gameStart();

    gra.gameEnd();
    


    return 0;

}



/*

    int skill_level;
    char increase_speed, mono_colo;

    std::cout << "Skill level (1 to 50)? \n 1 = Novice \n 30 = Expert \n 50 = Twidlle fingers \n";
    std::cin >> skill_level;

    std::cout << "Increase game speed during play (Y or N)? ";
    std::cin >> increase_speed;

    std::cout << "Monochrome or color monitor (M or C)? ";
    std::cin >> mono_colo;

  
*/