#include "AboutMenu.h"

AboutMenu::AboutMenu()
{
	if (!font.loadFromFile("Fonts/C&C Red Alert [LAN].ttf")) {
		std::cout << "Kolega nema ti fonta" << std::endl;
	}

	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString("The Game of Life, also known simply as Life,\nis a cellular automaton devised by the British\nmathematician John Horton Conway in 1970.\nIt is a zero-player game, meaning that its evolution\nis determined by its initial state,\nrequiring no further input.\n\nArrow keys to navigate / move along the board\nEnter to confirm selection / reset board\nEscape to go back\n\nMade by: Pauk");
	text.setCharacterSize(70);
	text.setPosition(200, 150);
}

bool AboutMenu::KeyPressed(std::string input)
{
	return input == "ESCAPE";
}

void AboutMenu::draw(sf::RenderWindow& window)
{
	window.draw(text);
}
