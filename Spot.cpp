

#include "Spot.h"

Spot::Spot(){
}

/*operator =*/
Spot& Spot::operator=(const Spot& a) {
    if(this==&a)
        return *this;
    else
        this->numOfPlayers = a.numOfPlayers;

    return *this;
}

/*copy constructor */
Spot::Spot(const Spot &a){
    this->numOfPlayers = a.numOfPlayers;
}



/*decrement operation for player - */
Spot &Spot::operator--() {
    numOfPlayers--;
    return *this;
}

/*increment operation for player -*/
Spot &Spot::operator++(int) {
    numOfPlayers++;
    return *this;
}
/*set number of players*/
void Spot::setNumberOfPlayers(int n) {
    numOfPlayers = 0;
}
/*returns the number of players*/
int Spot::getNumberOfPlayers() {
    return numOfPlayers;
}