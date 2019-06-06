#include "log.h"
#include "map.h"

#define cout std::cout
#define endl std::endl

void printLog(){
    gotoxy(0,20);
    cout<<(char)201;
    for(int i=0;i<30;i++)
        cout<<(char)205;
    cout<<(char)187;
    cout<<endl;
    for(int i=0;i<=1;i++){
        cout<<(char)186;
        for(int j=0;j<30;j++)
            cout<<' ';
        cout<<(char)186;
        cout<<endl;
    }
    cout<<(char)200;
    for(int i=0;i<30;i++)
        cout<<(char)205;
    cout<<(char)188;
    gotoxy(1,21);
    cout<<"Log: ";
}

void updateLog(const char* log){
    gotoxy(1,22);
    for(int j=0;j<30;j++)
        cout<<' ';
    gotoxy(1,22);
    cout<<log;
}

void printBattleLog(){
    gotoxy(33,1);
    cout<<(char)201;
    for(int i=0;i<50;i++)
    cout<<(char)205;
    cout<<(char)187;


    gotoxy(33,2);
    cout<<(char)186;
    for(int i=0;i<50;i++)
         cout<<' ';
    cout<<(char)186;


    gotoxy(33,3);
    cout<<(char)186;
    for(int j=0;j<50;j++)
        cout<<' ';
    cout<<(char)186;


    gotoxy(33,4);
    cout<<(char)186;
    for(int j=0;j<50;j++)
        cout<<' ';
    cout<<(char)186;

    gotoxy(33,5);
    cout<<(char)204;
    for(int j=0;j<50;j++)
        cout<<(char)205;
    cout<<(char)185;


    gotoxy(33,6);
    cout<<(char)186;
    for(int j=0;j<50;j++)
        cout<<' ';
    cout<<(char)186;


    gotoxy(33,7);
    cout<<(char)200;
    for(int i=0;i<50;i++)
        cout<<(char)205;
    cout<<(char)188;


    gotoxy(34,2);
    cout<<"Battle log: ";

    gotoxy(34,6);
        cout<<"  Attack<a>   Defend<d>   Info<i>   EnemyInfo<e>";
}
void updateBattleLog(const char* log , int n, int e){  ///n - indentifikator koi log da printvam
    gotoxy(34,3);
    if(n==-2) {                                         ///  -2 - gain exp  (e-exp)
        for(int j=0;j<50;j++)
            cout<<' ';
        gotoxy(34,3);
        cout<<"You gain "<<e<<" exp";
        gotoxy(34,4);
        cout<<log;
    }
    else if(n==-1){                                 /// -1 prosto suobshtanie
        for(int j=0;j<50;j++)
            cout<<' ';
        gotoxy(34,3);
        cout<<log;
    }
    else if(n==-3){                                 /// -3 poemane na dmg (e - dmg poet)
        gotoxy(34,4);
        for(int j=0;j<50;j++)
            cout<<' ';
        gotoxy(34,4);
        cout<<e<< " "<<log;
    }

    else if(n==-4){                                 /// dodge-vane
        gotoxy(34,4);
        for(int j=0;j<50;j++)
            cout<<' ';
        gotoxy(34,4);
        cout<<log;
    }

    else {
    for(int j=0;j<50;j++)
            cout<<' ';
    gotoxy(34,3);
    cout<<n<< " "<<log;
    }
}
