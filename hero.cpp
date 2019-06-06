#include "utility.h"
#include "hero.h"
#include "map.h"
#include "log.h"
#define cout std::cout
#define endl std::endl
#define setw std::setw

Hero::Hero(const char* _name, int str, int inte): strength(str),intellect(inte){
    name = new char[strlen(_name)+1];
    strcpy(name,_name);
    hp=100,maxHp=100;
    level=0;
    exp=0;
    nextLevel= 100;
    isDef=false;
}

Hero::Hero(std::ifstream& fin){
    isDef=false;
    char _name[32];
    fin.get();
    fin.getline(_name,32);
    fin>>strength>>intellect>>level>>maxHp>>hp>>exp>>nextLevel;
    name = new char[strlen(_name)+1];
    strcpy(name,_name);
}

Hero::Hero(const Hero& other):strength(other.strength),intellect(other.intellect){
    name = new char[strlen(other.name)+1];
    strcpy(name,other.name);
    hp=other.hp,maxHp=other.maxHp;
    level=other.level;
    exp=other.hp;
    nextLevel= other.nextLevel;
    isDef=false;
}

Hero::~Hero(){
    delete[] name;
}

Hero& Hero::operator=(const Hero& other){
    if(this!=&other){
        strength=other.strength;
        hp=other.hp,maxHp=other.maxHp;
        intellect=other.intellect;
        delete[] name;
        name = new char[strlen(other.name)+1];
        strcpy(name,other.name);
        exp=other.exp;
        nextLevel=other.nextLevel;
    }
    return *this;
}

bool Hero::isDead()const{
    if(hp==0)
        return true;
    return false;

}

bool Hero::isDefending()const{
    return isDef;
}

void Hero::resetDef(){
    isDef=false;
}

void Hero::takeDamage(double n){
    hp=hp-n;
    if(hp<0)
        hp=0;
    updateStats();

}

bool Hero::levelUp(){
    if(exp>=nextLevel){
        exp-=nextLevel;
        level++;
        nextLevel=ceil(nextLevel*1.5);
        maxHp=ceil(maxHp*0.33)+maxHp;
        hp=maxHp;
        strength = ceil(strength*0.33)+strength;
        intellect = ceil(intellect*0.33)+intellect;
        levelUp();
        return true;
    }
    return false;
}
void Hero::gainExp(double n){
    exp=exp+n;
    updateStats();
    if(levelUp()){
        updateBattleLog("You reached new level");
    }
}

void Hero::print() const{
    cout<<name<<endl;
    cout<<"Level: "<<level<<endl<<"Hp:"<<hp<<"/"<<maxHp<<endl;
    cout<<"Strength: "<<strength<<endl;
    cout<<"Intellect: "<<intellect<<endl;
    cout<<"Exp: "<<exp<<endl;
    cout<<"Exp for next level: "<<nextLevel<<endl<<endl;
}

int Hero::getLevel() const {
    return level;
}

char* Hero::getName() const {
    return name;
}

void Hero::heal(){
    hp=maxHp;
}

void Hero::printStats()const{
    gotoxy(2,1);
    cout<<(char)201;
    for(int i=0;i<15;i++)
    cout<<(char)205;
    cout<<(char)187;

    gotoxy(2,2);
    cout<<(char)186;
    for(int i=0;i<15;i++)
         cout<<' ';
    cout<<(char)186;

    gotoxy(2,3);
    cout<<(char)186;
    for(int j=0;j<15;j++)
        cout<<' ';
    cout<<(char)186;

    gotoxy(2,4);
    cout<<(char)186;
    for(int j=0;j<15;j++)
        cout<<' ';
    cout<<(char)186;

    gotoxy(2,5);
    cout<<(char)186;
    for(int j=0;j<15;j++)
        cout<<' ';
    cout<<(char)186;

    gotoxy(2,6);
    cout<<(char)200;
    for(int i=0;i<15;i++)
        cout<<(char)205;
    cout<<(char)188;

    gotoxy(3,2);
    cout<<name;

    gotoxy(3,3);
    cout<<"Level:"<<level;
    gotoxy(3,4);
    cout<<"HP:"<<hp<<"/"<<maxHp;
}

void Hero::updateStats()const{
    gotoxy(3,4);
    for(int j=0;j<15;j++)
        cout<<' ';
    gotoxy(3,4);
    cout<<"HP:"<<hp<<"/"<<maxHp;
}
