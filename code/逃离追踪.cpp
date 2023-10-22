//game_2.cpp
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include<iostream>
#include<windows.h>
using namespace std;
HANDLE hMutex = NULL;
int xl;
int yl;
int lv;
int flag=0;
int score=0;
int max_s=0;
void gotoxy(int x,int y){
	COORD pos;
	pos.X=x-1;
	pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int round(float f){
    if(f>=(int)f+0.5){
        return (int)f+1;
    }return (int)f;
}
class Randomize {
public:
    int pre;
    int operator!();
} rnd;
int Randomize::operator!() {
    srand((unsigned)time(NULL));
    pre=rand()+pre%9997+1;
    return pre;
}
class Entity{
public:
    int x;
    int y;
    int px;
    int py;
};
class Player:public Entity{
public:
    void draw(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		gotoxy(px*2,py+1);
        puts("  ");
		gotoxy(x*2,y+1);
        puts("��");
    
    }
    void move(char d){
        if((d==*"w")&&(y!=1)){y--;}
        else if((d==*"a")&&(x!=1)){x--;}
        else if((d==*"d")&&(x!=xl)){x++;}
        else if((d==*"s")&&(y!=yl)){y++;}
    }
    void reset(){
        x=1;
        y=1;
    }
    
}pl;
class Food:public Entity{
public:
    void draw(){
    gotoxy(x*2,y+1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);
    puts("��");
    }
    void reset(){
        x=!rnd%xl+1;
        y=!rnd%yl+1;
    }
    void test(Player &A){
        if((x==A.x)&&(y==A.y)){
        reset();
        score++;
        max_s+=score>max_s;
        }
    }
}food;
class Enemy{
public:
    float sp;
    float x;
    float y;
    int px;
    int py;
    void reset(){
        x=xl;
        y=yl;
    }
    void move(Player &A){
        float dt=hypot(x-A.x,y-A.y);
        px=x;
        py=y;
        if(dt<sp){
            x=A.x;
            y=A.y;
        }else{
        x=x+(A.x-x)/dt*sp;
        y=y+(A.y-y)/dt*sp;
        }
    }
    void draw(){
        gotoxy(round(x)*2,round(y)+1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        puts("��");
    }
    void pl__test(Player &A){
        if((x==A.x)&&(y==A.y)){
        A.reset();
        reset();
        score-=5;
        }
    }
}en;
inline void input(){
    pl.move(getch());
}
void check(){
	for(int i=100;i>0;i--)cout<<i<<endl;
	for(char i=33;i<100;i++)cout<<i<<" ";
	gotoxy(1,90);
	cout<<"����У�ԣ�\n��ȷ���������뷨ΪӢ��״̬��\n���������ϱߵ����ֺ����ұߵ��ַ������ִ�Сд�����ÿո�ֿ���\n������Ϻ󣬰��س��Լ�����";
	gotoxy(1,103);
	char c;
	cin>>yl>>c;
	xl=c-33;
	yl+=1;
	system("cls");
	gotoxy(1,1);
	//cout<<xl<<c<<yl;
}
DWORD WINAPI chase(LPVOID lpParamter){
	while(1){
		//Sleep(1000);
		WaitForSingleObject(hMutex, INFINITE);
		en.move(pl);
    	en.pl__test(pl);
    	//ReleaseMutex(hMutex);
    	//WaitForSingleObject(hMutex, INFINITE);
    	if(flag||(en.px!=(int)en.x)||(en.py!=(int)en.y)){
        	system("cls");
      		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
       	 	cout << "������" << score << "  ��߷֣�" << max_s;
        	food.draw();
    	    pl.draw();
    	    en.draw();
    	    //gotoxy(1,yl+1);
    	    flag=0;
    	    en.sp+=0.000000002*lv;
    		ReleaseMutex(hMutex);
    	}
	}
    return 0L;
}

void inform(){
	cout<<"С��Ϸ������׷�� V1.5\n\n��Ϸ˵����\n>�� w ��s ��a ��d �Կ���������ƶ���\n>�����������ƿ��Ͽɵ�һ�֣�\n>����׷�����飬�����׷�ϼ���֣�\n>�����ٶȻ�����ʱ������Ʊ��Խ��Խ�졣"<<endl;
	cout<<"\n������1��2��3��ѡ���Ѷȡ�\n\n1-��\n2-�е�\n3-����"; 
	char in;
	while(1){
		in=getch();
		if(in>48&&in<52){
			lv=in-48;
			break;
		}
	}
	system("cls");
}
int main(){
	//getch();
	check();
	inform();
    pl.reset();
    food.reset();
    en.reset();
    en.sp=0.000003;
    //int flag=0;
    cout << "������" << score << "  ��߷֣�0";
    food.draw();
    pl.draw();
    en.draw();
    //gotoxy(1,yl+1);
    getch();
    HANDLE hThread = CreateThread(NULL, 0, chase, NULL, 0, NULL);
    CloseHandle(hThread);
    while(1){
    	WaitForSingleObject(hMutex, INFINITE);
        if(kbhit()){
        input();
        food.test(pl);
        flag=1;
        }
        //en.move(pl);
        //en.pl__test(pl);
        //sleep(0.5);
        ReleaseMutex(hMutex);
        WaitForSingleObject(hMutex, INFINITE);
        /*if(flag||(en.px!=(int)en.x)||(en.py!=(int)en.y)){
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
        cout << "������" << score << "  ��߷֣�" << max_s;
        food.draw();
        pl.draw();
        //en.draw();
        //gotoxy(1,yl+1);
        flag=0;
        //en.sp+=0.00000002*pow(lv,2);
        ReleaseMutex(hMutex);
        }
        */
    }
    return 0;
}
