#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "hero.h"

class Monster{
protected:
    bool isDef;
    char* name;
    int strength;
    int intellect;
    int level;
    double exp;
    double maxHp;
    double hp;

public:
    Monster(Hero* , const char* = "", int =0, int=0, double = 0);
    ~Monster();

    double getHp()const;
    bool isDefending()const;
    double getMaxHp()const;
    void printStats()const;
    void takeDamage(int);
    bool isDead()const;
    double giveExp()const;
    virtual double atack() = 0;
    virtual void defend() = 0;
    virtual void printArt()const = 0;
    virtual void updateStats()const;
    virtual void info()const = 0;
};


#endif // __MONSTER_H__
