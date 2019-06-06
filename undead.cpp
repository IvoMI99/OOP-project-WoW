#include "undead.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Undead::Undead(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=ceil(exp*level*1.5);
}

double Undead::atack(){
    isDef=false;
    int buff=rand()%10;
    if(hp<0.20*maxHp)
        return strength*1.2+buff;
    return strength+buff;
}

void Undead::defend(){
    isDef=true;
}

void Undead::printArt()const{
   gotoxy(80,8);
   cout<<"                          .....";
   gotoxy(80,9);
   cout<<"                         C C  /";
   gotoxy(80,10);
   cout<<"                        /<   /";
   gotoxy(80,11);
   cout<<"         ___ __________/_#__=o";
   gotoxy(80,12);
   cout<<"        /(- /(\\_\\________   \\";
   gotoxy(80,13);
   cout<<"        \\ ) \\ )_      \\o     \\";
   gotoxy(80,14);
   cout<<"        /|\\ /|\\       |'     |";
   gotoxy(80,15);
   cout<<"                      |     _|";
   gotoxy(80,16);
   cout<<"                      /o   __\\";
   gotoxy(80,17);
   cout<<"                     / '     |";
   gotoxy(80,18);
   cout<<"                    / /      |";
   gotoxy(80,19);
   cout<<"                   /_/\______|";
   gotoxy(80,20);
   cout<<"                  (   _(    <";
   gotoxy(80,21);
   cout<<"                   \\    \\    \\";
   gotoxy(80,22);
   cout<<"                    \\    \\    | ";
   gotoxy(80,23);
   cout<<"                     \\____\\____\\";
   gotoxy(80,24);
   cout<<"                     ____\\_\\__\\_\\";
   gotoxy(80,25);
   cout<<"                   /`   /`     o\\";
   gotoxy(80,26);
   cout<<"                   |___ |_______|.. .";

}

void Undead::info ()const{
    system("cls");
    cout<<"A child of the scourge."<<endl;
    cout<<"It can do only basic attacks."<<endl;
}
