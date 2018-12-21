

#ifndef EVYATAR_CPP_3_SPEEDVECTOR_H
#define EVYATAR_CPP_3_SPEEDVECTOR_H


class Point;
class SpeedVector {
public:
    SpeedVector(double speedX, double speedY);
    SpeedVector();
    SpeedVector(const SpeedVector &a);
    SpeedVector& operator=(const SpeedVector& a);
    virtual ~SpeedVector();
    double speedX, speedY;
    void printInfo();
    SpeedVector operator*(const double n) const;
    SpeedVector operator+(const double n) const;
    SpeedVector operator+(const Point &rhs) const;
};


#endif //EVYATAR_CPP_3_SPEEDVECTOR_H