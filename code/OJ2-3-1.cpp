#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a,fa[n];
	long long int f[3];
	for(int i=1;i<=n;i++){
		cin>>a;
		f[0]=f[1]=1;
		if(a==1||a==2){fa[i-1]=1;continue;}
		for(int j=1;j<=a-2;j++){
			f[2]=f[0]+f[1];
			f[2]%=1000;
			f[0]=f[1];f[1]=f[2];
		}
    	fa[i-1]=f[2];
	}
	for(int i=1;i<=n;i++){
		cout<<fa[i-1]<<endl;
	}
	
}
