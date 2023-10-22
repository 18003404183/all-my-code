#include<bits/stdc++.h>
using namespace std;
int prime[12]={2,3,5,7,11,13,17,19,23,29,31,37};
bool b[21]={0};
int solution[20];
int ifp(int a){
	for(int i=0;i<12;i++){
		if(a==prime[i])return 1;
	}
	return 0;
}
void print(){
	for(int i=0;i<20;i++){
		cout<<solution[i]<<" ";
	}
	cout<<endl;
}
int search(int n){
	//print();//
	if(n==20){
		if(ifp(solution[19]+1))print();
		b[solution[19]]=0;
		return 0;
	}
	for(int i=1;i<21;i++){
		if((!b[i])&&ifp(solution[n-1]+i)){
			solution[n]=i;
			b[i]=1;
			search(n+1);
			
		}
	}
	b[solution[n-1]]=0;
	return 0;
}
int main(){
	solution[0]=1;
	b[1]=1;
	search(1);
	return 0;
}
