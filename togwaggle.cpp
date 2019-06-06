#include "togwaggle.h"
#include "map.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Togwaggle::Togwaggle(Hero* player, const char* name, int str, int inte, double _hp):Monster(player,name,str,inte,_hp){
    level=level+2;
    exp=exp*level*10;
    buff=0;
    maxHp=maxHp + level*_hp;
    hp=maxHp;
}

double Togwaggle::atack(){
    isDef=false;
    strength=strength+buff*2;
    buff++;
    if(hp<0.20*maxHp)
        return strength*1.5;
    return strength;
}

void Togwaggle::defend(){
    isDef=true;
}

void Togwaggle::printArt() const{
    gotoxy(90,10);
    cout<<"      .-.";
    gotoxy(90,11);
    cout<<"     (o.o)";
    gotoxy(90,12);
    cout<<"      |=|";
    gotoxy(90,13);
    cout<<"     __|__";
    gotoxy(90,14);
    cout<<"   //.=|=.\\";
    gotoxy(90,15);
    cout<<"  // .=|=. \\";
    gotoxy(90,16);
    cout<<"  \\\\ .=|=. //";
    gotoxy(90,17);
    cout<<"   \\\\(_=_)//";
    gotoxy(90,18);
    cout<<"    (:| |:)";
    gotoxy(90,19);
    cout<<"     || ||";
    gotoxy(90,20);
    cout<<"     () ()";
    gotoxy(90,21);
    cout<<"     || ||";
    gotoxy(90,22);
    cout<<"     || ||";
    gotoxy(90,23);
    cout<<"    ==' '==";

}

void Togwaggle::info()const{
    system("cls");
    cout<<"He is the ruler of all kobolds and is described as the big cheese, the head skeleton, the be-candled King of the Kobolds"<<endl;
    cout<<"The longer the battle continue the stronger he becomes."<<endl;

}
