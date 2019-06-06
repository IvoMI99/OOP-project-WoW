#include "giant.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Giant::Giant(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=exp*level;
}

double Giant::atack(){
    isDef=false;
    if(hp<0.20*maxHp)
        return strength*1.2;
    return strength;
}

void Giant::defend(){
    isDef=true;
}

void Giant::printArt() const {
    gotoxy(90,8);
    cout<<"     .      .";
    gotoxy(90,9);
    cout<<"     |\\____/|";
    gotoxy(90,10);
    cout<<"    (\\|----|/)";
    gotoxy(90,11);
    cout<<"     \\ 0  0 /";
    gotoxy(90,12);
    cout<<"      |    |";
    gotoxy(90,13);
    cout<<"   ___/\\../\\____";
    gotoxy(90,14);
    cout<<"  /     --       \\";
    gotoxy(90,15);
    cout<<" /  \\         /   \\";
    gotoxy(90,16);
    cout<<"|    \\___/___/(   |";
    gotoxy(90,17);
    cout<<"\\   /|  }{   | \\  )";
    gotoxy(90,18);
    cout<<" \\  ||__}{__|  |  |";
    gotoxy(90,19);
    cout<<"  \\  |;;;;;;;\\  \\ / \\_______";
    gotoxy(90,20);
    cout<<"   \\ /;;;;;;;;| [,,[|======'";
    gotoxy(90,21);
    cout<<"     |;;;;;;/ |     /";
    gotoxy(90,22);
    cout<<"     ||;;|\\   |";
    gotoxy(90,23);
    cout<<"     ||;;/|   /";
    gotoxy(90,24);
    cout<<"     \\_|:||__|";
    gotoxy(90,25);
    cout<<"      \\ ;||  /";
    gotoxy(90,26);
    cout<<"      |= || =|";
    gotoxy(90,27);
    cout<<"      |= /\\ =|";
    gotoxy(90,28);
    cout<<"      /_/  \\_\\";


}

void Giant::info ()const{
    system("cls");
    cout<<"Giant minotaur protecting the cave"<<endl;
}
