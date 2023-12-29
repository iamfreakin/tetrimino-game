// Game.cpp
#include "../include/game.h"
#include "../include/eventhandler.h"


Game::Game() : eventHandler(new EventHandler()) {
    // �����ڿ��� eventHandler�� �������� �Ҵ�
}

Game::~Game() {
    delete eventHandler; // �Ҹ��ڿ��� �Ҵ� ����
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
        // �浹�ϸ� �̳븦 �ʿ� �����ϰ� ���ο� �̳� ����
        gameMap.fixMino(currentMino);
        spawnNewMino();
    }
    
    // ���� ���� á���� Ȯ���ϰ�, ���� �� ���� �ִٸ� �����
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
//�Ű�����
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
