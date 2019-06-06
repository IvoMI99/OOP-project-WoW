#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

const int MAX_ZONE_WIDTH=24;
const int MAX_ZONE_HEIGHT=12;

class Map {
private:
    char nextPosition;
    short x;
    short y;
    short mapIndex;
    char zone[MAX_ZONE_HEIGHT][MAX_ZONE_WIDTH];



public:
    Map(const char*);
    Map(const Map& );
    void print()const;
    void moveSquare(int );
    void setNextPos(char);
    char getNextPos() const ;
    void update();
    short getMapIndex()const;

};

void gotoxy(int x, int y);
void textcolor (int color);
void setcursor(bool);


#endif // MAP_H_INCLUDED
