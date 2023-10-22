#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n][n],b[n][n];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		b[n-1][i-1]=a[n-1][i-1];
	}
	//下面需改正 
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			b[i-1][j-1]=b[i][j-1]>b[i][j] ? a[i-1][j-1]+b[i][j-1] : a[i-1][j-1]+b[i][j];
			
		}
	}
	//cout<<b[0][0];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<b[i-1][j-1]<<' ';
			
		}
		cout<<endl;
	}
	
	//
	return 0;
} 
