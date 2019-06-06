#ifndef __HERO_H__
#define __HERO_H__
#include <fstream>

class Hero{
protected:
    bool isDef;
    char* name;
    int strength;
    int intellect;
    int level;
    double maxHp;
    double hp;
    double exp;
    double nextLevel;
    bool levelUp();
public:
    Hero(const char* = "" , int = 0, int = 0);
    Hero(std::ifstream& );
    Hero(const Hero&);
    ~Hero();
    Hero& operator = (const Hero& );


    int getLevel()const;
    char* getName() const;
    bool isDefending()const;
    void resetDef();
    void takeDamage(double);
    void heal();
    void gainExp(double);
    bool isDead() const ;
    virtual double atack () = 0;
    virtual void defend () = 0;
    virtual bool save()=0;
    virtual void printArt()const=0;
    virtual void battleStart() = 0;
    virtual void printStats()const;
    virtual void info()const = 0;
    virtual void print()const;
    virtual void updateStats()const;

};

#endif // __HERO_H__
