#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
long long m,q;
const long long aa[3]={2,7,61};
long long f(long long a,long long b,long long c){
     long long t;
     if(b==0){
        t=1;
     }
     else if(b%2==0){
        t=f(a,b/2,c);
        t=t*t;
        t=t%c;
     }
     else {
        t=f(a,(b-1)/2,c);
        t=t*t;
        t=t%c;
        t*=a;
        t=t%c;
    }
    return t;
}
int main(){
	long long n;
	while(scanf("%I64d",&n)!=EOF){
		if(n==2||n==3){
			printf("YES\n");
			continue;
		}
		if(n==1||n%2==0){
			printf("NO\n");
			continue;
		}
		q=0;
		m=n-1;
		while(m%2==0){
			q++;
			m/=2;
		}
		//cout<<"q = "<<q<<" m = "<<m<<endl;
		bool flag1=false;
		bool flag2=false;
		bool flag3=true;
		for(int i=0;i<3;i++){
			flag1=false;
			flag2=false;
			int j=0;
			long long a=aa[i];
			long long x=f(a,m,n);
			if(x==1)flag1=true;
			if(x==n-1)flag2=true;
			//cout<<"a = "<<a<<" m = "<<m<<" n = "<<n<<" flag1 = "<<(flag1?1:0)<<endl;
			for(j=0;j<q&&x!=n-1;j++){
				x=(x*x)%n;
				if(x==n-1){
					flag2=true;
					break;
				}
			}
			if(flag1||flag2)flag3=true;
			else {
				flag3=false;
				break;
			}
		}
		if(flag3)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
