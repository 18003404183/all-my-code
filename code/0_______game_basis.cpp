#include<conio.h>
#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
HANDLE hMutex = NULL;
int pcsl[2]={0,0};
int csl[2]={0,0};
int xl=40;
int yl=23;
void gotoxy(int x,int y){
	COORD pos;
	pos.X=x-1;
	pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void draw(int pos[2],string s){
		gotoxy((pos[0]+xl/2)*2,-pos[1]+yl/2);
		cout<<s;
}
void update(){
	
}
void redraw(){
	
}
void vm(char in){
	if(in==*"w"&&csl[1]!=yl/2-1){
		pcsl[1]=csl[1];
		csl[1]++;
	}else if(in==*"a"&&csl[0]!=-xl/2+1){
		pcsl[0]=csl[0];
		csl[0]--;
	}else if(in==*"s"&&csl[1]!=-yl/2-2){
		pcsl[1]=csl[1];
		csl[1]--;
	}else if(in==*"d"&&csl[0]!=xl/2-1){
		pcsl[0]=csl[0];
		csl[0]++;
	}
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
}
void inform(){
	
}
int main(){
	//check();
	while(1){
		if(pcsl[0]!=csl[0]||pcsl[1]!=csl[1]){
			draw(pcsl,"  ");
			draw(csl,"[]");
			pcsl[0]=csl[0];
			pcsl[1]=csl[1];
		}
		if(kbhit()){
			vm(getch());
		}
	}
	return 0;
} 
