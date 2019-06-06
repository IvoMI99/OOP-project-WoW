#include "map.h"
#include "utility.h"

void setcursor(bool flag){
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;

    cci.dwSize = 25;
    cci.bVisible = flag;

    SetConsoleCursorInfo(hout, &cci);
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}

void textcolor (int color){
    static int __BACKGROUND;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color + (__BACKGROUND << 4));
}


const int UP_ARROW=72;
const int DOWN_ARROW=80;
const int LEFT_ARROW=75;
const int RIGHT_ARROW=77;


Map::Map(const char* fileName){
    std::ifstream fin(fileName);
    if(!fin)
            std::cerr<<"File could not be open"<<std::endl;
    int a;
;   for(int i=0;i<MAX_ZONE_HEIGHT;i++){
        for(int j=0;j<MAX_ZONE_WIDTH;j++){
            a=rand()%100;
            fin.get(zone[i][j]);
            if (a<13 && zone[i][j]=='-')
                zone[i][j]='M';
            else if(a>13 && a <20 && zone[i][j]=='-')
                zone[i][j]='T';
        }
        fin.ignore();
    }
    fin>>x>>y>>mapIndex;
    fin.close();

}

Map::Map(const Map& other){
    for(int i=0;i<MAX_ZONE_HEIGHT;i++)
        for(int j=0;j<MAX_ZONE_WIDTH;j++)
            zone[i][j]=other.zone[i][j];
    x=other.x;
    y=other.y;
    mapIndex=other.mapIndex;
}

void Map::print()const {
    int a=0;
    textcolor(15);
    for(int i=0;i<MAX_ZONE_HEIGHT;i++){
        for(int j=0;j<MAX_ZONE_WIDTH;j++){
            if(zone[i][j]=='X'){
                textcolor(RED);
                std::cout<<zone[i][j];
                textcolor(WHITE);
            }
            else if(zone[i][j]=='M'){
                textcolor(MAGENTA);
                std::cout<<zone[i][j];
                textcolor(WHITE);
            }
            else if(zone[i][j]=='B'){
                textcolor(GREEN);
                std::cout<<zone[i][j];
                textcolor(WHITE);
            }
            else if(zone[i][j]=='T'){
                textcolor(YELLOW);
                std::cout<<zone[i][j];
                textcolor(WHITE);
            }
            else if(zone[i][j]=='O'){
                textcolor(CYAN);
                std::cout<<zone[i][j];
                textcolor(WHITE);
            }
            else std::cout<<zone[i][j];
        }
        std::cout<<(char)186;
        if(a==0)
            std::cout<<"X - Your current possition";
        if(a==1)
            std::cout<<"M - Monster";
        if(a==2)
            std::cout<<"T - Treasure";
        if(a==3)
            std::cout<<"O - Portal";
        if(a==4)
            std::cout<<"B - Big bad boss";
        if(a==5)
            std::cout<<"Controls:";
        if(a==6)
            std::cout<<"^ - UP";
        if(a==7)
            std::cout<<"< - LEFT";
        if(a==8)
            std::cout<<"> - RIGHT";
        if(a==9)
            std::cout<<"v - DOWN";
        if(a==10)
            std::cout<<"Press <s> to save the game";
        if(a==11)
            std::cout<<"Press <e> to exit the game ";
        std::cout<<std::endl;
        a++;
    }
    for(int j=0;j<MAX_ZONE_WIDTH;j++)
        std::cout<<(char)205;
    std::cout<<(char)188<<std::endl;


}

