#include "spider.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Spider::Spider(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=ceil(exp*level*1.7);
}


double Spider::atack(){
    isDef=false;
    int buff=rand()%10;
    if(hp<0.20*maxHp)
        return strength*1.3+buff;
    return strength+buff;
}

void Spider::defend(){
    isDef=true;
}

void Spider::printArt()const{
    gotoxy(90,10);
    cout<<"           (";
    gotoxy(90,11);
    cout<<"           )";
    gotoxy(90,12);
    cout<<"          (";
    gotoxy(90,13);
    cout<<"    /\\  .-'''-.  /\\";
    gotoxy(90,14);
    cout<<"   //\\\\/  ,,,  \\//\\\\";
    gotoxy(90,15);
    cout<<"   |/\\| ,;;;;;, |/\\|";
    gotoxy(90,16);
    cout<<"   //\\\\\\;-'''-;///\\\\";
    gotoxy(90,17);
    cout<<"  //  \\/   .   \\/  \\\\";
    gotoxy(90,18);
    cout<<" (| ,-_| \\ | / |_-, |)";
    gotoxy(90,19);
    cout<<"   //`__\\.-.-./__`\\\\";
    gotoxy(90,20);
    cout<<"  // /.-(() ())-.\\ \\\\";
    gotoxy(90,21);
    cout<<" (\\ |)   '---'   (| /)";
    gotoxy(90,22);
    cout<<"  ` (|           |) `";
    gotoxy(90,23);
    cout<<"    \\)           (/";
}

void Spider::info ()const{
    system("cls");
    cout<<"Mutated cave spider"<<endl;
    cout<<"It can do only basic attacks"<<endl;
}
