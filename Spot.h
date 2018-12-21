
#ifndef EVYATAR_CPP_3_SPOT_H
#define EVYATAR_CPP_3_SPOT_H

class Spot {
public:
    Spot();
    Spot(const Spot &a);
    Spot& operator=(const Spot& a);
    Spot& operator++(int);
    Spot& operator--();
    void setNumberOfPlayers(int n);
    int getNumberOfPlayers();

private:
    int numOfPlayers;
};


#endif //EVYATAR_CPP_3_SPOT_H