#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Pixel.h"
class GameScreen
{
private:

	Pixel pixel;

	int startI;
	int startJ;

	bool hasPixel = false;
	int gameBoardWidth = 384;
	int gameBoardHeight = 216;
	int fullGameBoardHeight = gameBoardHeight * 2;
	int fullGameBoardWidth = gameBoardWidth * 2;
	bool* gameBoard = new bool[fullGameBoardHeight * fullGameBoardWidth];
	bool* swapBoard = new bool[fullGameBoardHeight * fullGameBoardWidth];
	
	int colorIndex = 0;

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	sf::RectangleShape cell;
public:
	GameScreen();

	void Update(sf::RenderWindow& window);
	void swapBoards();
	void logic();
	bool isAlive(int i, int j);
	void resetBoard();
	bool setLiveCell();
	bool KeyPressed(std::string input);

	// Varijable koje korisnik mijenja
	int percFilledOnStart = 25;
	int speed = 69;
	bool doRandomColor = true;
	bool doRainbow = false;
	bool doRainbowOnSteroids = false;
	bool doStripes = false;
};

