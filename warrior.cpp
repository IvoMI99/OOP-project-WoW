#include "utility.h"
#include "warrior.h"
#include "map.h"


Warrior::Warrior(const char* name , int str , int inte):Hero(name,str,inte) {
    rage=0;
    rageBuff=0;
}

Warrior::Warrior(std::ifstream& fin):Hero(fin){
    fin>>rage;
    rageBuff=0;
}

Warrior::Warrior(const Warrior& other):Hero(other) {
    rage=other.rage;
    rageBuff=0;
}

Warrior& Warrior::operator=(const Warrior& other) {
    if(this!=&other){
        Hero :: operator = (other);
        rage=other.rage;
        rageBuff=other.rageBuff;
    }
    return *this;
}


double Warrior::atack() {
    rage+=2;
    if(rage>100)
        rage=100;
    updateStats();
    return (strength+0.3*intellect)*rageBuff + strength+0.3*intellect;
}

void Warrior::battleStart(){
    isDef=false;
    rageBuff=rage*0.05;
    rage=0;
}

void Warrior::defend() {
    rage+=3;
    if(rage>100)
        rage=100;
    isDef=true;
    updateStats();
}

bool Warrior::save(){
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
    fout<<1<<std::endl;
    fout<<name<<std::endl;
    fout<<strength<<std::endl;
    fout<<intellect<<std::endl;
    fout<<level<<std::endl;
    fout<<maxHp<<std::endl;
    fout<<hp<<std::endl;
    fout<<exp<<std::endl;
    fout<<nextLevel<<std::endl;
    fout<<rage<<std::endl;

    fout.close();
    return true;
}

void Warrior::printArt()const {
    gotoxy(0,7);
    std::cout<<"                    ,dM\n                   dMMP\n                  dMMM'\n                  \\MM/\n                  dMMm.\n                 dMMP'_\---.\n                _| _  p ;88;`.\n              ,db; p >  ;8P|  `.\n             (``T8b,__,'dP |   |\n              |   `Y8b..dP  ;_  |\n             |    |`T88P_ /  `\\;\n             :_.-~|d8P'`Y/    /\n              \\_   TP    ;   7`\\\n   ,,__        >   `._  /'  /   `\\_\n   `._ """"~~~~------|`\;' ;     ,'      \\\n      " "~~~-----~~~'\__[|;' _.-'        \\\n              ;--..._     .-'-._     ;\n             /      /`~~'   ,'`\\_ ,/\n            ;_    /'        /    ,/\n            | `~-l         ;    /\n            `\\    ;       /\\.._|\n              \\    \\      \     \\\n              /`---';      `----'\n             (     /            \n              `---'";

}

void Warrior::printStats()const{
    Hero::printStats();
    gotoxy(3,5);
    std::cout<<"Rage:"<<rage<<"/100";
}

void Warrior::updateStats()const{
    gotoxy(3,4);
    for(int j=0;j<15;j++)
        std::cout<<' ';
    gotoxy(3,4);
    std::cout<<"HP:"<<hp<<"/"<<maxHp;

    gotoxy(3,5);
    for(int j=0;j<15;j++)
        std::cout<<' ';
    gotoxy(3,5);
    std::cout<<"Rage:"<<rage<<"/100";
}

void Warrior::info()const{
    system("cls");
    std::cout<<"Basic attack:\n Deals dmg scaling with strength.\n"<<std::endl;
    std::cout<<"Rage:\n Increases damage done in the next battle.\n"<<std::endl;

}
