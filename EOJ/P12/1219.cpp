#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<=100;i++){
			if(i*(i+1)/2>=n)break;
		}
		int tt=i*(i+1)/2;
		//cout<<"i = "<<i<<" tt = "<<tt<<endl;
		if(i%2==1)printf("%d\n",n);
		else printf("%d\n",2*tt-i-n+1);
	}
	return 0;
}
