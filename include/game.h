// Game.h
#pragma once

#include "Map.h"
#include "Mino.h"
#include "EventHandler.h"
#include "Renderer.h"

class Game {
private:
    Map gameMap;
    Mino currentMino;
    EventHandler eventHandler;
    Renderer renderer;

public:
    void run();
    void spawnNewMino();
    void updateGame();
    bool isGameOver() const;
    void moveCurrentMinoLeft();
    void moveCurrentMinoRight();
    void moveCurrentMinoDown();
    void rotateCurrentMinoClockwise();
    void rotateCurrentMinoCounterClockwise();
};