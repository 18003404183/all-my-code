#include<iostream>
#include<list>
#include<conio.h>
#include <math.h>
#include <string> 
#include <windows.h>
using namespace std;
#define mx 40
#define my 32
#define G 0.01
#define V 1
#define fl(a,l) for(iter a=l.begin();a!=l.end();++a)
#define iter list<matter>::iterator
#define ro(a) (int)((a)+0.5)
#define inscr(a) ((a[1])<=my/2+1&&(a[0])>=-mx/2+1&&(a[1])>=-my/2&&(a[0])<=mx/2)
int pcsl[2]={0,0};
int csl[2]={0,0};
int plc[2];
bool sel=1;
bool inpl=0;
bool ifp=0;
int sca=1;
void gotoxy(int x,int y){
	COORD pos;
	pos.X=x-1;
	pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
class matter{
public:
	double px[2];
	double x[2];
	double v[2];
	double r3;
	void force();
	void move();
};
list<matter> stars;
list<matter> planets;
iter p=stars.begin();
void matter::move(){
	px[0]=x[0];
	px[1]=x[1];
	x[0]+=v[0];
	x[1]+=v[1];
}
void matter::force(){
	fl(A,stars){
		r3=pow(hypot(A->x[0]-x[0],A->x[1]-x[1]),3);
		if(r3==0)continue;
		v[0]+=G*(A->x[0]-x[0])/r3;
		v[1]+=G*(A->x[1]-x[1])/r3;
	}		
}
		
		
		
		
void draw(int pos[2],string s){
	//if(inscr(pos)){
		gotoxy((pos[0]+mx/2)*2,-pos[1]+my/2);
		cout<<s;
	//}
}
void draw(double pos[2],string s){
	int po[2];
	po[0]=ro(pos[0]);
	po[1]=ro(pos[1]);
	draw(po,s);
}
void update(){
	fl(A,planets)A->force();
	fl(A,stars)A->force();
	fl(A,planets)A->move();
	fl(A,stars)A->move();
	fl(A,planets){
		//draw(A->px,"  ");
		draw(A->x,".");
	}
	fl(A,stars){
		//if(ro(A->x[0]-p->x[0])==ro(A->px[0]-p->px[0])&&ro(A->x[1]-p->x[1])==ro(A->px[1]-p->px[1]))continue;
		//draw(A->px,"  ");
		draw(A->x,"¡ö");
	}
}


		
void  redraw(){
	system("cls");
	draw(csl,"[]");
	fl(A,planets)draw(A->x,".");
	fl(A,stars)draw(A->x,"[]");
	gotoxy(1,my+1);
	cout<<""<<(sel?"1":"2");
}
		
		
inline void vm(char in){
	if(in==*"w"&&csl[1]!=my/2+1){
		pcsl[1]=csl[1];
		csl[1]++;
	}else if(in==*"a"&&csl[0]!=-mx/2+1){
		pcsl[0]=csl[0];
		csl[0]--;	
	}else if(in==*"s"&&csl[1]!=-my/2){
		pcsl[1]=csl[1];
		csl[1]--;
	}else if(in==*"d"&&csl[0]!=mx/2){
		pcsl[0] =csl[0];
		csl[0]++;
	}else if(in==*"c"){
		plc[0]=csl[0];
		plc[1]=csl[1];
		ifp=!ifp;
		
	}else if(in==*" "&&ifp){
		ifp=0;
		matter A;
		(sel?stars:planets).push_back(A);
		A.x[0]=plc[0];
		A.x[1]=plc[1];
		A.v[0]=V*(csl[0]-plc[0]);
		A.v[1]=V*(csl[1]-plc[1]);
		p=--(sel?stars:planets).end();
		//redraw();
		cout<<p->x[0]<<p->x[1];
	}else if(in==*"h"){
		sel=!sel;
		gotoxy(1,my+1);
		cout<<(sel?1:2);
	}
	//else if(in==*"q"&&)

}



int main(){
	redraw();
		while(1){
			
			if(!(stars.begin()==stars.end()&&planets.begin()==planets.end()))update();
			
			if(csl[0]!=pcsl[0]||csl[1]!=pcsl[1]){
				draw(pcsl,"  ");
				draw(csl,"[]");
			}
			//gotoxy(1,my+1);
			//cout<<p->x[0]<<p->x[1];
			if(ifp)draw(plc,"()");
			pcsl[0]=csl[0];
			pcsl[1]=csl[1];
			if(kbhit())vm(getch());
	}
}
