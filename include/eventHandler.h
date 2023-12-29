// EventHandler.h
#pragma once

#include <conio.h>

#include "game.h"

class Game;

class EventHandler { //�̸� �ٽû����ϱ�
private:
    char getInput();

public:
    void handleInput(Game& game);
    void handleGameEvents(Game& game) const;
};