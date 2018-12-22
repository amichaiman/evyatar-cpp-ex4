

#ifndef EVYATAR_CPP_3_GAME_H
#define EVYATAR_CPP_3_GAME_H


#include <fstream>
#include "Group.h"
#include "Arena.h"

class Game {
public:
    Game();
    void start();
    bool config(char *fileName);
    bool init(char *fileName);

private:
    Group players;
    Arena arena;
    int numOfIterations;
    bool goodFileState(const std::ifstream &file);
};


#endif //EVYATAR_CPP_3_GAME_H