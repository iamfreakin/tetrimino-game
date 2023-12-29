// main.cpp
#include <iostream>

#include "../include/game.h"

#include "game.cpp"
#include "eventHandler.cpp"
#include "map.cpp"
#include "mino.cpp"
#include "renderer.cpp"


int main() {
    Game* game = new Game();
    game->run();

    return 0;
}