#include<iostream>
#include<stdio.h>
using namespace std;
int extgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int d=extgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
}
int a[1005],b[1005];
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int x,y,ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		int m=1;
		for(i=0;i<n;i++){
			m*=a[i];
		}
		for(i=0;i<n;i++){
			int tm=m/a[i];
			int d=extgcd(tm,a[i],x,y);
			//cout<<"tm = "<<tm<<" x = "<<x<<endl;
			ans=(ans+x*tm*b[i])%m;
			//cout<<"ans = "<<ans<<endl;
		}
		if(ans>0)printf("%d\n",ans);
		else printf("%d\n",ans+m);
	}
	return 0;
}
