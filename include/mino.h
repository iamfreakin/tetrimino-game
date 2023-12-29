// Mino.h
#pragma once

#include "coordinate.h"
#include <cstdlib>
#include <ctime>

class Mino {
private:
    static const int SIZE = 4;
    static const int NUMBER = 7;

    Coordinate shape[SIZE];
    Coordinate minoshape[NUMBER][SIZE] = {
        {
            {6,1},
            {6,2},
            {6,3},
            {6,4}
        },
        {
            {6,1},
            {6,2},
            {7,1},
            {7,2}
        },
        {
            {6,2},
            {7,1},
            {7,2},
            {7,3}
        },
        {
            {6,2},
            {6,3},
            {7,1},
            {7,2}
        },
        {
            {6,1},
            {6,2},
            {7,2},
            {7,3}
        },
        {
            {6,1},
            {6,2},
            {7,2},
            {7,2}
        },
        {
            {7,1},
            {7,2},
            {7,3},
            {6,3}
        }
    };


public:
    Mino();
    const Coordinate* getShape() const;
    void setRandomShape();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    void rotateClockwise();
    void rotateCounterClockwise();
};