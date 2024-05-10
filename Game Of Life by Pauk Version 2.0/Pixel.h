#pragma once
#include <SFML/Graphics.hpp>
class Pixel
{
private:
	sf::RectangleShape getColor(int i);

public:
	sf::RectangleShape doRandomColor();
	sf::RectangleShape doRainbow(int i);
	sf::RectangleShape doTrippin();


};

