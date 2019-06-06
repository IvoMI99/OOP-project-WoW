#ifndef UNDEAD_H_INCLUDED
#define UNDEAD_H_INCLUDED
#include "monster.h"

class Undead:public Monster{
public:
    Undead(Hero* , const char* = "Undead" , int =6, int=3, double = 50 );

    double atack();
    void defend();
    void printArt()const;
    void info ()const;

};


#endif // UNDEAD_H_INCLUDED
