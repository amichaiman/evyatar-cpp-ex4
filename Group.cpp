

#include <fstream>
#include <iostream>
#include <stdint.h>
#include "Group.h"
#include "Limits.h"
#include "Goalie.h"
#include "Defencemen.h"
#include "Forwards.h"

Group::Group(){
}

/*operator =*/
Group& Group::operator=(const Group& a)
{
    if(this==&a)
        return *this;
    else
        this->players = a.players;
        this->globalBest = a.globalBest;
        this->objective = a.objective;
        this->numOfPlayers = a.numOfPlayers;

    return *this;
}

/*copy constructor */
Group::Group(const Group &a){
    this->players = a.players;
    this->globalBest = a.globalBest;
    this->objective = a.objective;
    this->numOfPlayers = a.numOfPlayers;
}


/*returns the Objective*/
const Point &Group::getObjective() const {
    return objective;
}

/*sets objective*/
void Group::setObjective(const Point &objective) {
    Group::objective = objective;
}
/*returns the number of players*/
int Group::getNumOfPlayers() const {
    return numOfPlayers;
}

bool Group::init(char *fileName) {
    std::ifstream file;
    file.open(fileName, std::ios::in);

    if (!file.is_open()){
        return false;
    }
    int numOfPlayers;
    file >> numOfPlayers;

    if (!goodFileState(file)) {
        return false;
    }

    if (numOfPlayers < Limits::MIN_PLAYERS || numOfPlayers > Limits::MAX_PLAYERS) {
        return false;
    }

    Group::numOfPlayers = numOfPlayers;
    char playerType;
    Point p;
    SpeedVector v;
    for (int i=0; i<numOfPlayers; i++){
        file >> playerType >> p.x >> p.y >> v.speedX >> v.speedY;
        if (!goodFileState(file)) {
            return false;
        }
        if (!Limits::inArena(p)){
            return false;
        }
        Player *currentPlayer;
        switch (playerType) {
            case ('G'):
                currentPlayer = new Goalie(i); break;
            case('D'):
                currentPlayer = new Defencemen(i); break;
            case('F'):
                currentPlayer = new Forwards(i); break;
            default:
                return false;
        }
        currentPlayer->setCurrentLocation(p, objective);
        currentPlayer->setSpeedVector(v);
        players.insert(currentPlayer);
    }
    return true;
}
/*checks the file */
bool Group::goodFileState(const std::ifstream &file) {
    return !file.fail() && !file.bad();
}
/**/
Group::~Group() { }

void Group::printInfo() {
    Player *curPlayer;
    for (int i=0; i<numOfPlayers; i++){
        curPlayer = players.getPlayerById(i);
        cout << curPlayer->getLetter() << " " << curPlayer->getCurrentLocation().x << " " << curPlayer->getCurrentLocation().y;
        if (i != numOfPlayers-1){
            cout << endl;
        }
    }
}

void Group::update() {
    updateGlobalBest();
    for (int i=0; i<numOfPlayers; i++){
        players.getPlayerById(i)->update(objective, *globalBest);
    }
}

void Group::updateGlobalBest() {
    double currentDistance;
    double shortestDistance = INT32_MAX;
    for (int i=0; i<numOfPlayers; i++){
        currentDistance = players.getPlayerById(i)->getCurrentLocation().getDistanceFrom(objective);
        if (currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            globalBest = players.getPlayerById(i);
        }
    }
}

PlayerTree<Player*>* Group::getPlayers() {
    return &players;
}