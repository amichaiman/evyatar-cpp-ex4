
#include "Game.h"
#include "Limits.h"
#include <iostream>
#include <fstream>
/*the big three are not necessary here*/
Game::Game() {
    arena.setPlayers(&players);
}
/*this function starts the game */
void Game::start() {
    int iteration;
    for (iteration=0; iteration < numOfIterations; iteration++){
        players.update();
        arena.update(players);
        if (arena.isObjectiveReached()){
            break;
        }
    }
    std::cout << iteration << std::endl;
    players.printInfo();
}
/*reads input from the file*/
bool Game::config(char *fileName) {
    std::ifstream file;
    file.open(fileName, std::ios::in);

    if (!file.is_open()){
        return false;
    }
    Point p;
    file >> p.x >> p.y;
    if (!goodFileState(file)) {
        return false;
    }

    if (!Limits::inArena(p)) {
        return false;
    }
    players.setObjective(p);

    int numOfIterations;
    file >> numOfIterations;

    if (!goodFileState(file)) {
        return false;
    }

    if (numOfIterations < Limits::MIN_ITERATIONS || numOfIterations > Limits::MAX_ITERATIONS){
        return false;
    }
    Game::numOfIterations = numOfIterations;
    return true;
}

bool Game::init(char *fileName) {
    return players.init(fileName);
}
/*checks if the file is valid*/
bool Game::goodFileState(const std::ifstream &file) {
    return !file.fail() && !file.bad();
}
