#include<iostream>
#include<stdio.h>
using namespace std;
const long long mod = 2005;
long long quick(long long a,long long n){
	long long ans = 1;
	//a = (a % mod + mod) % mod;
	while(n){
		if(n % 2 == 1){
			ans *= a;
			ans = (ans % mod + mod) % mod;
		}
		a *= a;
		a %= mod;
		n /= 2;
	}
	return ans;
}
/*long long getsum(long long p,long long n){
	//prlong longf("p = %d n = %d\n",p,n);
	if(n == 0)return 1;
	if(n & 1){
		return (((1 + quick(p,n / 2 + 1)) * getsum(p,n / 2)) % mod + mod) % mod;
	}
	else return ((((1 + quick(p,n / 2 + 1)) * getsum(p,n / 2 - 1)) + quick(p,n / 2)) % mod + mod) % mod;
}*/
long long getsum(long long p,long long n){
	if(n == 0)return 0;
	//p = (p % mod + p) % mod;
	if(n & 1)return (getsum(p,n - 1) + quick(p,n - 1)) % mod;
	p = p % mod;
	return ((p + 1) * getsum(p * p,n / 2)) % mod;
}
int main(){
	long long p,n;
	//prlong longf("%d\n",1<<31 - 1);
	while(scanf("%lld%lld",&p,&n) && !(p == 0 && n == 0)){
		long long ans;
		if(n & 1){
			ans = ((getsum(1 - p,n) - 1) % mod + mod) % mod;
		}
		else ans = ((((p - 1) % mod) * getsum(1 - p,n - 1)) % mod + mod) % mod;
		printf("%lld\n",ans);
	}
	return 0;
}
