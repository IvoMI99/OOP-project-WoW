#ifndef FURBOLG_H_INCLUDED
#define FURBOLG_H_INCLUDED

#include "monster.h"
#include "hero.h"

class Furbolg:public Monster{
public:
    Furbolg(Hero* , const char* = "Furbolg" , int =10, int=10, double = 60 );

    double atack();
    void defend();
    void printArt()const;
    void info ()const;


};




#endif // FURBOLG_H_INCLUDED
