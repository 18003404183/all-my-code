;//s_orbit.cpp
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include<iostream>
#include<unistd.h>
using namespace std;
#define xl 13
#define yl 10
int round(float f){
    if(f>=(int)f+0.5){
        return (int)f+1;
    }return (int)f;
}
class Randomize {
public:
    int pre;
    int operator!();
}rnd;
int Randomize::operator!() {
    srand((unsigned)time(NULL));
    pre=rand()+pre%9997+1;
    return pre;
}
class Creature{
public:
    float a;
    float vx;
    float vy;
    float x;
    float y;
};
class Player:public Creature{
public:
    void draw(){
    gotoxy(x*2,y+1);
    puts("\033[0;37;41m  \033[0m");
    }
    void move(char d){
        if((d==*"2")&&(y!=1)){y--;}
        else if((d==*"4")&&(x!=1)){x--;}
        else if((d==*"6")&&(x!=xl)){x++;}
        else if((d==*"8")&&(y!=yl)){y++;}
    }
    void reset(){
        x=1;
        y=1;
    }
}pl;
class Entity:public Creature{
public:
    int px;
    int py;
    
    void move(Player &A){
        float ds=hypot(x-A.x,y-A.y);
        a=0.00001/pow(ds,2);
        px=x;
        py=y;
        if(ds<hypot(vx,vy)){
            x=A.x;
            y=A.y;
        }else{
            vx=vx+(A.x-x)/ds*a;
            vy=vy+(A.y-y)/ds*a;
            x+=vx;
            y+=vy;
        }
    }
    void draw(){
        gotoxy(round(x)*2,round(y)+1);
        puts("\033[0;37;44m  \033[0m");
    }
    void reset(){
        x=xl;
        y=yl;
    }
}en;
inline void input(){
    char d;
    d=getch();
    pl.move(d);
}
    
int main(){
    pl.reset();
    en.reset();
    pl.x=5;
    pl.y=5;
    en.vy=-0.001;
    int flag=0;
    pl.draw();
    en.draw();
    gotoxy(1,yl+1);
    getch();
    while(1){
        if(kbhit()){
        input();
        flag=1;
        }
        en.move(pl);
        sleep(0.5);
        if(flag||(en.px!=(int)en.x)||(en.py!=(int)en.y)){
        clrscr();
        pl.draw();
        en.draw();
        gotoxy(1,yl+1);
        flag=0;
        }
    }
    return 0;
}






    
