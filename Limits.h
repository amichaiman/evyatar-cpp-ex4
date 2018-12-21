

#ifndef EVYATAR_CPP_3_LIMITS_H
#define EVYATAR_CPP_3_LIMITS_H


#include "Point.h"

class Limits {
public:
    static const int X_MAX = 61;
    static const int Y_MAX = 30;
    static const int X_MIN = 0;
    static const int Y_MIN = 0;
    static const int MAX_ITERATIONS = 1000000;
    static const int MIN_ITERATIONS = 0;
    static const int MAX_PLAYERS = 100;
    static const int MIN_PLAYERS = 3;

    static bool inArena(Point p);
};


#endif //EVYATAR_CPP_3_LIMITS_H