#include "goblin.h"
#include "utility.h"
#include "map.h"

#define cout std::cout
#define endl std::endl

Goblin::Goblin(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=exp*level;
}

double Goblin::atack(){
    isDef=false;
    int buff=rand()%10;
    if(hp<0.20*maxHp)
        return strength*1.2+buff;;
    return strength+buff;;
}

void Goblin::defend(){
    isDef=true;
}

void Goblin::printArt() const {
    gotoxy(90,10);
    cout<<"         ,      ,";
    gotoxy(90,11);
    cout<<"        /(.-''-.)\\";
    gotoxy(90,12);
    cout<<"    |\\  \\/      \\/  /|";
    gotoxy(90,13);
    cout<<"    | \\ / =.  .= \\ / |";
    gotoxy(90,14);
    cout<<"    \\( \\   o\\/o   / )/";
    gotoxy(90,15);
    cout<<"     \\_, '-/  \\-' ,_/";
    gotoxy(90,16);
    cout<<"       /   \\__/   \\";
    gotoxy(90,17);
    cout<<"       \\ \\__/\\__/ /";
    gotoxy(90,18);
    cout<<"     ___\\ \\|--|/ /___";
    gotoxy(90,19);
    cout<<"   /`    \\      /    `\\";
    gotoxy(90,20);
    cout<<"  /       '----'       \\";

}

void Goblin::info ()const{
    system("cls");
    cout<<"Weakest of all creatures"<<endl;
    cout<<"It can do only basic attacks"<<endl;
}
