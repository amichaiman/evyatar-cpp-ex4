#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

inline void invalidInput() { std::cerr << "ERROR: Invalid input." << std::endl; }

int main(int argc, char** argv) {
    Game game;
    srand(time(NULL));
    if (argc != 3){
        invalidInput();
        exit(1);
    }
    if (!game.config(argv[1]) ||  !game.init(argv[2])) {
        invalidInput();
        exit(2);
    }
    game.start();
    return 0;
}
