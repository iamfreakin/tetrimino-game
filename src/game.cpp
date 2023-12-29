// Game.cpp
#include "../include/game.h"
#include "../include/eventhandler.h"


Game::Game() : eventHandler(new EventHandler()) {
    // 생성자에서 eventHandler를 동적으로 할당
}

Game::~Game() {
    delete eventHandler; // 소멸자에서 할당 해제
}

void Game::run() {
    hide_cursor();

    renderer.drawMap(gameMap);

    while (!isGameOver()) {
        eventHandler->handleInput(*this);

        updateGame();
        renderer.render(gameMap, currentMino);
    }
}

void Game::updateGame() {
    dropBlock();
    if (gameMap.isCollision(currentMino)) {
        // 충돌하면 미노를 맵에 고정하고 새로운 미노 생성
        gameMap.fixMino(currentMino);
        spawnNewMino();
    }
    
    // 행이 가득 찼는지 확인하고, 가득 찬 행이 있다면 지우기
    for (int i = 1; i < gameMap.getHeight() - 1; ++i) {
        if (gameMap.isFullLine(i)) {
            gameMap.clearLine(i);
            renderer.updateMap(gameMap);
        }
    }
}

bool Game::isGameOver() const {
    for (int i = 0; i < gameMap.getWidth(); ++i) {
        if (gameMap.getShell(1, i) != 0) {
            return true;
        }
    }
    return false;
}

void Game::spawnNewMino() {
    currentMino = new Mino();
}

void Game::dropBlock() {
    if (clock() - timeStart > 1000) {
        moveCurrentMinoDown();
        timeStart = clock();
    }
}

void Game::moveCurrentMinoLeft() {
    renderer.eraesMino(currentMino);
    currentMino->moveLeft();

    if (gameMap.isCollision(currentMino)) {
        currentMino->moveRight();
    }

    renderer.drawMino(*currentMino);
}

void Game::moveCurrentMinoRight() {
    renderer.eraesMino(currentMino);
    currentMino->moveRight();

    if (gameMap.isCollision(currentMino)) {
        currentMino->moveLeft();
    }
    
    renderer.drawMino(*currentMino);
}
//매개변수
void Game::moveCurrentMinoDown() {
    renderer.eraesMino(currentMino);
    currentMino->moveDown();

    if (gameMap.isCollision(currentMino)) {
        currentMino->moveUp();
        renderer.drawMino(*currentMino);
        gameMap.fixMino(currentMino);
        spawnNewMino();
    }
    else {
        renderer.drawMino(*currentMino);
    }
}

void Game::rotateCurrentMinoClockwise(){
    renderer.eraesMino(currentMino);
    currentMino->rotateClockwise();

    if (gameMap.isCollision(currentMino)) {
        currentMino->rotateCounterClockwise();
    }
    
    renderer.drawMino(*currentMino);
}

void Game::hide_cursor() {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
