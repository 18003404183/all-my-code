#include<bits/stdc++.h>
using namespace std;

int m;//mÎª×Ü²ãÊı 
char c[3];
int mid;
void move(int n,int s,int e,int mid){
	if(n==1){
		cout<<c[s-1]<<"->"<<1<<"->"<<c[e-1]<<endl;
		return;
	}
	move(n-1,s,mid,6-(s+mid));
	cout<<c[s-1]<<"->"<<n<<"->"<<c[e-1]<<endl;
	move(n-1,mid,e,6-(mid+e));
	return;
}
int main(){
	cin>>m>>c[0]>>c[1]>>c[2];
	move(m,1,2,3);
	return 0;
} 
