#include<bits/stdc++.h>
using namespace std;
int f(int n){
	if(n==1||n==2)return 1;
	return f(n-1)+f(n-2);
}
int main(){
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
} 
