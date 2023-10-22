#include<bits/stdc++.h>
using namespace std;

int put(int m,int n){
	if(m==1)return n;
	return put(m-1,n);
}
int main(){
	int t;
	cin>>t;
	int m[t],n[t];
	for(int i=0;i<t;i++){
		cin>>m[i]>>n[i];
	}
	for(int i=0;i<t;i++){
		cout<<put(m[i],n[i]);
	}
	return 0;
} 
