#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class AboutMenu
{
private:
	sf::Text text;
	sf::Font font;
public:
	AboutMenu();
	bool KeyPressed(std::string input);
	void draw(sf::RenderWindow& window);
};

