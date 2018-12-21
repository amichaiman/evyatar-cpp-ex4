
#include "Limits.h"
/*the big three are not necessary here*/
/*checks if the point is in the range of the Arena limits*/
bool Limits::inArena(Point p) {
    return p.x >= Limits::X_MIN && p.y >= Limits::Y_MIN && p.x <= Limits::X_MAX && p.y <= Limits::Y_MAX;
}