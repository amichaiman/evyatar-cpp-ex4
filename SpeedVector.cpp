

#include <iostream>
#include "SpeedVector.h"
#include "Point.h"

//constructors
SpeedVector::SpeedVector(double speedX, double speedY) : speedX(speedX), speedY(speedY) {}

SpeedVector::SpeedVector() {
}

SpeedVector::~SpeedVector() {

}

/*operator =*/
SpeedVector& SpeedVector::operator=(const SpeedVector& a)
{
    if(this==&a)
        return *this;
    else
        this->speedX = a.speedX;
    this->speedY = a.speedY;


    return *this;
}


/*copy constructor */
SpeedVector::SpeedVector(const SpeedVector &a){
    this->speedX = a.speedX;
    this->speedY = a.speedY;
}
/*prints SpeedVector*/
void SpeedVector::printInfo() {
    std::cout << "x: " << speedX << " y: " << speedY << std::endl;
}
/*multiplication between SpeedVector to a number*/
SpeedVector SpeedVector::operator*(const double n) const {
    SpeedVector newSpeedVector;
    newSpeedVector.speedX = speedX*n;
    newSpeedVector.speedY = speedY*n;
    return newSpeedVector;
}

/*addition between SpeedVector to a number*/
SpeedVector SpeedVector::operator+(const double n) const {
    SpeedVector newSpeedVector;
    newSpeedVector.speedX = speedX+n;
    newSpeedVector.speedY = speedY+n;
    return newSpeedVector;
}
/*addition between SpeedVector to a point*/
SpeedVector SpeedVector::operator+(const Point &rhs) const {
    SpeedVector newSpeedVector;
    newSpeedVector.speedX = speedX+rhs.x;
    newSpeedVector.speedY = speedY+rhs.y;
    return newSpeedVector;
}