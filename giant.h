#ifndef GIANT_H_INCLUDED
#define GIANT_H_INCLUDED
#include "monster.h"

class Giant:public Monster{
public:
    Giant(Hero* , const char* = "Giant" , int =14, int=5, double = 90 );

    double atack();
    void defend();
    void printArt()const;
    void info ()const;


};





#endif // GIANT_H_INCLUDED
