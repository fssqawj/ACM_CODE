#include<iostream>
using namespace std;
long long f(int i){
	long long sum=1;
	for(int j=1;j<=i;j++){
		sum*=j;
	}
	return sum;
}
int main()
{
	long long sum;
	long long a[21];
	long long c,ans;
	int i;
	int n,m,r,t;
	a[0]=0;
	a[1]=0;
	a[2]=1;
	for(i=3;i<21;i++)a[i]=(i-1)*(a[i-1]+a[i-2]);
	cin>>t;
	while(t--){
		cin>>n>>m;
		r=n-m;
		c=f(n)/(f(r)*f(n-r));
		ans=c*a[m];
		cout<<ans<<endl;
	}
	return 0;
}
