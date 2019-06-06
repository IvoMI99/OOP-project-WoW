#ifndef RAGGNAROS_H_INCLUDED
#define RAGGNAROS_H_INCLUDED
#include "monster.h"

class Raggnaros: public Monster{
private:
    int elementalPower;
public:
    Raggnaros(Hero* , const char* = "Raggnaros" , int =14, int=21, double = 250);

    double atack();
    void defend();
    void printArt()const;
    void printStats()const;
    void updateStats()const;
    void info() const;
};


#endif // RAGGNAROS_H_INCLUDED
