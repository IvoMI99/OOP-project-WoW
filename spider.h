#ifndef SPIDER_H_INCLUDED
#define SPIDER_H_INCLUDED
#include "monster.h"

class Spider:public Monster{
public:
    Spider(Hero* , const char* = "Spider" , int =8, int=1, double = 60 );

    double atack();
    void defend();
    void printArt()const;
    void info()const;

};


#endif // SPIDER_H_INCLUDED
