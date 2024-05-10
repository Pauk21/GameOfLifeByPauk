#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

class SoundManager
{
private:


public:
	SoundManager();
	sf::Sound sound;
	sf::Sound bgMusic;
	sf::SoundBuffer bgMus;
	sf::SoundBuffer Gore;
	sf::SoundBuffer Dolje;
	sf::SoundBuffer Escape;
	sf::SoundBuffer Enter;
	sf::SoundBuffer Lijevo;
	sf::SoundBuffer Desno;
};

