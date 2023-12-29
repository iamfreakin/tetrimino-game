// Mino.cpp
#include "../include/mino.h"

Mino::Mino() {
    shape[0] = {5, 1};
    shape[1] = {6, 1};
    shape[2] = {5, 2};
    shape[3] = {6, 2};
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
    for (int i = 0; i < SIZE; ++i) {
        int temp = shape[i].X;
        shape[i].X = shape[i].Y;
        shape[i].Y = -temp;
    }
}

void Mino::rotateCounterClockwise() {
    for (int i = 0; i < SIZE; ++i) {
        int temp = shape[i].X;
        shape[i].X = -shape[i].Y;
        shape[i].Y = temp;
    }
}