

#ifndef EVYATAR_CPP_3_PLAYER_H
#define EVYATAR_CPP_3_PLAYER_H


#include "Point.h"
#include "SpeedVector.h"

class Player {
public:
    Player(int id);
    Player();
    Player(const Player &a);
    virtual ~Player();
    Player& operator=(const Player& a);
    bool operator==(const Player &rhs);
    bool operator==(int id);
    bool operator>(const Player &rhs);
    bool operator<(const Player &rhs);
    void setCurrentLocation(Point point, Point objective);
    void setSpeedVector(SpeedVector &vector);
    void update(Point &objective, Player &globalBest);
    const Point &getCurrentLocation() const;
    int getId() const;
    virtual char getLetter()=0;

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