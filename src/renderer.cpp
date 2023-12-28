// Renderer.cpp
#include "../include/renderer.h"
#include <iostream>
#include <windows.h>

void Renderer::setCursorPosition(int x, int y) const {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){(short)x, (short)y});
}

void Renderer::render(const Map& gameMap, const Mino& currentMino) {
    drawMap(gameMap);
    drawBlocks(gameMap);
    drawMino(currentMino);
}

void Renderer::eraesMino(const Mino& currentMino) {
    for (int i = 0; i < 4; ++i) {
        int x = currentMino.getShape()[i].X;
        int y = currentMino.getShape()[i].Y;
        setCursorPosition(x, y);
        std::cout << " ";
    }
}

void Renderer::drawMino(const Mino& currentMino) { 
    for (int i = 0; i < 4; ++i) {
        int x = currentMino.getShape()[i].X;
        int y = currentMino.getShape()[i].Y;
        setCursorPosition(x, y);
        std::cout << "■";
    }
}

void Renderer::drawMap(const Map& gameMap) {
    system("cls");
    for (int i = 0; i < gameMap.getHeight(); ++i) {
        for (int j = 0; j < gameMap.getWidth(); ++j) {
            if (i == 0 || i == gameMap.getHeight() - 1 || j == 0 || j == gameMap.getWidth() - 1) {
                setCursorPosition(j, i);
                std::cout << "#";  // 테두리를 '#'로 표시
            }
        }
    }
}

void Renderer::drawBlocks(const Map& gameMap) {
    for (int y = 1; y < gameMap.getHeight() - 1; ++y) {
        for (int x = 1; x < gameMap.getWidth() - 1; ++x) {
            if (gameMap.getShell(y, x) == 1) {
                setCursorPosition(x, y);
                std::cout << "X";
            }
        }
    }
}