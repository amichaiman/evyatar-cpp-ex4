

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
    players = new Player*[numOfPlayers];
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
        switch (playerType) {
            case ('G'):
                players[i] = new Goalie(); break;
            case('D'):
                players[i] = new Defencemen(); break;
            case('F'):
                players[i] = new Forwards(); break;
            default:
                return false;
        }
        players[i]->setCurrentLocation(p, objective);
        players[i]->setSpeedVector(v);
        players[i]->setId(i);
    }
    return file.eof();
}
/*checks the file */
bool Group::goodFileState(const std::ifstream &file) {
    return !file.fail() && !file.bad();
}
/**/
Group::~Group() {
    delete[] players;
}

void Group::printInfo() {
    for (int i=0; i<numOfPlayers; i++){
        cout << players[i]->getCurrentLocation().x << " " << players[i]->getCurrentLocation().y;
        if (i != numOfPlayers-1){
            cout << endl;
        }
    }
}

void Group::update() {
    updateGlobalBest();
    for (int i=0; i<numOfPlayers; i++){
        players[i]->update(objective, *globalBest);
    }
}

void Group::updateGlobalBest() {
    double currentDistance;
    double shortestDistance = INT32_MAX;
    for (int i=0; i<numOfPlayers; i++){
        currentDistance = players[i]->getCurrentLocation().getDistanceFrom(objective);
        if (currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            globalBest = players[i];
        }
    }
}

Player *Group::getPlayers() const {
    return *players;
}