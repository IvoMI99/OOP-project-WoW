#include "utility.h"
#include "paladin.h"
#include "map.h"
#include "log.h"

#define cout std::cout

Paladin::Paladin(const char* name , int str , int inte):Hero(name,str,inte){
    hitCounter=0;
    holyPoints=3;
}

Paladin::Paladin(std::ifstream& fin):Hero(fin){
    fin>>hitCounter;
}

Paladin::Paladin(const Paladin& other):Hero(other){
    hitCounter=other.hitCounter;
}

Paladin& Paladin::operator=(const Paladin& other ){
    if(this!=&other){
        Hero :: operator = (other);
        hitCounter=other.hitCounter;
    }
    return *this;
}


void Paladin::battleStart(){
    isDef=false;
    holyPoints=3;
}

double Paladin::atack(){
    gotoxy(34,6);
    cout<<"  Attack<a>   HolyShock<h>   Judgment<j>        ";

    char atck;
    int buff=rand()%10;
    chooseAtack:
    atck=getch();
    if(atck=='a'){
        gotoxy(34,6);

        cout<<"  Attack<a>   Defend<d>   Info<i>   EnemyInfo<e>";
        updateStats();
        if(hitCounter==2){
            hitCounter=0;
            int n = (0.7*strength + 0.7*intellect)*0.7 + 0.7*strength+0.7*intellect;
            hp+=1/3*n;
            holyPoints++;
            if(holyPoints>3)
                holyPoints=3;
            if(hp>maxHp)
                hp=maxHp;
            return n;
        }
        else {
            hitCounter++;
            return 0.5*strength+0.5*intellect;
        }
    }
    else if(atck=='h'){
        if(holyPoints<1){
            updateBattleLog("Not enough Holy Points for HolyShock!");
            updateBattleLog("",-4);
            goto chooseAtack;

        }
        holyPoints--;
        hp=hp+intellect*2+buff;
        if(hp>maxHp)
            hp=maxHp;
        gotoxy(34,6);
        cout<<"  Attack<a>   Defend<d>   Info<i>   EnemyInfo<e>";
        updateStats();
        return intellect*2+buff;
    }
    else if (atck=='j'){
        if(holyPoints<2){
            updateBattleLog("Not enough Holy Points for Judgment!");
            updateBattleLog("",-4);
            goto chooseAtack;

        }
        holyPoints-=2;
        gotoxy(34,6);
        cout<<"  Attack<a>   Defend<d>   Info<i>   EnemyInfo<e>";
        updateStats();
        return intellect*2+strength*2;

    }
    else goto chooseAtack;

}

void Paladin::defend(){
    isDef=true;
    updateStats();
}

bool Paladin::save(){
   std::ofstream fout;
    std::fstream charlist("Characters/CharacterList.txt");
    char fname[32];
    bool flag=true;
    while(charlist.good()){
        charlist.getline(fname,32);
        if(!strcmp(fname,name)){
            strcpy(fname,"Characters/");
            strcat(fname,name);
            fout.open(fname);
            flag=false;
            break;
            }
        }
    charlist.clear();
    if(flag){
        charlist<<std::endl<<name;
        char temp[64]="Characters/";
        strcat(temp,name);
        fout.open(temp);
    }
    charlist.close();
    if(!fout){
        std::cerr<<"File could not be open"<<std::endl;
        return false;
    }
    if(!fout){
        std::cerr<<"File could not be open"<<std::endl;
        return false;
    }
    fout<<3<<std::endl;
    fout<<name<<std::endl;
    fout<<strength<<std::endl;
    fout<<intellect<<std::endl;
    fout<<level<<std::endl;
    fout<<maxHp<<std::endl;
    fout<<hp<<std::endl;
    fout<<exp<<std::endl;
    fout<<nextLevel<<std::endl;
    fout<<hitCounter<<std::endl;
    fout<<holyPoints<<std::endl;
    fout.close();
    return true;
}

void Paladin::printArt()const {
    gotoxy(0,7);
    cout<<"          _,."<<std::endl;
    cout<<"       ,` -.)" <<std::endl;
    cout<<"      ( _/-\\\\-._"<<std::endl;
    cout<<"     /,|`--._,-^|            ,"<<std::endl;
    cout<<"     \\_| |`-._/||          ,'|"<<std::endl;
    cout<<"       |  `-, / |         /  /"<<std::endl;
    cout<<"       |     || |        /  /"<<std::endl;
    cout<<"        `r-._||/   __   /  /"<<std::endl;
    cout<<"    __,-<_     )`-/  `./  /"<<std::endl;
    cout<<"   '  \\   `---'   \\   /  /"<<std::endl;
    cout<<"  |    |           |./  /"<<std::endl;
    cout<<"  |    /           //  /"<<std::endl;
    cout<<"   \\_/' \          |/  /"<<std::endl;
    cout<<"    |    |   _,^-'/  /"<<std::endl;
    cout<<"    |    , ``   (\/  /_"<<std::endl;
    cout<<"     \\,.->._    \X-=/^"<<std::endl;
    cout<<"     (  /   `-._//^`"<<std::endl;
    cout<<"      `Y-.____(__}"<<std::endl;
    cout<<"       |     {__)"<<std::endl;
}

void Paladin::printStats()const{
    Hero::printStats();
    gotoxy(3,5);
    cout<<"HolyPoints: "<<holyPoints<<"/3";
}

void Paladin::updateStats()const {
    gotoxy(3,4);
    for(int j=0;j<15;j++)
        cout<<' ';
    gotoxy(3,4);
    cout<<"HP:"<<hp<<"/"<<maxHp;

    gotoxy(3,5);
    for(int j=0;j<15;j++)
        cout<<' ';
    gotoxy(3,5);
    cout<<"HolyPoints: "<<holyPoints<<"/3";
}

void Paladin::info()const{
    system("cls");
    cout<<"Basic attacks:\n Every 3rd hit will deal extra dmg healing you for 1/3 of the dmg dealt\n"<<std::endl;
    cout<<"Holy Shock\n Strong attack scaling with intellect. Heals for 100% of the damage dealt. Requires 1 Holy Points\n"<<std::endl;
    cout<<"Judgment\n The most powerful attack in the paladin's arsenal. Requires 2 Holy Points\n"<<std::endl;
}
