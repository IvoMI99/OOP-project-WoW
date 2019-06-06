#ifndef __WARRIOR_H__
#define __WARRIOR_H__
#include "hero.h"
#include <fstream>

class Warrior: public Hero{
private:
    int rage;
    double rageBuff;
public:
    Warrior(const char* = "" , int = 13, int = 2);
    Warrior(const Warrior&);
    Warrior& operator = (const Warrior& );
    Warrior(std::ifstream& );

    void printArt()const;
    double atack () ;
    void defend () ;
    void printStats()const;
    void updateStats()const;
    void info()const ;
    bool save();
    void battleStart();

};

#endif // __WARRIOR_H__
