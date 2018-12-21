

#include <iostream>
#include "Point.h"
#include "SpeedVector.h"
#include <cmath>
#include <iomanip>
/*This class represents a Point */

//constructors
Point::Point(double x, double y) : x(x), y(y) {}

Point::Point()
        :x(UNINITIALIZED), y(UNINITIALIZED) {}

//destructor
Point::~Point() {

}


void Point::printInfo() {
    std::cout << std::fixed << std::setprecision(getPrecision(x)) << x << " " << std::setprecision(getPrecision(x)) << y << std::endl;
}


int Point::getPrecision(double n) {
    if (floor(n) == n) {
        return 0;
    }
    if (floor(n * 10) == n * 10) {
        return 1;
    }
    return 2;
}
/*returns the distance from one point to another */
double Point::getDistanceFrom(Point point) const{
    return sqrt(pow(x-point.x,2)+pow(y-point.y,2));
}

/*subtructs between two points */
Point Point::operator-(const Point &rhs) const {
    Point newPoint;
    newPoint.x = x-rhs.x;
    newPoint.y = y-rhs.y;
    return newPoint;
}

/*multiply point with number*/
Point Point::operator*(const double n) const {
    Point newPoint;
    newPoint.x = x*n;
    newPoint.y = y*n;
    return newPoint;
}
/*adds between point to SpeedVector*/
Point Point::operator+(const SpeedVector &rhs) const {
    Point newPoint;
    newPoint.x = x+rhs.speedX;
    newPoint.y = y+rhs.speedY;
    return newPoint;
}
