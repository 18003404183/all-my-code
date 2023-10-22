#include<conio.h>
#include<iostream>
#include<list>
#include<windows.h>
#include<math.h>
#define mx 40
#define my 24
#define G 1
#define iter list<matter>::iterator
using namespace std;
int pcsl[2]={0,0};
int csl[2]={0,0};


void gotoxy(int x,int y){
	COORD pos;
	pos.X=x-1;
	pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void draw(int pos[2],int ppos[2],string s){
	gotoxy(2*ppos[0]+mx,pcsl[1]+my/2);
	cout<<"  ";
	ppos[0]=pos[0];ppos[1]=pos[1];
	gotoxy(2*pos[0]+mx,pos[1]+my/2);
	cout<<s;
}
void draw(double pos[2],double ppos[2],string s){
	gotoxy(2*ppos[0]+mx,pcsl[1]+my/2);
	cout<<"  ";
	ppos[0]=pos[0];ppos[1]=pos[1];
	gotoxy(2*pos[0]+mx,pos[1]+my/2);
	cout<<s;
}
void vm(char in){
	if(in==*"w"&&csl[1]!=-my/2+1){
		pcsl[1]=csl[1];
		csl[1]--;
	}else if(in==*"a"&&csl[0]!=-mx/2+1){
		pcsl[0]=csl[0];
		csl[0]--;
	}else if(in==*"s"&&csl[1]!=my/2){
		pcsl[1]=csl[1];
		csl[1]++;
	}else if(in==*"d"&&csl[0]!=mx/2-1){
		pcsl[0]=csl[0];
		csl[0]++;
	}
}
int main(){
	while(1){
		if(pcsl[0]!=csl[0]||pcsl[1]!=csl[1])draw(csl,pcsl,"[]");
		if(kbhit()){
			vm(getch());
		}
	}
	return 0;
} 

