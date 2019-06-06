#include "flamewalker.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Flamewalker::Flamewalker(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=exp*level;
}

double Flamewalker::atack(){
    isDef=false;
    if(hp<0.20*maxHp)
        return strength*1.2;
    return strength;
}

void Flamewalker::defend(){
    isDef=true;
}

void Flamewalker::printArt() const {
    gotoxy(60,12);
    cout<<"            \\                  /";
    gotoxy(60,13);
    cout<<"    _________))                ((__________";
    gotoxy(60,14);
    cout<<"   /.-------./\\\\    \\    /    //\\.--------.\\";
    gotoxy(60,15);
    cout<<"  //#######//##\\\\   ))  ((   //##\\\\########\\\\";
    gotoxy(60,16);
    cout<<" //#######//###((  ((    ))  ))###\\\\########\\\\";
    gotoxy(60,17);
    cout<<"((#######((#####\\\\  \\\\  //  //#####))########))";
    gotoxy(60,18);
    cout<<" \\##' `###\\######\\\\  \\)(/  //######/####' `##/";
    gotoxy(60,19);
    cout<<"  )'    ``#)'  `##\\`->oo<-'/##'  `(#''     `(";
    gotoxy(60,20);
    cout<<"          (       ``\\`..'/''       )";
    gotoxy(60,21);
    cout<<"                     \\''(";
    gotoxy(60,22);
    cout<<"                      `- )";
    gotoxy(60,23);
    cout<<"                      / /";
    gotoxy(60,24);
    cout<<"                     ( /\\";
    gotoxy(60,25);
    cout<<"                     /\\| \\";
    gotoxy(60,26);
    cout<<"                    (  \\";
    gotoxy(60,27);
    cout<<"                        )";
    gotoxy(60,28);
    cout<<"                       /";


}

void Flamewalker::info ()const{
    system("cls");
    cout<<"Weakest of all creatures"<<endl;
}
