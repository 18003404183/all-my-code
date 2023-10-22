#include <bits/stdc++.h> 
using namespace std;
int main(){
	string a;
	srand(time(0));
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			a=rand()%2?"¨€":"  ";
			cout<<a;
		}	
	cout<<endl;
	}
	
}
