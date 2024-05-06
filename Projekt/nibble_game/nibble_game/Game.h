#pragma once
#include <iostream>
#include <vector>
#include <queue>

#include "Frame.h"
#include "Snake.h"

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(int game_speed);
	int score = 0;
	int lives = 5;
	int level = 1;
	int game_speed;
	std::vector<std::pair<std::string, int>> leaderBoard;

	void gameStart();
	void nextLevel();
	void gameOver();
	void gameEnd();
	void showLeaderBoard();
	void addScore(std::string name, int score);



	
	//Game() = default;// nie wiem co to 
};

