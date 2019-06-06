#include "utility.h"
#include "play.h"

#define cout std::cout
#define endl std::endl
#define setw std::setw

Map* mapSelection(Map* zone){
    char a;
    char openMap[64]="Maps/";
    label:
    system("cls");
    cout<<"1)Ghostland"<<endl;
    cout<<"2)Deadmines"<<endl;
    cout<<"3)Molten Core"<<endl;
    a=getch();
    if(a=='1'){
        strcat(openMap,"Ghostland.txt");
        zone=new Map(openMap);
    }
    else if(a=='2'){
        strcat(openMap,"Deadmines.txt");
        zone=new Map(openMap);
    }
    else if(a=='3'){
        strcat(openMap,"MoltenCore.txt");
        zone=new Map(openMap);
    }
    else goto label;
    return zone;
}

void play(Hero* player){
    Map* zone;
    char ch;
    charscr:
    system("cls");
    cout<<"Hello ";
    player->print();
    cout<<"Choose map <press m>"<<endl;
    cout<<"Exit game <press e> "<<endl;
    ch=getch();
    if(ch=='m'){
        zone=mapSelection(zone);
    }
    else if(ch=='e'){
        delete player;
        exit(0);
    }
    else goto charscr;
    system("cls");
    zone->print();
    player->print();
    printLog();
    while(true){
        char c;
        c=getch();
        zone->moveSquare(c);
        if(c=='s'){
            player->save();
            updateLog("You saved the game");
        }
        if(c=='e'){
            system("cls");
            delete player;
            exit(0);

        }
        ch=zone->getNextPos();
        switch(ch){
            case 'M':{
                    zone->setNextPos('-');
                    if(battleScreen(player,false,zone)){
                        system("cls");
                        zone->print();
                        player->print();
                        printLog();
                        updateLog("You defeated an enemy!!");
                    }
                    else {
                        system("cls");
                        cout<<"You were defeated in battle..."<<endl;
                        cout<<"To continue your journey please pick up new map and you will be revived."<<endl;
                        cout<<"Press a button to select map."<<endl;
                        getch();
                        delete zone;
                        player->heal();
                        zone=mapSelection(zone);
                        system("cls");
                        zone->print();
                        player->print();
                        printLog();
                    }
            }break;

            case 'B':{
                    zone->setNextPos('-');
                    if(battleScreen(player,true,zone)){
                        system("cls");
                        zone->print();
                        player->print();
                        printLog();
                        updateLog("You defeated the boss!!");
                    }
                    else {
                        system("cls");
                        cout<<"You were defeated in battle..."<<endl;
                        cout<<"To continue your journey please pick up new map and you will be revived."<<endl;
                        cout<<"Press a button to select map."<<endl;
                        getch();
                        delete zone;
                        player->heal();
                        zone=mapSelection(zone);
                        system("cls");
                        zone->print();
                        player->print();
                        printLog();
                    }
            }break;

            case 'T':{
                    zone->setNextPos('-');
                    treasureScreen(player);
            }break;

            case 'O': {
                    delete zone;
                    zone=mapSelection(zone);
                    system("cls");
                    zone->print();
                    player->print();
                    printLog();
            }break;

            default: {
                if(c!='s'){
                    updateLog("You moved");
                    zone->update();
                }
            }
        }

    }

}
bool battleScreen(Hero* player,bool isBossBattle ,Map* zone){
    char ch;
    Monster* monster;
    int mapIndex=zone->getMapIndex();

    if(isBossBattle){
        if(mapIndex==0)
            monster=new Patchwerk(player);
        if(mapIndex==1)
            monster=new Togwaggle(player);
        if(mapIndex==2)
            monster=new Raggnaros(player);
    }
    else {
        int a=rand()%3 + mapIndex*3;
        if(a==0)
            monster=new Goblin(player);
        if(a==1)
            monster=new Undead(player);
        if(a==2)
            monster=new Combatant(player);
        if(a==3)
            monster=new Kobold(player);
        if(a==4)
            monster=new Spider(player);
        if(a==5)
            monster=new Furbolg(player);
        if(a==6)
            monster=new Giant(player);
        if(a==7)
            monster=new Rager(player);
        if(a==8)
            monster=new Flamewalker(player);
    }
    ///print battle screen
    player->battleStart();
    battle:
    system("cls");
    player->printStats();
    monster->printStats();
    monster->printArt();
    player->printArt();
    printBattleLog();

    while(true){
        battle2:
        ch=getch();
        if(ch=='a'){
            double n=player->atack();
            monster->takeDamage(n);
            if(monster->isDefending())
                updateBattleLog("damage dealt",n*0.4);
            else
                updateBattleLog("damage dealt",n);
            if(monster->isDead()){
                updateBattleLog("Press a button to continue.",-2,monster->giveExp());
                player->gainExp(monster->giveExp());
                getch();
                delete monster;
                return true;
            }
        }
        else if(ch=='d'){
            player->defend();
            updateBattleLog("You are defending.");

        }
        else if(ch=='i'){
            player->info();
            cout<<"press a button go back to the battle."<<endl;
            getch();
            goto battle;
        }
        else if(ch=='e'){
            monster->info();
            cout<<"press a button go back to the battle."<<endl;
            getch();
            goto battle;
        }
        else goto battle2;

        ///monster turn
        int monsterHp=monster->getHp();
        int monsterMaxHp=monster->getMaxHp();
        if(monsterHp>=0.20*monsterMaxHp && monsterHp<=0.35*monsterMaxHp){
            monster->defend();
            updateBattleLog("Monster is defending",-4);
        }
        else {
            int chanceToHit=100;
            if(player->isDefending())
                chanceToHit=rand()%100+1;

            if(chanceToHit<=60){
                updateBattleLog("You dodged enemy's  attack!",-4);
                player->resetDef();
                chanceToHit=100;
            }

            else {
                int n=monster->atack();
                player->takeDamage(n);
                updateBattleLog("damage taken",-3,n);

                if(player->isDead()){
                    updateBattleLog("You died.",-4);
                    getch();
                    delete monster;
                    return false;
                }
            }
        }

    }
}

void treasureScreen(Hero* player){
    player->heal();
    gotoxy(0,MAX_ZONE_HEIGHT+1);
    player->print();
    updateLog("You picked up healing potion!");
}
