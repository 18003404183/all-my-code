#include<bits/stdc++.h>
using namespace std;
int main(){
	int ue=0,ex=0;
	int a[3];
	srand((int)time(0));
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=2;j++)a[j]=0;
		srand(rand());
		a[rand()%3]=1;
		ue+=a[2];
		ex+=a[!(a[0]==0?0:1)];
		
	}
	cout<<ue<<endl<<ex;
}

