#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct data{
	int x,y,z;
};
bool cmp(data a,data b){
	return (a.x*a.y)<(b.x*b.y);
}
data d[100];
int h[100];
int main(){
	int n,i,j;
	int ca=1;
	while(scanf("%d",&n)&&n){
		memset(h,0,sizeof(h));
		for(i=0,j=0;i<n;i++){
			scanf("%d%d%d",&d[j].x,&d[j].y,&d[j].z);
			h[j]=d[j].z;
			//cout<<"j = "<<j<<" x = "<<d[j].x<<" y = "<<d[j].y<<" z = "<<d[j].z<<" h = "<<h[j]<<endl;
			j++;
			d[j].x=d[j-1].z;
			d[j].z=d[j-1].x;
			d[j].y=d[j-1].y;
			h[j]=d[j].z;
			//cout<<"j = "<<j<<" x = "<<d[j].x<<" y = "<<d[j].y<<" z = "<<d[j].z<<" h = "<<h[j]<<endl;
			j++;
			d[j].y=d[j-2].z;
			d[j].z=d[j-2].y;
			d[j].x=d[j-2].x;
			h[j]=d[j].z;
			//cout<<"j = "<<j<<" x = "<<d[j].x<<" y = "<<d[j].y<<" z = "<<d[j].z<<" h = "<<h[j]<<endl;
			j++;
		}
		sort(d,d+3*n,cmp);
		int ans=0;
		for(i=0;i<3*n;i++){
			int maxn = 0;
			for(j=0;j<3*n;j++){
				if((d[j].x<d[i].x&&d[j].y<d[i].y)||(d[j].y<d[i].x&&d[j].x<d[i].y)){
					if(h[j]>maxn){
						//cout<<"i = "<<i<<" j = "<<j<<endl;
						maxn=h[j];
					}
				}
			}
			h[i]=maxn+d[i].z;
			if(h[i]>ans){
				ans=h[i];
			}
		}
		printf("Case %d: maximum height = %d\n",ca++,ans);
	}
	return 0;
}
