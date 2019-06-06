#include "utility.h"
#include "play.h"
using namespace std;
const int MAX_NAME_LEN=32;


int main(){
    textcolor(WHITE);
    setcursor(false);
    srand(time(0));
    char ch;
    Hero* player;
    start:
    cout<<"#    #  ####  #####  #      #####      ####  ######    #    #   ##   #####   ####  #####    ##   ###### #####\n#    # #    # #    # #      #    #    #    # #         #    #  #  #  #    # #    # #    #  #  #  #        #\n#    # #    # #    # #      #    #    #    # #####     #    # #    # #    # #      #    # #    # #####    #\n# ## # #    # #####  #      #    #    #    # #         # ## # ###### #####  #      #####  ###### #        #\n##  ## #    # #   #  #      #    #    #    # #         ##  ## #    # #   #  #    # #   #  #    # #        #\n#    #  ####  #    # ###### #####      ####  #         #    # #    # #    #  ####  #    # #    # #        #   "<<endl<<endl<<endl;
    cout<<"Create new character <press n>"<<endl;
    cout<<"Load existing character <press l>"<<endl;
    cout<<"Exit game <press e> "<<endl;
    ch=getch();
    system("cls");
    if(ch=='n'){
        char c;
        charCreate:
        cout<<"Chose class: "<<endl<<"Warrior (press w)\n"<<
            "Mage (press m)\n"<<"Paladin (press p)\n";
        c=getch();
        system("cls");
        switch(c){
            case 'w':{  char name[32];
                        cout<<"Enter character name: ";
                        cin.getline(name,32);
                        player=new Warrior(name);};break;

            case 'm':{  char name[32];
                        cout<<"Enter character name: ";
                        cin.getline(name,32);
                        player=new Mage(name);};break;

            case 'p':{  char name[32];
                        cout<<"Enter character name: ";
                        cin.getline(name,32);
                        player=new Paladin(name);};break;
            default: goto charCreate;
        }
    }
    else if(ch=='l'){
        ifstream fin("Characters/CharacterList.txt", ios::in);
        if(!fin)
            cerr<<"File could not be open"<<endl;
        char name[9][MAX_NAME_LEN];
        int k=1;
        while(fin.good()){
            fin.getline(name[k],32);
            cout<<k<<")"<<name[k]<<endl;
            k++;
        }
        fin.clear();
        fin.close();
        char c;
        char tempname[MAX_NAME_LEN]="\n";
        loadChar:
        c=getch();
        for(int i=1;i<k;i++)
            if(i==c - '0'){
                strcpy(tempname,name[i]);
                break;
        }
        if(!strcmp(tempname,"\n"))
            goto loadChar;
        char openHero[64]="Characters/";
        strcat(openHero,tempname);
        fin.open(openHero);
        if(!fin)
            cerr<<"File could not be open"<<endl;
        int a;
        fin>>a;
        system("cls");
        switch(a){
            case 1:{  player =  new Warrior(fin); };break;

            case 2:{  player =  new Mage(fin); };break;

            case 3:{  player =  new Paladin(fin); };break;
        }

        fin.close();
    }
    else if(ch=='e'){
        exit(0);
    }
    else goto start;
    play(player);

    return 0;
}
