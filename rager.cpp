#include "rager.h"
#include "utility.h"
#include "map.h"

#define cout std::cout
#define endl std::endl

Rager::Rager(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=exp*level;
}

double Rager::atack(){
    isDef=false;
    if(hp<0.20*maxHp)
        return strength*1.2;
    return strength;
}

void Rager::defend(){
    isDef=true;
}

void Rager::printArt() const {
    gotoxy(90,12);
    cout<<"  ,/         \\.";
    gotoxy(90,13);
    cout<<" ((          ))";
    gotoxy(90,14);
    cout<<" \\`.       ,'/";
    gotoxy(90,15);
    cout<<"  )')     (`(";
    gotoxy(90,16);
    cout<<",'`/       \\,`.";
    gotoxy(90,17);
    cout<<"(`-(        )-')";
    gotoxy(90,18);
    cout<<" \\-'\\,-''`-./`-/";
    gotoxy(90,19);
    cout<<"  \\-')     (`-/";
    gotoxy(90,20);
    cout<<"  /`'       `'\\";
    gotoxy(90,21);
    cout<<" (  _       _  )";
    gotoxy(90,22);
    cout<<" | ( \\     / ) |";
    gotoxy(90,23);
    cout<<" |  `.\\   /,'  |";
    gotoxy(90,24);
    cout<<" |    `\\ /'    |";
    gotoxy(90,25);
    cout<<" (             )";
    gotoxy(90,26);
    cout<<"  \\           /";
    gotoxy(90,27);
    cout<<"   \\         /";
    gotoxy(90,28);
    cout<< "    `.     ,'";
    gotoxy(90,29);
    cout<<"      `-.-'";

}

void Rager::info ()const{
    system("cls");
    cout<<"Magma rages are specialised in offense. They hit hard but don't have much hp."<<endl;
}
