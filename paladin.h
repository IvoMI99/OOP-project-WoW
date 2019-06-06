#ifndef __PALADIN_H__
#define __PALADIN_H__
#include "hero.h"

class Paladin: public Hero{
private:
    int hitCounter;
    int holyPoints;

public:
    Paladin(const char* = "" , int = 9, int = 6);
    Paladin(const Paladin&);
    Paladin& operator = (const Paladin& );
    Paladin(std::ifstream& );

    void printArt()const;
    void heal();
    double atack () ;
    void defend () ;
    void printStats()const;
    void updateStats()const;
    void info()const ;
    bool save();
    void battleStart() ;

};

#endif // __PALADIN_H__
