#include "SoundManager.h"

SoundManager::SoundManager()
{
	if (!Gore.loadFromFile("Sounds/Gore.wav"))
		std::cout << "Fale ti soundovi";

	if (!Dolje.loadFromFile("Sounds/Dolje.wav"))
		std::cout << "Fale ti soundovi";

	if (!Escape.loadFromFile("Sounds/Nazad.wav"))
		std::cout << "Fale ti soundovi";

	if (!Enter.loadFromFile("Sounds/Enter.wav"))
		std::cout << "Fale ti soundovi";

	if (!Lijevo.loadFromFile("Sounds/Lijevo.wav"))
		std::cout << "Fale ti soundovi";

	if (!Desno.loadFromFile("Sounds/Desno.wav"))
		std::cout << "Fale ti soundovi";

	if (!bgMus.loadFromFile("Sounds/bg.ogg"))
		std::cout << "Fale ti soundovi";
}
