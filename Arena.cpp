
#include <iostream>
#include "Arena.h"
#include "Limits.h"
/*the big three are not necessary here*/

void Arena::update(Group &group) {
    for (int i=Limits::X_MIN; i < Limits::X_MAX; i++){
        for (int j=Limits::Y_MIN; j<Limits::Y_MAX; j++){
            arena[i][j].setNumberOfPlayers(0);
            for (int k=0; k<group.getNumOfPlayers(); k++){
                if (isPointInSpot(i,j, group.getPlayers()[k].getCurrentLocation())){
                    arena[i][j]++;
                    if (isPointInSpot(i,j,group.getObjective())){
                        objectiveReached = true;
                    }
                }
            }
        }
    }
}

Arena::Arena() : objectiveReached(false) {}

bool Arena::isObjectiveReached(){
    return objectiveReached;
}
void Arena::setPlayers(Group *players) {
    Arena::players = players;
}

bool Arena::isPointInSpot(int i, int j, Point p) const {
    return p.x >= j && p.x < j+1 &&
           p.y >= i && p.y < i+1;
}

int Arena::operator()(int i, int j) {
    return arena[i][j].getNumberOfPlayers();
}