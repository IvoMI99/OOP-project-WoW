#ifndef __MAGE_H__
#define __MAGE_H__
#include "hero.h"

class Mage: public Hero{
private:
    int mana;

public:
    Mage(const char* = "" , int = 4, int = 11);
    Mage(const Mage&);
    Mage& operator = (const Mage& );
    Mage(std::ifstream& );

    double fireball();
    double atack () ;
    void defend () ;
    bool save();
    void printArt()const;
    void printStats()const;
    void updateStats()const;
    void info()const ;
    void battleStart() ;


};

#endif // __MAGE_H__
