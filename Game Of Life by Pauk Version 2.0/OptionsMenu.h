#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameScreen.h"

#define _GameModeOptions 4
#define _OptionsMenuText 3

class OptionsMenu
{
private:
	sf::Font font;
	sf::Text optionsMenuText[_OptionsMenuText];
	sf::Text percentageText;
	sf::Text speedText;
	sf::Text gameModeText;
	std::string gameModeOptions[_GameModeOptions] = {"Random Color", "Rainbow", "Rainbow On Steroids", "Stripes"};
	std::string speedOptions[4] = { "Slow", "Normal", "Fast (DO NOT USE WITH RAINBOW)", "Ultra Fast (ESPECIALLY DO NOT USE \n          WITH RAINBOW)"};

	int optionsMenuSelected;
	int modeSelected;
	int speedSelected;
	

	void setOptionsMenuText();
	void updateSpeed();



public:
	OptionsMenu();  
	
	void draw(sf::RenderWindow& window);

	void MoveUP();
	void MoveDOWN();
	void MoveLEFT(GameScreen& gameScreen);
	void MoveRIGHT(GameScreen& gameScreen);
	void Selected(); 

	bool KeyPressed(std::string input, GameScreen& gameScreen);

	void updatePercentText(GameScreen& gameScreen);
	void updateGameMode(GameScreen& gameScreen);

	int setSpeed;
};

 