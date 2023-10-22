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
int plc[2];
bool inpl=0;
bool ifp=0;
bool sel=0;
bool emp=0;
void gotoxy(int x,int y){
	COORD pos;
	pos.X=x-1;
	pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
class matter{
public:
	double x[2];
	double px[2];
	double v[2];
	double r3;
	void force();
	void move(){
		x[0]+=v[0];
		x[1]+=v[1];
	}
};
list<matter> stars;
list<matter> planets;
iter p=stars.begin();
void matter::force(){
	
	for(iter A=stars.begin();A!=stars.end();++A){
		r3=pow(hypot(A->x[0]-x[0],A->x[1]-x[1]),3);
		if(r3==0)continue;
		v[0]+=G*(A->x[0]-x[0])/r3;
		v[1]+=G*(A->x[1]-x[1])/r3;
	}
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
	}else if(in==*"q"){
		if(p==stars.begin()){
			p=--planets.end();
			inpl=1;
		}else if(p==planets.begin()){
			p=--stars.end();
			inpl=0;
		}else{
			p--;
		}
	}else if(in==*"e"){
		if(p==--stars.end()){
			p=planets.begin();
			inpl=1;
		}else if(p==--planets.end()){
			p=stars.begin();
			inpl=0;
		}else{
			p++;
		}
	}else if(in==*"c"){
		 ifp=!ifp;
		 plc[0]=csl[0];
		 plc[1]=csl[1];
	}else if(in==*" "&&ifp){
		ifp=0;
		matter A;
		if(!sel){
			stars.push_back(A);
			
		}else{
			planets.push_back(A);
			
		}
		A.x[0]=plc[0]-p->x[0];
		A.x[1]=plc[1]-p->x[1];
		A.px[0]=A.x[0];
		A.px[1]=A.x[1];
		A.v[0]=csl[0]-plc[0];
		A.v[1]=csl[1]-plc[1];
		
	}else if(in==*"b"){
		if(!inp)stars.erase(--p);
		else if(inp)planets.erase(--p);
	}else if(in==*"r"){
		sel=!sel;
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
