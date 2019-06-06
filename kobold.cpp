#include "kobold.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Kobold::Kobold(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=exp*level;
}

double Kobold::atack(){
    isDef=false;
    int buff=rand()%10;
    if(hp<0.20*maxHp)
        return strength*1.3+buff;
    return strength+buff;
}

void Kobold::defend(){
    isDef=true;
}

void Kobold::printArt() const {
    gotoxy(90,10);
    cout<<"      __       __     _";
    gotoxy(90,11);
    cout<<"     /-.\\     /  \\   //";
    gotoxy(90,12);
    cout<<"     \\  \\|_,_/|  /  ((";
    gotoxy(90,13);
    cout<<"      `\\ `    `\\'    \\\\";
    gotoxy(90,14);
    cout<<"      /  _   _  \\     ))";
    gotoxy(90,15);
    cout<<"     |  (0\\ /0)  |   //";
    gotoxy(90,16);
    cout<<"     \\           /  //";
    gotoxy(90,17);
    cout<<"     /`.== 0 ==.`\\ ((";
    gotoxy(90,18);
    cout<<"    /   `~~W~~`   \\ \\\\";
    gotoxy(90,19);
    cout<<"   |   ,       ,   | ))";
    gotoxy(90,20);
    cout<<"   \\   \\       /   ///";
    gotoxy(90,21);
    cout<<"   /`vvvv     vvvv`\\/";
    gotoxy(90,22);
    cout<<"  |                 |";
    gotoxy(90,23);
    cout<<"  |   |         |   |";
    gotoxy(90,24);
    cout<<" /    (         )    \\";
    gotoxy(90,25);
    cout<<"(v(v(v)`=.....=`(v)v)v)";

}

void Kobold::info ()const{
    system("cls");
    cout<<"You no take candle!!!"<<endl;
}
