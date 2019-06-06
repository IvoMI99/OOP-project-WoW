#ifndef FLAMEWALKER_H_INCLUDED
#define FLAMEWALKER_H_INCLUDED
#include "monster.h"

class Flamewalker:public Monster{
public:
    Flamewalker(Hero* , const char* = "Flamewalker" , int =11, int=7, double = 70 );

    double atack();
    void defend();
    void printArt()const;
    void info ()const;


};





#endif // FLAMEWALKER_H_INCLUDED
