#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long extgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	long long d=extgcd(b,a%b,x,y);
	long long t=x;x=y;y=t-a/b*y;
	return d;
}
int main(){
	long long e,i,d,x,y;
	long long a,b,c,n;
	long long ta,tb,tc,k;
	while(scanf("%lld%lld%lld%lld",&ta,&tb,&tc,&k)!=EOF){
		if(ta==0&&tb==0&&tc==0&&k==0)break;
		a=tc;
		n=1LL<<k;
		b=(tb>ta?tb-ta:tb-ta+n);
		d=extgcd(a,n,x,y);
		//cout<<"a = "<<a<<" b = "<<b<<" n = "<<n<<endl;
		if(b%d!=0)printf("FOREVER\n");
		else {
			e=(x*(b/d))%n;
			//cout<<"e = "<<e<<endl;
			//cout<<"x = "<<x<<" b = "<<b<<" d = "<<d<<endl;
			printf("%lld\n",(e+n)%(n/d));
		}
	}
	return 0;
}
