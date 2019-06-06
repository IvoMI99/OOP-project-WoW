#include "utility.h"
#include "furbolg.h"

#define cout std::cout
#define endl std::endl

Furbolg::Furbolg(Hero* player, const char* name, int str, int inte, double hp):Monster(player,name,str,inte,hp){
    exp=exp*level*2;
}

double Furbolg::atack(){
    isDef=false;
    if(hp<0.20*maxHp)
        return strength*2;
    return strength*1.5;
}

void Furbolg::defend(){
    isDef=true;
}

void Furbolg::printArt() const {
    gotoxy(70,8);
    cout<<"                        !         !     ";
    gotoxy(70,9);
    cout<<"                       ! !       ! !   ";
    gotoxy(70,10);
    cout<<"                      ! . !     ! . ! ";
    gotoxy(70,11);
    cout<<"                         ^^^^^^^^^ ^      ";
    gotoxy(70,12);
    cout<<"                       ^             ^       ";
    gotoxy(70,13);
    cout<<"                     ^  (0)       (0)  ^       ";
    gotoxy(70,14);
    cout<<"                    ^        ""         ^       ";
    gotoxy(70,15);
    cout<<"                   ^   ***************    ^     ";
    gotoxy(70,16);
    cout<<"                 ^   *                 *   ^    ";
    gotoxy(70,17);
    cout<<"                ^   *   /\\   /\\   /\\    *    ^";
    gotoxy(70,18);
    cout<<"               ^   *                     *    ^";
    gotoxy(70,19);
    cout<<"              ^   *   /\\   /\\   /\\   /\\   *    ^";
    gotoxy(70,20);
    cout<<"             ^   *                         *    ^";
    gotoxy(70,21);
    cout<<"             ^  *                           *   ^";
    gotoxy(70,22);
    cout<<"              ^  *                           *   ^";
    gotoxy(70,23);
    cout<<"              ^ *                           *  ^  ";
    gotoxy(70,24);
    cout<<"               ^*                           * ^ ";
    gotoxy(70,25);
    cout<<"                ^ *                        * ^";
    gotoxy(70,26);
    cout<<"                ^  *                      *  ^";
    gotoxy(70,27);
    cout<<"                  ^  *       ) (         * ^";
    gotoxy(70,28);
    cout<<"                      ^^^^^^^^ ^^^^^^^^^ ";


}

void Furbolg::info ()const{
    system("cls");
    cout<<"Furbolgs are a hulking, ancient race of bear-men."<<endl;
}
