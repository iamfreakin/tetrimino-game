// Renderer.h
#pragma once

#include "map.h"
#include "mino.h"

class Renderer {
private:
    void setCursorPosition(int x, int y) const;

public:
    void render(const Map& gameMap, const Mino* currentMino);
    void eraesMino(const Mino* currentMino);
    void updateMap(const Map& gameMap);
    void drawMino(const Mino* currentMino);
    void drawMap(const Map& gameMap);
    void drawBlocks(const Map& gameMap);
};