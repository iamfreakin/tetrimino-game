// Map.cpp
#include "../include/map.h"

Map::Map() {
    // Initialize the map
    shell = new int*[HEIGHT];
    for (int i = 0; i < HEIGHT; ++i) {
        shell[i] = new int[WIDTH]();
    }
}

Map::~Map() {
    // Deallocate memory
    for (int i = 0; i < HEIGHT; ++i) {
        delete[] shell[i];
    }
    delete[] shell;
}

int Map::getWidth() const {
    return WIDTH;
}

int Map::getHeight() const {
    return HEIGHT;
}

int Map::getShell(int y, int x) const {
    return shell[y][x];
}

void Map::clearLine(int lineNumber) {
    // Clear a line in the map
    for (int i = lineNumber; i > 0; --i) {
        for (int j = 0; j < WIDTH; ++j) {
            shell[i][j] = shell[i - 1][j];
        }
    }
}

bool Map::isCollision(const Mino& mino) const {
    for (int i = 0; i < 4; i++) {
        int x = mino.getShape()[i].X;
        int y = mino.getShape()[i].Y;

        if (y >= HEIGHT + 1 || x <= 0 || x >= WIDTH + 1 || shell[y][x] != 0) {
            return true;
        }
    }
    return false; // 충돌 없음
}

bool Map::isFullLine(int lineNumber) const {
    // 특정 행이 가득 찼는지 확인
    for (int j = 1; j < WIDTH + 1; j++) {
        if (shell[lineNumber][j] == 0) {
            return false; // 비어있는 곳이 있으면 가득 차지 않음
        }
    }
    return true; // 가득 참

}

void Map::fixMino(const Mino& mino) {
    // 미노를 맵에 고정
    for (int i = 0; i < 4; i++) {
        int x = mino.getShape()[i].X;
        int y = mino.getShape()[i].Y;

        if (y >= 1 && y <= HEIGHT && x >= 1 && x <= WIDTH) {
            shell[y][x] = 1;
        }
    }
}

void Map::clear() {
    // Clear the entire map
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            shell[i][j] = 0;
        }
    }
}