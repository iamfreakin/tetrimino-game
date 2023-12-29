// Mino.h
#pragma once

#include "coordinate.h"
#include <cstdlib>
#include <ctime>

class Mino { //블럭자체만 구현 구조체로
                //물리계산 클래스 따로 만들기
private:
    static const int SIZE = 4;
    static const int NUMBER = 7;

    Coordinate shape[SIZE];
    Coordinate minoshape[NUMBER][SIZE] = { //블럭에 좌표값 추가하지 않고 해봐야할듯
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
            {7,1},
            {8,1},
            {8,2}
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
    void setRandomShape(); //game으로 옮기기
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    void rotateClockwise();
    void rotateCounterClockwise();
    
};