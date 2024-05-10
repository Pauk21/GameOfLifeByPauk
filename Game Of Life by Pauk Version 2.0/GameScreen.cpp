#include "GameScreen.h"


GameScreen::GameScreen()
{
	resetBoard();
}

void GameScreen::Update(sf::RenderWindow& window)
{

	if (doRandomColor && !hasPixel) {
		cell = pixel.doRandomColor();
		hasPixel = true;
	}

	if (doRainbow) {
		cell = pixel.doRainbow(colorIndex);
		colorIndex++;
		if (colorIndex == 6) colorIndex = 0;
	}
	

	for (size_t i = startI; i < startI + gameBoardHeight; i++){
		for (size_t j = startJ; j < startJ + gameBoardWidth; j++) {
			if (*(gameBoard + i * fullGameBoardWidth + j)) {
				if (doRainbowOnSteroids) {
						cell = pixel.doTrippin();
						cell.setPosition((j - startJ) * 5.f, (i - startI) * 5.f);
						window.draw(cell);
				}
				else if (doStripes) {
					if (i % 10 == 0) cell = pixel.doRandomColor();
					cell.setPosition((j - startJ) * 5.f, (i - startI) * 5.f);
					window.draw(cell);
				}
				else {
					cell.setPosition((j - startJ) * 5.f, (i - startI) * 5.f);
					window.draw(cell);
				}

			}
		}
	}
	logic();
}

void GameScreen::swapBoards()
{
	for (size_t i = 0; i < fullGameBoardHeight; i++) {
		for (size_t j = 0; j < fullGameBoardWidth; j++) {
			*(gameBoard + i * fullGameBoardWidth + j) = *(swapBoard + i * fullGameBoardWidth + j);
		}
	}
}

void GameScreen::logic()
{
	for (size_t i = 0; i < fullGameBoardHeight; i++) {
		for (size_t j = 0; j < fullGameBoardWidth; j++) {
			*(swapBoard + i * fullGameBoardWidth + j) = isAlive(i, j);
		}
	}

	swapBoards();
}

bool GameScreen::isAlive(int i, int j)
{
	//Broj zivih susjeda jedne celije
	int numberAlive = 0;

	//provjera lijevo
	if (j > 0 && *(gameBoard + i * fullGameBoardWidth + j - 1)) numberAlive++;
	//projevra desno
	if (j < (fullGameBoardWidth - 1) && *(gameBoard + i * fullGameBoardWidth + j + 1)) numberAlive++;
	//provjera gore
	if (i > 0 && *(gameBoard + i * fullGameBoardWidth + j - fullGameBoardWidth)) numberAlive++;
	//provjera dolje
	if (i < (fullGameBoardHeight - 1) && *(gameBoard + i * fullGameBoardWidth + j + fullGameBoardWidth)) numberAlive++;

	//provjera lijevo gore
	if (i > 0 && j > 0 && *(gameBoard + i * fullGameBoardWidth + j - fullGameBoardWidth - 1)) numberAlive++;
	//provjera desno gore
	if (j < (fullGameBoardWidth - 1) && i > 0 && *(gameBoard + i * fullGameBoardWidth + j - fullGameBoardWidth + 1)) numberAlive++;
	//provjera lijevo dolje
	if (j > 0 && i < (fullGameBoardHeight - 1) && *(gameBoard + i * fullGameBoardWidth + j + fullGameBoardWidth - 1)) numberAlive++;
	//provjera desno dolje
	if (i < (fullGameBoardHeight - 1) && j < (fullGameBoardWidth - 1) && *(gameBoard + i * fullGameBoardWidth + j + fullGameBoardWidth + 1)) numberAlive++;


	//Decision make na temelju koliko je zivih susjeda
	if (*(gameBoard + i * fullGameBoardWidth + j) && (numberAlive == 2 || numberAlive == 3))
		return true;
	else if (*(gameBoard + i * fullGameBoardWidth + j) && (numberAlive < 2 || numberAlive > 3))
		return false;
	else if (!*(gameBoard + i * fullGameBoardWidth + j) && numberAlive == 3)
		return true;
}

void GameScreen::resetBoard()
{
	startI = (fullGameBoardHeight - 216) / 2;
	startJ = (fullGameBoardWidth - 384) / 2;

	for (size_t i = 0; i < fullGameBoardHeight; i++) {
		for (size_t j = 0; j < fullGameBoardWidth; j++) {
			*(gameBoard + i * fullGameBoardWidth + j) = setLiveCell();
		}
	}
	hasPixel = false;
}

bool GameScreen::setLiveCell()
{
	return (rand() % 100) < percFilledOnStart;
}

bool GameScreen::KeyPressed(std::string input)
{
	bool retValue = false;

	if (input == "ESCAPE")
		retValue = true;
	if (input == "LEFT")
		moveLeft();
	if (input == "RIGHT")
		moveRight();
	if (input == "UP")
		moveUp();
	if (input == "DOWN")
		moveDown();

	return retValue;
}

void GameScreen::moveLeft()
{
	if (startJ > 0)
		startJ--;
}

void GameScreen::moveRight()
{
	if (startJ < fullGameBoardWidth - 1)
		startJ++;
}

void GameScreen::moveUp()
{
	if (startI > 9)
		startI--;
}

void GameScreen::moveDown()
{
	if (startI < fullGameBoardHeight - 1)
		startI++;
}