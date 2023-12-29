// EventHandler.cpp
#include "../include/eventHandler.h"
#include "../include/direction.h"

#include <conio.h>

char EventHandler::getInput() {
    if (_kbhit()) {
        return (char)_getch();
    }
    return '\0';
}

void EventHandler::handleInput(Game& game) {
    char input = getInput();

    switch (input) {
        case Directions::Left:
            game.moveCurrentMinoLeft();
            break;
        case Directions::Right:
            game.moveCurrentMinoRight();
            break;
        case Directions::Down:
            game.moveCurrentMinoDown();
            break;
        case Directions::Exit:
            break;
        default:
            break;
    }
}

void EventHandler::handleGameEvents(Game& game) const{
    
}