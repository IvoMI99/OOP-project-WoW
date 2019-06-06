#ifndef GOBLIN_H_INCLUDED
#define GOBLIN_H_INCLUDED
#include "monster.h"

class Goblin:public Monster{
public:
    Goblin(Hero* , const char* = "Goblin" , int =5, int=2, double = 30 );

    double atack();
    void defend();
    void printArt()const;
    void info ()const;


};



#endif // GOBLIN_H_INCLUDED
