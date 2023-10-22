#include<bits/stdc++.h>
using namespace std;
int spread(int c,int r){
	int map[c][r];
	int head[2][50]={{-1,-1}};
	
}
int main(){
	int c,r;
	int answer[50]={0};
	int order=0;
	while(1){
		cin>>c>>r;
		if(c==0&&r==0)break;
		answer[order]=spread(c,r);
		order++;
	}
	for(int i=0;i<order;i++)cout<<answer[i]<<endl;
	cout<<"\b";
	return 0;
} 
