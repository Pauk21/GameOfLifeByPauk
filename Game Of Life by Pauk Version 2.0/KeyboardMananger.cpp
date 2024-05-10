#include "KeyboardMananger.h"

std::string KeyboardMananger::checkForInput(sf::Event& event)
{
    if (event.key.code == sf::Keyboard::Left) {
        playSound('L');
        return "LEFT";
    }
    if (event.key.code == sf::Keyboard::Right) {
        playSound('R');
        return "RIGHT";
    }
    if (event.key.code == sf::Keyboard::Up) {
        playSound('U');
        return "UP";
    }
    if (event.key.code == sf::Keyboard::Down) {
        playSound('D');
        return "DOWN";
    }
    if (event.key.code == sf::Keyboard::Enter) {
        playSound('E');
        return "ENTER";
    }
    if (event.key.code == sf::Keyboard::Escape) {
        playSound('B');
        return "ESCAPE";
    }

    return "NULL";
}

void KeyboardMananger::playSound(char input)
{
    switch (input)
    {
    case 'L':
        soundManager.sound.setBuffer(soundManager.Lijevo);
        soundManager.sound.play();
        break;
    case 'R':
        soundManager.sound.setBuffer(soundManager.Desno);
        soundManager.sound.play();
        break;
    case 'U':
        soundManager.sound.setBuffer(soundManager.Gore);
        soundManager.sound.play();
        break;
    case 'D':
        soundManager.sound.setBuffer(soundManager.Dolje);
        soundManager.sound.play();
        break;
    case 'E':
        soundManager.sound.setBuffer(soundManager.Enter);
        soundManager.sound.play();
        break;
    case 'B':
        soundManager.sound.setBuffer(soundManager.Escape);
        soundManager.sound.play();
        break;
    }
}
