//
// Created by amichai on 21/12/18.
//

#ifndef EVYATAR_GENERIC_TREE_FORWARDS_H
#define EVYATAR_GENERIC_TREE_FORWARDS_H


#include "Player.h"

class Forwards : public Player{
public:
    Forwards(int id);
    char getLetter();
private:
    virtual double getAlpha();
    virtual double getBeta();
    virtual double getGama();
};


#endif //EVYATAR_GENERIC_TREE_FORWARDS_H
