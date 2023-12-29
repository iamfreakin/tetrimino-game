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
     Game(); // �����ڿ��� eventHandler�� �������� �Ҵ�
    ~Game(); // �Ҹ��ڿ��� �Ҵ� ����

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