#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.h"
#include "AboutMenu.h"
#include "OptionsMenu.h"
#include "GameScreen.h"
#include "KeyboardMananger.h"

int main() {
	//Kreiranje svih klasa/objekata
	MainMenu MainMenu;
	AboutMenu AboutMenu;
	GameScreen GameScreen;
	OptionsMenu OptionsMenu;
	KeyboardMananger KeyboardManager;
	SoundManager soundManager;


	sf::Clock frameClock;


	//Kreiranje varijabli
	int optionSelected = -1; //-1 znaci da nije selectano nista jos
	bool goBack = false;

	// Settings za Windowe
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Kreira se glavni Window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game of Life by PAUK", sf::Style::Fullscreen, settings);

	soundManager.bgMusic.setBuffer(soundManager.bgMus);
	soundManager.bgMusic.play();
	soundManager.bgMusic.setLoop(true);

	while (window.isOpen()) {
		
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed) // Ako je neki key stisnut pogledaj koji
				optionSelected = MainMenu.KeyPressed(KeyboardManager.checkForInput(event, false));

			switch (optionSelected)
			{
			case 0: // PLAY
				while (!goBack)
				{
					
					while (window.pollEvent(event)) {
						if (event.type == sf::Event::KeyPressed) {
							if (event.key.code == sf::Keyboard::Enter)
								GameScreen.resetBoard();
							goBack = GameScreen.KeyPressed(KeyboardManager.checkForInput(event, true));
						}
					}
					sf::Time elapsed = frameClock.getElapsedTime();
					if (elapsed.asMilliseconds() >= OptionsMenu.setSpeed) {
						window.clear();
						GameScreen.Update(window);
						window.display();
						frameClock.restart();
					}
				}
				optionSelected = -1;
				goBack = false;
				break;

			case 1: // OPTIONS
				while (!goBack) {
					while (window.pollEvent(event)) {
						if (event.type == sf::Event::KeyPressed)
							goBack = OptionsMenu.KeyPressed(KeyboardManager.checkForInput(event, false), GameScreen);
					}
					window.clear();
					OptionsMenu.draw(window);
					window.display();
				}
				optionSelected = -1;
				goBack = false;
				break;

			case 2: // ABOUT
				while (!goBack) {
					while (window.pollEvent(event)) {
						if (event.type == sf::Event::KeyPressed) // Ako je neki key stisnut pogledaj koji
							goBack = AboutMenu.KeyPressed(KeyboardManager.checkForInput(event, false));
					}
					window.clear();
					AboutMenu.draw(window);
					window.display();								
				}
				optionSelected = -1;
				goBack = false;
				break;

			case 3: // EXIT
				window.close();
				break;
			}
		}

		window.clear();
		MainMenu.Draw(window);
		window.display();
	}
}

