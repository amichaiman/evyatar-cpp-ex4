//
// Created by amichai on 21/12/18.
//

#include "Forwards.h"

double Forwards::getAlpha() {
    return 0.25;
}

double Forwards::getBeta() {
    return 1.0;
}

double Forwards::getGama() {
    return 1.0;
}

char Forwards::getLetter() {
    return 'F';
}

Forwards::Forwards(int id) : Player(id) { }
