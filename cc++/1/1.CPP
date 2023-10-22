#include<iostream>
#include<conio.h>
#include<windows.h>


using namespace std;
void gotoxy(int x,int y){
	COORD pos;
	pos.X=x-1;
	pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }
int map[8][8] = {0};



int draw(int x , int y ){

    gotoxy(x+1,y+1);
    cout << "[]";
    

}

int main(){

    while(true){
        if(kbhit()){
            switch (getch())
            {
            case 'a':
                

                break;
            case 'w':
                
                break;
            case 's':

                break;
            case 'd':

                break;
            }


        }
        

    }
    return 0;
}