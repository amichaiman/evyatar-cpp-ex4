

#ifndef EVYATAR_CPP_3_ARENA_H
#define EVYATAR_CPP_3_ARENA_H


#include "Point.h"
#include "Limits.h"
#include "Spot.h"
#include "Group.h"

class Arena {
public:
    Arena();

    void update(Group &group);
    void setPlayers(Group *players);
    bool isObjectiveReached();
    int operator()(int i, int j);
private:
    Spot arena[Limits::X_MAX][Limits::Y_MAX];
    Group *players;
    bool objectiveReached;
    bool isPointInSpot(int i, int j, Point p) const;
};


#endif //EVYATAR_CPP_3_ARENA_H