
#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Limits.h"

/*operator =*/
Player& Player::operator=(const Player& a)
{
    if(this==&a)
        return *this;
    else
        this->id = a.id;
    this->currentLocation = a.currentLocation;
    this->personalBest = a.personalBest;
    this->speed = a.speed;

    return *this;
}


/*copy constructor */
Player::Player(const Player &a){
    this->id = a.id;
    this->currentLocation = a.currentLocation;
    this->personalBest = a.personalBest;
    this->speed = a.speed;
}


/*sets current location*/
void Player::setCurrentLocation(Point point, Point objective) {
    if (point.x < Limits::X_MIN) {
        point.x = Limits::X_MIN;
    } else if (point.x > Limits::X_MAX) {
        point.x = Limits::X_MAX;
    }
    if (point.y < Limits::Y_MIN) {
        point.y = Limits::Y_MIN;
    } else if (point.y > Limits::Y_MAX) {
        point.y = Limits::Y_MAX;
    }
    if (isPersonalBest(point, objective)){
        personalBest = point;
    }
    currentLocation = point;
}
/*sets the speed vector*/
void Player::setSpeedVector(SpeedVector &vector) {
    speed = vector;
}

/*updates the current location of a player according to the speed*/
void Player::update(Point &objective, Player &globalBest) {
    SpeedVector newSpeed = getNewSpeed(globalBest);
    setCurrentLocation(currentLocation+speed, objective);
    speed = newSpeed;
}
/*returns the current location*/
const Point &Player::getCurrentLocation() const {
    return currentLocation;
}

Player::Player(){ }
/*checks if is personalBest*/
bool Player::isPersonalBest(Point &newPoint, Point &objective) const{
    return (personalBest.x == Point::UNINITIALIZED && personalBest.y == Point::UNINITIALIZED) ||
           newPoint.getDistanceFrom(objective) < currentLocation.getDistanceFrom(objective);
}

/*returns the new speed of a player*/
SpeedVector Player::getNewSpeed(Player &globalBest) {
    return (speed*0.25)*getAlpha() + (personalBest-currentLocation)*r()*getBeta() + (globalBest.getCurrentLocation()-currentLocation)*r()*getGama();
}
/*random variables between 0 to 1*/
double Player::r() {
    return rand()/static_cast<double>(RAND_MAX);
}

Player::Player(int id) : id(id) {}

bool Player::operator==(const Player &rhs) {
    return id == rhs.getId();
}

int Player::getId() const {
    return id;
}

bool Player::operator==(int id) {
    return getId() == id;
}

bool Player::operator>(const Player &rhs) {
    return getId() > rhs.getId();
}

bool Player::operator<(const Player &rhs) {
    return getId() < rhs.getId();
}

Player::~Player() {
}
