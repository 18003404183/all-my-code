#include<bits/stdc++.h>
using namespace std;
int move(int n){
	
	if(n==1)return 1;
	return move(n-1)*2+1;
}
int main(){
	
	int n;
	cin>>n;
	cout<<move(n);
	
	return 0;
} 
