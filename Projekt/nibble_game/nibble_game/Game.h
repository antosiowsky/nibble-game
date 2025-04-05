#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <ranges>
#include <thread>
//#include <SFML/Audio.hpp>
#include "Frame.h"
#include "Snake.h"
#include "Point.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(int game_speed, float windowWidth, float windowHeight);
	int score = 0;
	int lives = 15;
	int scoreMultiplier = 1;
	int level = 1;
	int game_speed;
	float windowWidth;
	float windowHeight;

	std::vector<std::pair<std::string, int>> leaderBoard;

	void gameStart();
	void gameEnd();

	float getWindowWidth() const { return windowWidth; }
	float getWindowHeight() const { return windowHeight; }

	friend class Snake;
};

