#include<conio.h>
#include<iostream>
#include<windows.h>
#include<math.h>
#include<string>
using namespace std;
int pcsl[2]={1,1};
int csl[2]={1,1};
int xl=80;
int yl=40;
string rule[2]={"3","23"};
int cell[200][100];
int chg[200][100];
bool pause=1;
BOOL SetConsoleColor(WORD wAttributes)  
{  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    if (hConsole == INVALID_HANDLE_VALUE)  
        return FALSE;  
  
    return SetConsoleTextAttribute(hConsole, wAttributes);  
}
void gotoxy(int x,int y){
	COORD pos;
	pos.X=x-1;
	pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
inline void reset2(){
	for(int j=1;j<=yl;j++){
		for(int i=1;i<=xl;i++){
			cell[i][j]=0;
			chg[i][j]=0;
		}
	}
	//cell[10][9]=1;
	//cell[10][10]=1;
	//cell[10][11]=1;
}
void draw(int pos0,int pos1,string s,bool bg){
	gotoxy(pos0*2,pos1+1);
	if(bg)SetConsoleColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout<<s;
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
inline void draw(int pos[2],string s,bool bg){
	draw(pos[0],pos[1],s,bg);
}

void update(){
	for(int j=1;j<=yl;j++){
		for(int i=1;i<=xl;i++){
			int around=cell[i-1][j-1]+cell[i-1][j]+cell[i-1][j+1]+cell[i][j-1]+cell[i][j+1]+cell[i+1][j-1]+cell[i+1][j]+cell[i+1][j+1];
			chg[i][j]=0;
			if(cell[i][j]==0){
				for(int rp=0;rp<rule[0].length();rp++){
					chg[i][j]+=(around==(int)(rule[0][rp]-48));
				}
			}else{
				for(int rp=0;rp<rule[1].length();rp++){
					chg[i][j]+=(around==(int)(rule[1][rp]-48));
				}
				chg[i][j]=!chg[i][j];
			}
		}
	}
	for(int j=1;j<=yl;j++){
		for(int i=1;i<=xl;i++){
			cell[i][j]=(cell[i][j]+chg[i][j])%2;	
		}
	}
	for(int j=1;j<=yl;j++){
		for(int i=1;i<=xl;i++){
			if(chg[i][j])draw(i,j,"  ",cell[i][j]);
		}
	}
	draw(csl,"[]",cell[csl[0]][csl[1]]);
}
void redraw(){
	gotoxy(1,1);
	cout<<"B"<<rule[0]<<"/S"<<rule[1];
	gotoxy(1,yl+2);
	cout<<"开始(空格) | 放置/清除(p) | 更改规则(r) | 随机填充(shift+f) | 清屏(shift+c)";
	for(int j=1;j<=yl;j++){
		for(int i=1;i<=xl;i++){
			draw(i,j,"  ",cell[i][j]);
		}
	}
	draw(csl,"[]",cell[csl[0]][csl[1]]);
}
void vm(char in){
	if(in==*"w"&&csl[1]!=1){
		pcsl[1]=csl[1];
		csl[1]--;
	}else if(in==*"a"&&csl[0]!=1){
		pcsl[0]=csl[0];
		csl[0]--;
	}else if(in==*"s"&&csl[1]!=yl-1){
		pcsl[1]=csl[1];
		csl[1]++;
	}else if(in==*"d"&&csl[0]!=xl){
		pcsl[0]=csl[0];
		csl[0]++;
	}else if(in==*" "){
		pause=!pause;
		gotoxy(1,yl+2);
		if(pause){
			cout<<"继续";
		}else{
			cout<<"暂停";
		}
	}else if(in==*"p"){
		cell[csl[0]][csl[1]]=!cell[csl[0]][csl[1]];
		draw(csl,"[]",cell[csl[0]][csl[1]]);
	}else if(in==*"F"){
		for(int j=1;j<=yl;j++){
			for(int i=1;i<=xl;i++){
				cell[i][j]=(rand()%10<3)?1:0;
				chg[i][j]=0;
			}
		}
		redraw();
	}else if(in==*"r"){
		system("cls");
		cout<<"请输入新规则：\nB:\nS:"<<endl;
		cout<<"注意：使用“_”或“-”表示不填。\n如“B2/S-”表示B2规则。";
		gotoxy(4,2);
		cin>>rule[0];
		if(rule[0]=="-"||rule[0]=="_")rule[0]=="";
		gotoxy(4,3);
		cin>>rule[1];
		if(rule[1]=="-"||rule[1]=="_")rule[1]=="";
		system("cls");
		redraw();
	}else if(in==*"C"){
		reset2();
		redraw();
	}
}
void check(){
	for(int i=100;i>0;i--)cout<<i<<endl;
	//for(int i=0;i>10;i++)cout<<" ";
	for(char i=20;i<127;i++)cout<<i<<" ";
	gotoxy(1,90);
	cout<<"窗口校对：\n请确保您的输入法为英文状态。\n请输入最上边的数字和最右边的字符（区分大小写），用空格分开。\n输入完毕后，按回车以继续。";
	gotoxy(1,103);
	char c;
	cin>>yl>>c;
	xl=c-21;
	yl-=3;
	system("cls");
	gotoxy(1,1);
}
void inform(){
	cout<<"康威生命游戏模拟器 v2.0\n\n请将输入法调整至英文状态。\n如果允许，请将窗口调至全屏。\n\n调整完成后，按空格开始窗口校对。"<<endl;
	cout<<"\n帮助：按w,a,s,d移动光标，按键进行操作。"; 
	while(getch()!=*" "){}
}
int main(){
	
	inform();
	check();
	reset2();
	redraw();
	pause=1;
	while(1){
		for(int i=0;i<10000;i++){
			if(pcsl[0]!=csl[0]||pcsl[1]!=csl[1]){
				draw(pcsl,"  ",cell[pcsl[0]][pcsl[1]]);
				draw(csl,"[]",cell[csl[0]][csl[1]]);
				pcsl[0]=csl[0];
				pcsl[1]=csl[1];
			}
			if(kbhit()){
				vm(getch());
			}
		}
		if(!pause)update();
	}
	return 0;
} 
