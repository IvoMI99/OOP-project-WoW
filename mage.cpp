#include "utility.h"
#include "log.h"
#include "mage.h"
#include "map.h"


Mage::Mage(const char* name , int str, int inte):Hero(name,str,inte){
    mana=100;
}

Mage::Mage(std::ifstream& fin):Hero(fin){
    fin>>mana;
}

Mage::Mage(const Mage& other):Hero(other){
    mana=100;
}

Mage& Mage::operator=(const Mage& other){
    if(this!=&other){
        Hero :: operator = (other);
        mana=other.mana;
    }
    return *this;
}

double Mage::fireball(){
    if(mana<30){
        std::cout<<"Not enough mana"<<std::endl;
        return 0;
    }
    mana=mana-30;
    return intellect*2.5;

}

void Mage::battleStart(){
    isDef=false;
    mana=100;
}

double Mage::atack(){
    gotoxy(34,6);
        std::cout<<"  Arcane missiles<a>   Fireball<f>   Blizzard<b>";

    char atck;
    int buff=rand()%10;
    chooseAtack:
    atck=getch();
    if(atck=='a'){
        gotoxy(34,6);
        std::cout<<"  Attack<a>   Defend<d>   Info<i>   EnemyInfo<e>";
        updateStats();
        return intellect+buff;
    }
    else if(atck=='f'){
        if(mana<30){
            updateBattleLog("Not enough mana for Fireball!");
            updateBattleLog("",-4);
            goto chooseAtack;

        }
        mana=mana-30;
        gotoxy(34,6);
        std::cout<<"  Attack<a>   Defend<d>   Info<i>   EnemyInfo<e>";
        updateStats();
        return intellect*2+buff;
    }
    else if (atck=='b'){
        if(mana<45){
            updateBattleLog("Not enough mana for Blizzard!");
            updateBattleLog("",-4);
            goto chooseAtack;

        }
        mana=mana-45;
        gotoxy(34,6);
        std::cout<<"  Attack<a>   Defend<d>   Info<i>   EnemyInfo<e>";
        updateStats();
        return intellect*2.6+buff;

    }
    else goto chooseAtack;
}

void Mage::defend(){
    isDef=true;
    updateStats();
}

bool Mage::save(){
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
    fout<<2<<std::endl;
    fout<<name<<std::endl;
    fout<<strength<<std::endl;
    fout<<intellect<<std::endl;
    fout<<level<<std::endl;
    fout<<maxHp<<std::endl;
    fout<<hp<<std::endl;
    fout<<exp<<std::endl;
    fout<<nextLevel<<std::endl;
    fout<<mana<<std::endl;

    fout.close();
    return true;
}

void Mage::printArt()const{
    gotoxy(0,7);
    std::cout<<" \n                    _____\n                  .'* *.'\n               __/_*_*(_\n              / _______ \\\n             _\\_)/___\\(_/_\n            / _((\\- -/))_ \\\n            \\ \\())(-)(()/ /\n             ' \\(((()))/ '\n            / ' \\)).))/ ' \\\n           / _ \\ - | - /_  \\\n          (   ( .;''';. .'  )\n          _\\\"__ /    )\\ __'/_\n            \\/  \\   ' /  \\/\n             .'  '...' ' )\n              / /  |  \\ \\\n             / .   .   . \\\n            /   .     .   \\\n           /   /   |   \    \\\n         .'   /    b    '.  '.\n     _.-'    /     Bb     '-. '-._\n _.-'       |      BBb       '-.  '-.\n(________mrf\____.dBBBb.________)____)";

}

void Mage::printStats()const{
    Hero::printStats();
    gotoxy(3,5);
    std::cout<<"Mana:"<<mana<<"/100";
}

void Mage::updateStats()const {
    gotoxy(3,4);
    for(int j=0;j<15;j++)
        std::cout<<' ';
    gotoxy(3,4);
    std::cout<<"HP:"<<hp<<"/"<<maxHp;

    gotoxy(3,5);
    for(int j=0;j<15;j++)
        std::cout<<' ';
    gotoxy(3,5);
    std::cout<<"Mana:"<<mana<<"/100";

}

void Mage::info()const{
    system("cls");
    std::cout<<"Arcane missiles: \n Basic spell requiring no mana to use.\n"<<std::endl;
    std::cout<<"Fireball:\n A technique used by advanced magicians. Requires 30 mana to use.\n"<<std::endl;
    std::cout<<"Blizzard:\n Used only by veteran magicians. Requires 45 mana to use.\n"<<std::endl;
}
