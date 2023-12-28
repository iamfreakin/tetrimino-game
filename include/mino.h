// Mino.h
#pragma once

#include "Coordinate.h"

class Mino {
private:
    static const int SIZE = 4;
    Coordinate shape[SIZE];

public:
    Mino();
    const Coordinate* getShape() const;
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    void rotateClockwise();
    void rotateCounterClockwise();
};