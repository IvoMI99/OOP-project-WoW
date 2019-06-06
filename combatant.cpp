#include "combatant.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Combatant::Combatant(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=exp*level;
}

double Combatant::atack(){
    isDef=false;
    if(hp<0.20*maxHp)
        return strength*1.2;
    return strength;
}

void Combatant::defend(){
    isDef=true;
}

void Combatant::printArt() const {
    gotoxy(90,15);
cout<<"  <=======]}======";
    gotoxy(90,16);
cout<<"    ---.   /|";
    gotoxy(90,17);
cout<<"   _\\''/_.'/";
    gotoxy(90,18);
cout<<" .'._._,.'";
    gotoxy(90,19);
cout<<" :/ \\{}/";
    gotoxy(90,20);
cout<<"(L  /--',----._";
    gotoxy(90,21);
cout<<"    |          \\\\";
    gotoxy(90,22);
cout<<"   : /-\\ .'-'\\ / |";
    gotoxy(90,23);
cout<<"    \\\\, ||    \\|";
    gotoxy(90,24);
cout<<"     \\/ ||    ||";


}

void Combatant::info ()const{
    system("cls");
    cout<<"A fallen warrior who was once a hero."<<endl;
}
