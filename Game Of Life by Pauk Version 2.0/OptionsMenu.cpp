#include "OptionsMenu.h"

OptionsMenu::OptionsMenu()
{
    setOptionsMenuText();
    optionsMenuSelected = 0;
    modeSelected = 0;
    speedSelected = 1;
    setSpeed = 69;
    updateSpeed();
}

void OptionsMenu::draw(sf::RenderWindow& window)
{
    Selected();
    for (int i = 0; i < _OptionsMenuText; i++)
        window.draw(optionsMenuText[i]);
    window.draw(gameModeText);
    window.draw(percentageText);
    window.draw(speedText);
}

void OptionsMenu::setOptionsMenuText()
{
    if (!font.loadFromFile("Fonts/C&C Red Alert [LAN].ttf")) {
        std::cout << "Kolega nema ti fonta!";
    }

    //Mode
    optionsMenuText[0].setFont(font);
    optionsMenuText[0].setFillColor(sf::Color::White);
    optionsMenuText[0].setString("Mode: ");
    optionsMenuText[0].setCharacterSize(70);
    optionsMenuText[0].setPosition(400, 200);

    // Percentage filled
    optionsMenuText[1].setFont(font);
    optionsMenuText[1].setFillColor(sf::Color::White);
    optionsMenuText[1].setString("Percentage Filled: ");
    optionsMenuText[1].setCharacterSize(70);
    optionsMenuText[1].setPosition(400, 300);

    // Speed
    optionsMenuText[2].setFont(font);
    optionsMenuText[2].setFillColor(sf::Color::White);
    optionsMenuText[2].setString("Speed: ");
    optionsMenuText[2].setCharacterSize(70);
    optionsMenuText[2].setPosition(400, 400);

    // Mode Selection
    gameModeText.setFont(font);
    gameModeText.setFillColor(sf::Color::White);
    gameModeText.setString(gameModeOptions[modeSelected]);
    gameModeText.setCharacterSize(70);
    gameModeText.setPosition(600, 200);

    // Percentage
    percentageText.setFont(font);
    percentageText.setFillColor(sf::Color::White);
    percentageText.setString("25%");
    percentageText.setCharacterSize(70);
    percentageText.setPosition(930, 300);

    // Speed
    speedText.setFont(font);
    speedText.setFillColor(sf::Color::White);
    speedText.setString("Normal");
    speedText.setCharacterSize(70);
    speedText.setPosition(630, 400);

}


void OptionsMenu::MoveUP()
{
    optionsMenuSelected--;
    if (optionsMenuSelected == -1) optionsMenuSelected = _OptionsMenuText - 1;
}

void OptionsMenu::MoveDOWN()
{
    optionsMenuSelected++;
    if (optionsMenuSelected == _OptionsMenuText) optionsMenuSelected = 0;
}

void OptionsMenu::MoveLEFT(GameScreen& gameScreen) {
    switch (optionsMenuSelected)
    {
    case 0:
        modeSelected--;
        if (modeSelected == -1) modeSelected = _GameModeOptions - 1;
        gameModeText.setString(gameModeOptions[modeSelected]);
        updateGameMode(gameScreen);
        break;

    case 1:
        gameScreen.percFilledOnStart--;
        if (gameScreen.percFilledOnStart < 0) gameScreen.percFilledOnStart = 0;
        updatePercentText(gameScreen);
        gameScreen.resetBoard();
        break;

    case 2:
        speedSelected--;
        if (speedSelected == -1) speedSelected = 3;
        speedText.setString(speedOptions[speedSelected]);
        updateSpeed();
    }
}

void OptionsMenu::MoveRIGHT(GameScreen& gameScreen) {
    switch (optionsMenuSelected)
    {
    case 0:
        modeSelected++;
        if (modeSelected == _GameModeOptions) modeSelected = 0;
        gameModeText.setString(gameModeOptions[modeSelected]);
        updateGameMode(gameScreen);
        break;
        
    case 1:
        gameScreen.percFilledOnStart++;
        if (gameScreen.percFilledOnStart > 100) gameScreen.percFilledOnStart = 100;
        updatePercentText(gameScreen);
        gameScreen.resetBoard();
        break;

    case 2:
        speedSelected++;
        if (speedSelected == 4) speedSelected = 0;
        speedText.setString(speedOptions[speedSelected]);
        updateSpeed();
        break;
    }
}

void OptionsMenu::Selected()
{
    for (size_t i = 0; i < _OptionsMenuText; i++)
    {
        if (i == optionsMenuSelected) {
            optionsMenuText[i].setFillColor(sf::Color::Green);
            if (i == 0) {
                gameModeText.setFillColor(sf::Color::Green);
                percentageText.setFillColor(sf::Color::White);
                speedText.setFillColor(sf::Color::White);
            }
            else if (i == 1) {
                gameModeText.setFillColor(sf::Color::White);
                percentageText.setFillColor(sf::Color::Green);
                speedText.setFillColor(sf::Color::White);
            }
            else if (i == 2) {
                gameModeText.setFillColor(sf::Color::White);
                percentageText.setFillColor(sf::Color::White);
                speedText.setFillColor(sf::Color::Green);
            }
        }
        else {
            optionsMenuText[i].setFillColor(sf::Color::White);
        }
    }
}

bool OptionsMenu::KeyPressed(std::string input, GameScreen& gameScreen)
{
    bool ret = false;
    if (input == "DOWN") MoveDOWN();
    if (input == "UP") MoveUP();
    if (input == "RIGHT") MoveRIGHT(gameScreen);
    if (input == "LEFT") MoveLEFT(gameScreen);
    if (input == "ESCAPE") ret = true;

    return ret;
}

void OptionsMenu::updatePercentText(GameScreen& gameScreen)
{
    percentageText.setString(std::to_string(gameScreen.percFilledOnStart) + "%");
}

void OptionsMenu::updateGameMode(GameScreen& gameScreen)
{
    switch (modeSelected)
    {
    case 0:
        gameScreen.doRandomColor = true;
        gameScreen.doRainbow = false;
        gameScreen.doRainbowOnSteroids = false;
        gameScreen.doStripes = false;
        break;
    case 1:
        gameScreen.doRandomColor = false;
        gameScreen.doRainbow = true;
        gameScreen.doRainbowOnSteroids = false;
        gameScreen.doStripes = false;
        break;
    case 2:
        gameScreen.doRandomColor = false;
        gameScreen.doRainbow = false;
        gameScreen.doRainbowOnSteroids = true;
        gameScreen.doStripes = false;
        break;

    case 3:
        gameScreen.doRandomColor = false;
        gameScreen.doRainbow = false;
        gameScreen.doRainbowOnSteroids = false;
        gameScreen.doStripes = true;
        break;
    }
}

void OptionsMenu::updateSpeed()
{
    switch (speedSelected)
    {
    case 0:
        setSpeed = 500;
        break;

    case 1:
        setSpeed = 200;
        break;

    case 2:
        setSpeed = 30;
        break;

    case 3:
        setSpeed = 1;
        break;
    }
}