//
// Created by amichai on 21/12/18.
//

#ifndef EVYATAR_GENERIC_TREE_DEFENCEMEN_H
#define EVYATAR_GENERIC_TREE_DEFENCEMEN_H


#include "Player.h"

class Defencemen : public Player{
public:
    Defencemen(int id);
    virtual char getLetter();
private:
    virtual double getAlpha();
    virtual double getBeta();
    virtual double getGama();
};


#endif //EVYATAR_GENERIC_TREE_DEFENCEMEN_H
