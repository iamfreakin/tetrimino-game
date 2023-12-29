// Game.h
#pragma once

#include <ctime>
#include <windows.h>

#include "map.h"
#include "mino.h"
#include "eventHandler.h"
#include "renderer.h"

class EventHandler;

class Renderer;

class Game {
private:
    Map gameMap;
    Mino* currentMino;
    EventHandler* eventHandler;
    Renderer renderer;
    clock_t timeStart;

public:
     Game(); // 생성자에서 eventHandler를 동적으로 할당
    ~Game(); // 소멸자에서 할당 해제

    void run();
    void spawnNewMino();
    void updateGame();
    bool isGameOver() const;
    void dropBlock();
    void moveCurrentMinoLeft();
    void moveCurrentMinoRight();
    void moveCurrentMinoDown();
    void rotateCurrentMinoClockwise();
    void hide_cursor();
    
};