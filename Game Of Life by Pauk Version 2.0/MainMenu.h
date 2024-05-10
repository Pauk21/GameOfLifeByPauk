#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define _MainMenuOptions 4

class MainMenu
{
private:
	sf::RectangleShape logo;
	sf::Texture texture;
	sf::Font font;
	sf::Text mainMenuText[_MainMenuOptions];
	int mainMenuSelected;
	
	void setMainMenuText();
public:
	MainMenu();

	void Draw(sf::RenderWindow& window);
	int KeyPressed(std::string input);
	void MoveUP();
	void MoveDOWN();
	void Selected();

	int ConfirmSelect();

	~MainMenu();
};

