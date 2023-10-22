#include<bits/stdc++.h>
using namespace std;
string s="";
const double l2=log(2);

string out(int n){
	if(pow(2,(int)(log(n)/l2))==n){
		if(n==0)return "0";
		if(n==2)return "2";
		return "2("+out(log(n)/l2)+")";
	}
	if(n>2&&n<4)return "2+"+out(n-pow(2,(int)(log(n)/l2)));
	return "2("+out(log(n)/l2)+")+"+out(n-pow(2,(int)(log(n)/l2)));
}
int main(){
	int n;
	cin>>n;
	cout<<out(n);
	return 0;
} 
