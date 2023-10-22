#include<bits/stdc++.h>
using namespace std;
int order=1;
int pos[8][2]={-1};
int solution[8][8]={0};
bool b=0;
void print(){
	for(int i=0;i<8;i++)solution[pos[i][0]][pos[i][1]]=1;
	cout<<"No. "<<order<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<solution[j][i]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<8;i++)solution[pos[i][0]][pos[i][1]]=0;
}
int search(int n){
	if(n==8){
		print();
		order++;
		//pos[7][0]=-1;
		//pos[7][1]=;
		
		system("pause");
		return 0;
	}
	for(int j=0;j<8;j++){
		for(int i=0;i<8;i++){
			b=0;
			for(int k=0;k<n;k++){
				if(i+j==pos[k][0]+pos[k][1]||abs(i-j)==abs(pos[k][0]-pos[k][1])||i==pos[k][0]||j==pos[k][1]){
					b=1;
				}
			}
			if(b==0){
				pos[n][0]=i;
				pos[n][1]=j;
				
				//print();//
				//system("pause");//
				search(n+1);
			}
			b=0;
			
		}
	}
	return 0;
	//pos[n][0]=0;
	//pos[n][1]=0;
}
int main(){
	search(0);
	return 0;
} 
