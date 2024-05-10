#include "Pixel.h"

sf::RectangleShape Pixel::getColor(int i)
{
	sf::RectangleShape cell(sf::Vector2f(3.0f, 3.0f));

	switch (i)
	{
	case 0:
		cell.setFillColor(sf::Color::Red);
		break;
	case 1:
		cell.setFillColor(sf::Color::Yellow);
		break;
	case 2:
		cell.setFillColor(sf::Color::Green);
		break;
	case 3:
		cell.setFillColor(sf::Color::Cyan);
		break;
	case 4:
		cell.setFillColor(sf::Color::Blue);
		break;
	case 5:
		cell.setFillColor(sf::Color::Magenta);
		break;
	case 6:
		cell.setFillColor(sf::Color::White);
		break;
	}

	return cell;
}

sf::RectangleShape Pixel::doRandomColor()
{

	sf::RectangleShape cell(sf::Vector2f(3.0f, 3.0f));

	cell = getColor(rand() % 7);

	return cell;
}

sf::RectangleShape Pixel::doRainbow(int i)
{
	sf::RectangleShape cell(sf::Vector2f(3.0f, 3.0f));

	cell = getColor(i);
	
    return cell;
}

sf::RectangleShape Pixel::doTrippin()
{

	sf::RectangleShape cell(sf::Vector2f(3.0f, 3.0f));

	cell = getColor(rand() % 6);
    return cell;
}
