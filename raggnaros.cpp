#include "raggnaros.h"
#include "map.h"
#include "utility.h"

#define cout std::cout
#define endl std::endl

Raggnaros::Raggnaros(Hero* player, const char* name, int str, int inte, double _hp):Monster(player,name,str,inte,_hp){
    level=level+2;
    exp=exp*level*10;
    elementalPower=100;
    maxHp=maxHp + level*_hp;
    hp=maxHp;
}

double Raggnaros::atack(){
    isDef=false;
    int buff=rand()%10;
    if(hp<0.20*maxHp){
        buff+= strength + intellect + elementalPower*0.5;
        elementalPower-=10;
        return buff;
    }
    buff +=strength/2+intellect/2;
    return buff;
}

void Raggnaros::defend(){
    isDef=true;
}

void Raggnaros::printArt() const{
    gotoxy(90,12);
    cout<<"   ,    ,    /\\   /\\";
    gotoxy(90,13);
    cout<<"  /( /\\ )\\  _\\ \\_/ /_";
    gotoxy(90,14);
    cout<<"  |\\_||_/| < \\_   _/ >";
    gotoxy(90,15);
    cout<<"  \\______/  \\|0   0|/";
    gotoxy(90,16);
    cout<<"    _\\/_   _(_  ^  _)_";
    gotoxy(90,17);
    cout<<"   ( () ) /`\\|V'''V|/`\\";
    gotoxy(90,18);
    cout<<"     {}   \\  \\_____/  /";
    gotoxy(90,19);
    cout<<"     ()   /\\   )=(   /\\";
    gotoxy(90,20);
    cout<<"     {}  /  \\_/\\=/\\_/  \\";

}

void Raggnaros::printStats()const{
    Monster::printStats();
    gotoxy(101,5);
    cout<<"EP:"<<elementalPower<<"/100";
}

void Raggnaros::updateStats()const{
    Monster::updateStats();
    gotoxy(101,5);
    for(int j=0;j<15;j++)
        cout<<' ';
    cout<<(char)186;
    gotoxy(101,5);
    cout<<"EP:"<<elementalPower<<"/100";
}

void Raggnaros::info()const{
    system("cls");
    cout<<"DIE INSECT\n"<<endl;
    cout<<"When hp is reduced to 20% he stats using his elemental powers dealing extra dmg."<<endl;
}
