// Map.h
#pragma once

#include "mino.h"
#include "coordinate.h"

class Map {
private:
    static const int WIDTH = 14;
    static const int HEIGHT = 20;
    int** shell;

public:
    Map();
    ~Map();
    int getWidth() const;
    int getHeight() const;
    int getShell(int y, int x) const;
    void clearLine(int lineNumber);
    bool isCollision(const Mino* mino) const;
    bool isFullLine(int lineNumber) const;
    void fixMino(const Mino* mino);
    void clear();
};