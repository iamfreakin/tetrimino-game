// EventHandler.h
#pragma once

#include <conio.h>

#include "game.h"

class Game;

class EventHandler { //이름 다시생각하기
private:
    char getInput();

public:
    void handleInput(Game& game);
    void handleGameEvents(Game& game) const;
};