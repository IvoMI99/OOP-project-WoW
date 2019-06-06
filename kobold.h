#ifndef KOBOLD_H_INCLUDED
#define KOBOLD_H_INCLUDED

#include "monster.h"

class Kobold:public Monster{
public:
    Kobold(Hero* , const char* = "Kobold" , int =8, int=1, double = 30 );

    double atack();
    void defend();
    void printArt()const;
    void info ()const;


};



#endif // KOBOLD_H_INCLUDED
