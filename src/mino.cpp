// Mino.cpp
#include "../include/mino.h"

Mino::Mino() {

    setRandomShape();
}

void Mino::setRandomShape() {
    std::srand(std::time(0));
    int randomIndex = std::rand() % 7;
    for (int i = 0; i < SIZE; ++i) {
        shape[i] = minoshape[randomIndex][i];
    }
}

const Coordinate* Mino::getShape() const {
    return shape;
}

void Mino::moveLeft() {
    for (int i = 0; i < SIZE; ++i) {
        shape[i].X -= 1;
    }
}

void Mino::moveRight() {
    for (int i = 0; i < SIZE; ++i) {
        shape[i].X += 1;
    }
}

void Mino::moveDown() {
    for (int i = 0; i < SIZE; ++i) {
        shape[i].Y += 1;
    }
}

void Mino::moveUp() {
    for (int i = 0; i < SIZE; ++i) {
        shape[i].Y -= 1;
    }
}

void Mino::rotateClockwise() {
    int tempx = shape[0].X;
    int tempy = shape[0].Y;
    for (int i = 0; i < SIZE; ++i) {
        int temp = shape[i].X - tempx;
        shape[i].X = shape[i].Y - tempy + tempx;
        shape[i].Y = -temp + tempy;
        
    }
}

void Mino::rotateCounterClockwise() {
    for (int i = 0; i < SIZE; ++i) {
        int temp = shape[i].X;
        shape[i].X = -shape[i].Y;
        shape[i].Y = temp;
    }
}