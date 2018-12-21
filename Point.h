

#ifndef EVYATAR_CPP_3_POINT_H
#define EVYATAR_CPP_3_POINT_H


class SpeedVector;

class Point {
public:
    Point(double x, double y);
    Point();
    virtual ~Point();
    static const int UNINITIALIZED = -1;

    double x,y;
    void printInfo();
    double getDistanceFrom(Point point) const;
    Point operator-(const Point &rhs) const;
    Point operator+(const SpeedVector &rhs) const;
    Point operator*(const double n) const;

    int getPrecision(double x);
};


#endif //EVYATAR_CPP_3_POINT_H