void Map::moveSquare(int c){
    switch(c){
        case UP_ARROW: {
            if(x-1>=0 && zone[x-1][y]!='\\' && zone[x-1][y]!='|' && zone[x-1][y]!='/' && zone[x-1][y]!='_' ){
                gotoxy(y,x);
                std::cout<<'-';
                zone[x][y]='-';
                x=x-1;
                nextPosition=zone[x][y];
                zone[x][y]='X';
                textcolor(RED);
                gotoxy(y,x);
                std::cout<<'X';
                textcolor(WHITE);
            }
        };break;
        case DOWN_ARROW: {
            if(x+1<MAX_ZONE_HEIGHT && zone[x+1][y]!='\\' && zone[x+1][y]!='|' && zone[x+1][y]!='/' && zone[x+1][y]!='_'){
                gotoxy(y,x);
                std::cout<<'-';
                zone[x][y]='-';
                x=x+1;
                nextPosition=zone[x][y];
                zone[x][y]='X';
                textcolor(RED);
                gotoxy(y,x);
                std::cout<<'X';
                textcolor(WHITE);
            }
        };break;
        case RIGHT_ARROW: {
            if(y+1<MAX_ZONE_WIDTH && zone[x][y+1]!='\\' && zone[x][y+1]!='|' && zone[x][y+1]!='/' && zone[x][y+1]!='_'){
                gotoxy(y,x);
                std::cout<<'-';
                zone[x][y]='-';
                y=y+1;
                nextPosition=zone[x][y];
                zone[x][y]='X';
                textcolor(RED);
                gotoxy(y,x);
                std::cout<<'X';
                textcolor(WHITE);
            }
        };break;
        case LEFT_ARROW: {
            if(y-1>=0 && zone[x][y-1]!='\\' && zone[x][y-1]!='|' && zone[x][y-1]!='/' && zone[x][y-1]!='_'){
                gotoxy(y,x);
                std::cout<<'-';
                zone[x][y]='-';
                y=y-1;
                nextPosition=zone[x][y];
                zone[x][y]='X';
                textcolor(RED);
                gotoxy(y,x);
                std::cout<<'X';
                textcolor(WHITE);
            }
            };break;
        }
}

void Map::update(){
    int a;
    for(int i=0;i<MAX_ZONE_HEIGHT;i++)
        for(int j=0;j<MAX_ZONE_WIDTH;j++){
            if(zone[i][j]=='M'){
                a=rand()%30;
                switch(a){
                    case 0:{
                            if(i-1>=0 && zone[i-1][j]=='-'){
                                gotoxy(j,i);
                                std::cout<<'-';
                                zone[i][j]='-';
                                zone[i-1][j]='M';
                                textcolor(MAGENTA);
                                gotoxy(j,i-1);
                                std::cout<<'M';
                                textcolor(WHITE);
                            }
                    };break;
                    case 1:{
                            if(i+1<MAX_ZONE_HEIGHT && zone[i+1][j]=='-'){
                                gotoxy(j,i);
                                std::cout<<'-';
                                zone[i][j]='-';
                                zone[i+1][j]='M';
                                textcolor(MAGENTA);
                                gotoxy(j,i+1);
                                std::cout<<'M';
                                textcolor(WHITE);
                            }
                    };break;
                    case 2:{
                            if(j+1<MAX_ZONE_WIDTH && zone[i][j+1]=='-'){
                                gotoxy(j,i);
                                std::cout<<'-';
                                zone[i][j]='-';
                                zone[i][j+1]='M';
                                textcolor(MAGENTA);
                                gotoxy(j+1,i);
                                std::cout<<'M';
                                textcolor(WHITE);
                            }
                    };break;
                    case 3:{
                            if(j-1>=0 && zone[i][j-1]=='-'){
                                gotoxy(j,i);
                                std::cout<<'-';
                                zone[i][j]='-';
                                zone[i][j-1]='M';
                                textcolor(MAGENTA);
                                gotoxy(j-1,i);
                                std::cout<<'M';
                                textcolor(WHITE);
                            }
                    };break;
                }
        }
    }
}


char Map::getNextPos()const {
    return nextPosition;
}
void Map::setNextPos(char pos){
    nextPosition=pos;
}
short Map::getMapIndex()const{
    return mapIndex;
}
