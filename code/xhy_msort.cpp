#include<bits/stdc++.h>
using namespace std;
#define fp(a) for(int i=1;i<=len;i++){cout<<a[i-1]<<' ';}cout<<endl;
#define p(s) cout<<s<<endl;
int* msort(int *a,int len){
	int b_array[len];
	int *b=b_array,e,pl,pr,pb;
	for(int i=1;i<len;i*=2){
		for(int j=1;j<=len;j+=i*2){
			e=j+i*2-1<=len?j+i*2-1:len;
			pl=j;pr=j+i;pb=j;
			while(pl<=j+i-1&&pr<=e){
				//fp(b)//
				if(a[pl-1]>=a[pr-1])b[pb-1]=a[pr-1];pb++;pr++;
				if(a[pl-1]<a[pr-1])b[pb-1]=a[pl-1];pb++;pl++;
				//fp(b)//
				//p("-")
			}
		}
		//fp(a)//
		swap(a,b);
		//fp(b)//
		p("----------")//
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	int a_array[n];
	int *a=a_array;
	for(int i=1;i<=n;i++){
		cin>>a[i-1];
	}
	a=msort(a,n);
	for(int i=1;i<=n;i++){
		cout<<a[i-1]<<' ';
	}
}

