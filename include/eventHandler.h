// EventHandler.h
#pragma once

#include "Game.h"
#include "direction.h"

class EventHandler {
private:
    char getInput();

public:
    void handleInput(Game& game);
    void handleGameEvents(Game& game) const;
};