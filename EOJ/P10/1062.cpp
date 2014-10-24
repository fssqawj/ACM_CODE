#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct point {
	int x,y;
};
bool inter(point a,point b,point c,point d){
	if(min(a.x,b.x)>max(c.x,d.x)||min(a.y,b.y)>max(c.y,d.y)||min(c.x,d.x)>max(a.x,b.x)||min(c.y,d.y)>max(a.y,b.y))return false;
	int h,i,j,k;
	h=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	i=(b.x-a.x)*(d.y-a.y)-(b.y-a.y)*(d.x-a.x);
	j=(d.x-c.x)*(a.y-c.y)-(d.y-c.y)*(a.x-c.x);
	k=(d.x-c.x)*(b.y-c.y)-(d.y-c.y)*(b.x-c.x);
	//cout<<h<<" " <<i<<" "<<j<<" " <<k<<endl;
	return h*i<=0&&j*k<=0;
}
int main(){
	point a,b,c,d;
	while(scanf("%d%d%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y)!=EOF){
		if(inter(a,b,c,d))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
