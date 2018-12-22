//
// Created by amichai on 21/12/18.
//

#include "Goalie.h"

double Goalie::getAlpha() {
    return 0.01;
}

double Goalie::getBeta() {
    return -0.1;
}

double Goalie::getGama() {
    return -0.25;
}

Goalie::Goalie(int id): Player(id) { }

char Goalie::getLetter() {
    return 'G';
}
