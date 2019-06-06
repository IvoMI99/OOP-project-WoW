#include "utility.h"
#include "hero.h"
#include "monster.h"
#include "map.h"


#define cout std::cout
#define endl std::endl
#define setw std::setw


Monster::Monster(Hero* player, const char* _name, int str, int inte, double _hp){

    level = rand() %5 + player->getLevel() -2;
    if(level<=0)
        level=1;
    exp=50;
    maxHp = ceil((rand() % (level*5)+10)*level) + _hp;
    hp=maxHp;
    strength= str;
    intellect= str;
    for(int i=0;i<level;i++){
        strength= strength + ceil(str*level*0.15);
        intellect= intellect + ceil(inte*level*0.15);
    }
    isDef=false;
    name = new char[strlen(_name)+1];
    strcpy(name,_name);
}

Monster::~Monster(){
    delete[] name;
}

double Monster::giveExp()const{
    return exp;
}

void Monster::takeDamage(int n){
    if(isDef){
        n=0.4*n;
    }
    hp=hp-n;
    if(hp<0)
        hp=0;
    updateStats();
}

bool Monster::isDefending()const{
    return isDef;
}
double Monster::getHp()const{
    return hp;
}

double Monster::getMaxHp()const{
    return maxHp;
}

bool Monster::isDead()const{
    if(hp==0)
        return true;
    return false;

}

void Monster::printStats()const{
    gotoxy(100,1);
    cout<<(char)201;
    for(int i=0;i<16;i++)
    cout<<(char)205;
    cout<<(char)187;

    gotoxy(100,2);
    cout<<(char)186;
    for(int i=0;i<16;i++)
         cout<<' ';
    cout<<(char)186;

    gotoxy(100,3);
    cout<<(char)186;
    for(int j=0;j<16;j++)
        cout<<' ';
    cout<<(char)186;

    gotoxy(100,4);
    cout<<(char)186;
    for(int j=0;j<16;j++)
        cout<<' ';
    cout<<(char)186;

    gotoxy(100,5);
    cout<<(char)186;
    for(int j=0;j<16;j++)
        cout<<' ';
    cout<<(char)186;

    gotoxy(100,6);
    cout<<(char)200;
    for(int i=0;i<16;i++)
        cout<<(char)205;
    cout<<(char)188;

    gotoxy(101,2);
    cout<<name;
    gotoxy(101,3);
    cout<<"Level:"<<level;
    gotoxy(101,4);
    cout<<"HP:"<<hp<<"/"<<maxHp;
}

void Monster::updateStats()const{
    gotoxy(101,4);
    for(int j=0;j<16;j++)
        cout<<' ';
    cout<<(char)186;
    gotoxy(101,4);
    cout<<"HP:"<<hp<<"/"<<maxHp;
}

