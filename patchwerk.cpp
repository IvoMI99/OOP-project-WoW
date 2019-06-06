#include "patchwerk.h"
#include "map.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Patchwerk::Patchwerk(Hero* player, const char* name, int str, int inte, double _hp):Monster(player,name,str,inte,_hp){
    level=level+2;
    exp=exp*level*10;
    counter=0;
    maxHp=maxHp + level*_hp;
    hp=maxHp;
}

double Patchwerk::atack(){
    isDef=false;
    if(counter==2){
        counter=0;
        return strength+intellect;

    }
    counter++;
    return strength;
}

void Patchwerk::defend(){
    isDef=true;
}

void Patchwerk::printArt() const{
    gotoxy(80,12);
    cout<<"                        ______";
    gotoxy(80,13);
    cout<<"             ______,---'__,---'";
    gotoxy(80,14);
    cout<<"         _,-'---_---__,---'";
    gotoxy(80,15);
    cout<<"  /_    (,  ---____',";
    gotoxy(80,16);
    cout<<" /  ',,   `, ,-'";
    gotoxy(80,17);
    cout<<";/)   ,',,_/,'";
    gotoxy(80,18);
    cout<<"| /\\   ,.'//\\";
    gotoxy(80,19);
    cout<<"`-` \\ ,,'    `.";
    gotoxy(80,20);
    cout<<"     `',   ,-- `. ";
    gotoxy(80,21);
    cout<<"     '/ / |      `,  ";
    gotoxy(80,22);
    cout<<"     //'',.\\_    .\\\\      ,{==>-";
    gotoxy(80,23);
    cout<<"  __//   __;_`-  \\ `;.__,;'";
    gotoxy(80,24);
    cout<<"((,--,) (((,------;  `--' ";

}

void Patchwerk::info()const{
    system("cls");
    cout<<"The most fearsome griffon in the woods"<<endl;
    cout<<"Every third attack deals extra damage"<<endl;
}
