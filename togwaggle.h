#ifndef TOGWAGGLE_H_INCLUDED
#define TOGWAGGLE_H_INCLUDED
#include "monster.h"

class Togwaggle: public Monster{
private:
    int buff;
public:
    Togwaggle(Hero* , const char* = "Togwaggle" , int =17, int=10, double = 225 );

    double atack();
    void defend();
    void printArt()const;
    void info() const;
};


#endif // TOGWAGGLE_H_INCLUDED

