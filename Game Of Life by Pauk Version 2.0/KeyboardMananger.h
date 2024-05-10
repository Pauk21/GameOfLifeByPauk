#pragma once
#include <SFML/Graphics.hpp>
#include "SoundManager.h"
#include <string>

class KeyboardMananger
{
private:
	SoundManager soundManager;

public:
	std::string checkForInput(sf::Event& event);
	void playSound(char input);
};

