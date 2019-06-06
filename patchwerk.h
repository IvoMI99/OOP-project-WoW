#ifndef PATCHWERK_H_INCLUDED
#define PATCHWERK_H_INCLUDED
#include "monster.h"

class Patchwerk: public Monster{
private:
    int counter;
public:
    Patchwerk(Hero* , const char* = "Patchwerk" , int =10, int=10, double = 175 );

    double atack();
    void defend();
    void printArt()const;
    void info() const;
};


#endif // PATCHWERK_H_INCLUDED
