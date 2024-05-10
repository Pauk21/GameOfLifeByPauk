#include "MainMenu.h"


MainMenu::MainMenu()
{
    setMainMenuText();
    mainMenuSelected = 0;

    if (!texture.loadFromFile("Images/bground.png"))
        std::cout << "Fale ti slikice";

    logo.setSize(sf::Vector2f(1920.f, 1080.f));
    logo.setTexture(&texture);

}
 
void MainMenu::Draw(sf::RenderWindow& window)
{
    Selected();
    window.draw(logo);
    for (size_t i = 0; i < _MainMenuOptions; i++)
    {
        window.draw(mainMenuText[i]);
    }
}

int MainMenu::KeyPressed(std::string input)
{
    int selection = -1;
    if (input == "DOWN") MoveDOWN();
    if (input == "UP") MoveUP();
    if (input == "ENTER") selection = ConfirmSelect();

    return selection;
}

void MainMenu::MoveUP()
{
    mainMenuSelected--;
    if (mainMenuSelected == -1) mainMenuSelected = _MainMenuOptions - 1;
}

void MainMenu::MoveDOWN()
{
    mainMenuSelected++;
    if (mainMenuSelected == _MainMenuOptions) mainMenuSelected = 0;
}

void MainMenu::Selected()
{
    for (size_t i = 0; i < _MainMenuOptions; i++)
    {
        if (i == mainMenuSelected) {
            if (i == _MainMenuOptions - 1)
                mainMenuText[i].setFillColor(sf::Color::Red);
            else
                mainMenuText[i].setFillColor(sf::Color::Green);
        }
        else {
            mainMenuText[i].setFillColor(sf::Color::White);
        }
    }
}

int MainMenu::ConfirmSelect()
{
    return mainMenuSelected;
}

void MainMenu::setMainMenuText()
{
    if (!font.loadFromFile("Fonts/C&C Red Alert [LAN].ttf")) {
        std::cout << "Frajeru nema ti fonta!" << std::endl;
    }

    //Play
    mainMenuText[0].setFont(font);
    mainMenuText[0].setFillColor(sf::Color::White);
    mainMenuText[0].setString("Play");
    mainMenuText[0].setCharacterSize(70);
    mainMenuText[0].setPosition(400, 200);

    //Options
    mainMenuText[1].setFont(font);
    mainMenuText[1].setFillColor(sf::Color::White);
    mainMenuText[1].setString("Options");
    mainMenuText[1].setCharacterSize(70);
    mainMenuText[1].setPosition(400, 300);

    //About
    mainMenuText[2].setFont(font);
    mainMenuText[2].setFillColor(sf::Color::White);
    mainMenuText[2].setString("About");
    mainMenuText[2].setCharacterSize(70);
    mainMenuText[2].setPosition(400, 400);

    //Exit
    mainMenuText[3].setFont(font);
    mainMenuText[3].setFillColor(sf::Color::White);
    mainMenuText[3].setString("Exit");
    mainMenuText[3].setCharacterSize(70);
    mainMenuText[3].setPosition(400, 500);
}

MainMenu::~MainMenu()
{
    std::cout << "!!! GIVE ME MA MONEY !!!" << std::endl;
}