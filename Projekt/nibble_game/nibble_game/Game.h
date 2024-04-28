#pragma once
#include <iostream>
#include <vector>

class Game
{
public:
	Game(int game_speed);
	int score = 0;
	int level = 1;
	int game_speed;
	std::vector<std::pair<std::string, int>> leaderBoard;

	void gameStart();
	void gameOver();
	void gameEnd();
	void showLeaderBoard();
	void addScore(std::string name, int score);



	
	Game() = default;// nie wiem co to 
};

