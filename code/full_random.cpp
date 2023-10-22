#include<bits/stdc++.h>
using namespace std;
void rnum();
void rsum();
void dsum();
int r(int s,int e);
int main(){
	int se;
	while(1){
		cout<<"给定范围取随机数，请按1；"<<endl<<"单范围多个数求和，请按2；"<<endl<<"不同范围多个数求和，请按3；"<<endl<<"退出请按0。"<<endl;
		cin>>se;
		if(se==1)rnum();
		if(se==2)rsum();
		if(se==3)dsum();
		if(se==0)return 0;
	}
}
int r(int s,int e){
	srand(rand()+(int)time(0));
	return rand()%(e-s+1)+s;
}
void rnum(){
	int s,e,s1;
	cout<<"给定范围取随机数："<<endl<<"输入格式：【最大值】【最小值】"<<endl<<"按上一组数据输入请输入0；"<<endl<<"退出请输入-1。"<<endl;
	while(1){
		cin>>s;
		if(s==-1){
			return;
		}
		if(s==0){
			s=s1;
			cout<<"->"<<r(s,e)<<endl;
		}else{
			cin>>e;
			cout<<"->"<<r(s,e)<<endl;
			s1=s;
		}
	}
}
void rsum(){
	int s,e,n,n1,a;
	cout<<"单范围多个随机数求和："<<endl<<"输入格式：【个数】【最大值】【最小值】"<<endl<<"按上一组数据输入请输入0；"<<endl<<"退出请输入-1。"<<endl;
	while(1){
		a=0;
		cin>>n;
		if(n==-1){
			return;
		}
		if(n==0){
			for(int i=0;i<n1;i++)a+=r(s,e);
			cout<<"->"<<a<<endl;
		}else{
			cin>>s>>e;
			for(int i=0;i<n;i++)a+=r(s,e);
			cout<<"->"<<a<<endl;
			n1=n;
		}
	}
}
void dsum(){
	int n,n1,a,s[50],e[50];
	cout<<"不同范围多个数求和："<<endl<<"输入格式：【组数】"<<endl<<"【最大值】【最小值】"<<endl<<"【最大值】【最小值】"<<endl<<"......"<<endl<<"按上一组数据输入请输入0；"<<endl<<"退出请输入-1。"<<endl;
	while(1){
		a=0;
		cin>>n;
		if(n==-1){
			return;
		}
			
		if(n!=0){
			
			for(int i=0;i<n;i++){
				cout<<i+1<<"|";
				cin>>s[i]>>e[i];
				a+=r(s[i],e[i]);
			}
			cout<<"->"<<a<<endl;
			n1=n;
		}else{
		//断点 
			for(int i=0;i<n1;i++){
				a+=r(s[i],e[i]);
			}
			cout<<"->"<<a<<endl;
		}
	}
}
