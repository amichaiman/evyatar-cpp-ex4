
#ifndef EVYATAR_CPP_3_GROUP_H
#define EVYATAR_CPP_3_GROUP_H


#include "Player.h"
#include "Point.h"
#include "Tree.h"
#include <fstream>
using namespace std;

class Group {
public:
    Group();
    const Point &getObjective() const;
    void setObjective(const Point &objective);
    int getNumOfPlayers() const;
    Group& operator=(const Group& a);
    Group(const Group &a);
    bool init(char *fileName);
    virtual ~Group();
    void printInfo();

    Player *getPlayers() const;

    void update();
private:
    Tree<Player> players;
    Player **players;
    Player *globalBest;
    Point objective;
    int numOfPlayers;

    bool goodFileState(const std::ifstream &file);
    void updateGlobalBest();
};


#endif //EVYATAR_CPP_3_GROUP_H