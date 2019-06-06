#ifndef COMBATANT_H_INCLUDED
#define COMBATANT_H_INCLUDED
#include "monster.h"

class Combatant:public Monster{
public:
    Combatant(Hero* , const char* = "Fallen Combatant" , int =13, int=2, double = 60 );

    double atack();
    void defend();
    void printArt()const;
    void info ()const;


};




#endif // COMBATANT_H_INCLUDED
