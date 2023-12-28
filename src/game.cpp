// Game.cpp
#include "../include/game.h"
#include <iostream>

void Game::run() {
    while (!isGameOver()) {
        updateGame();
        renderer.render(gameMap, currentMino);
    }

    std::cout << "Game Over!" << std::endl;
}

void Game::updateGame() {
    if (gameMap.isCollision(currentMino)) {
        // �浹�ϸ� �̳븦 �ʿ� �����ϰ� ���ο� �̳� ����
        gameMap.fixMino(currentMino);
        spawnNewMino();
    }
    
    // ���� ���� á���� Ȯ���ϰ�, ���� �� ���� �ִٸ� �����
    for (int i = 1; i < gameMap.getHeight() - 1; ++i) {
        if (gameMap.isFullLine(i)) {
            gameMap.clearLine(i);
        }
    }
}

bool Game::isGameOver() const {
    for (int i = 0; i < gameMap.getWidth(); ++i) {
        if (gameMap.getShell(1, i) == 1) {
            return true;
        }
    }
    return false;
}

void Game::spawnNewMino() {
    currentMino = Mino();
}

void Game::moveCurrentMinoLeft() {
    renderer.eraesMino(currentMino);
    currentMino.moveLeft();

    if (gameMap.isCollision(currentMino)) {
        currentMino.moveRight();
    }

    renderer.drawMino(currentMino);
}

void Game::moveCurrentMinoRight() {
    renderer.eraesMino(currentMino);
    currentMino.moveRight();

    if (gameMap.isCollision(currentMino)) {
        currentMino.moveLeft();
    }
    
    renderer.drawMino(currentMino);
}

void Game::moveCurrentMinoDown() {
    renderer.eraesMino(currentMino);
    currentMino.moveDown();

    if (gameMap.isCollision(currentMino)) {
        currentMino.moveUp();
        renderer.drawMino(currentMino);
        gameMap.fixMino(currentMino);
        spawnNewMino();
    }
    else {
        renderer.drawMino(currentMino);
    }
}