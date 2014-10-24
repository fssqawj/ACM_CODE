#include<iostream>
#include<stdio.h>
struct point{
	int x,y;
};
using namespace std;
int main(){
	int n;
	point p[700];
	int i,j,k;
	while(scanf("%d",&n)&&n){
		for(i=0;i<n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		int ans=0;
		int temp=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				temp=2;
				for(k=j+1;k<n;k++){
					if((p[j].y-p[i].y)*(p[k].x-p[j].x)==(p[k].y-p[j].y)*(p[j].x-p[i].x)){
						temp++;
					}
				}
				if(ans<temp){
					ans=temp;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
