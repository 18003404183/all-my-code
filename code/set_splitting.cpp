#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,s=1;
	cin>>n>>k;
	for(int i=1;i<=k-1;i++){
		
		s*=n-1;
		n--;
	}
	cout<<s;
	return 0;
} 
