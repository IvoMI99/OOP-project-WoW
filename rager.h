#ifndef RAGER_H_INCLUDED
#define RAGER_H_INCLUDED
#include "monster.h"

class Rager:public Monster{
public:
    Rager(Hero* , const char* = "Magma Rager" , int =30, int=1, double = 15 );

    double atack();
    void defend();
    void printArt()const;
    void info ()const;


};



#endif // RAGER_H_INCLUDED
