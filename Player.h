

#ifndef EVYATAR_CPP_3_PLAYER_H
#define EVYATAR_CPP_3_PLAYER_H


#include "Point.h"
#include "SpeedVector.h"

class Player {
public:
    Player();
    Player(const Player &a);
    Player& operator=(const Player& a);
    void setCurrentLocation(Point point, Point objective);
    void setSpeedVector(SpeedVector &vector);
    void setId(int i);

    void update(Point &objective, Player &globalBest);
    const Point &getCurrentLocation() const;

private:
    int id;
    Point currentLocation;
    Point personalBest;
    SpeedVector speed;

    bool isPersonalBest(Point &newPoint, Point &objective) const;
    double r();

    virtual double getAlpha()=0;
    virtual double getBeta()=0;
    virtual double getGama()=0;

    SpeedVector getNewSpeed(Player &globalBest);
};


#endif //EVYATAR_CPP_3_PLAYER_H