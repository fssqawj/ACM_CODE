#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 105;
int x[maxn];
int main(){
	int n;
	while(scanf("%d",&n) && n){
		double a,b,c,d,e;
		for(int i = 0;i < n;i ++){
			scanf("%d",&x[i]);
		}
		sort(x,x + n);
		a = x[0];
		e = x[n - 1];
		if(n % 2)c = x[n / 2];
		else c = 0.5 * (x[n / 2 - 1] + x[n / 2]);
		int half = n / 2;
		if(half % 2){
			b = x[half / 2];
			d = x[(n - 1 + n - half) / 2];
		}
		else {
			b = 0.5 * (x[half / 2 - 1] + x[half / 2]);
			//printf("b = %.1lf\n",b);
			int len = n - 1 + n - half;
			d = 0.5 * (x[len / 2] + x[len / 2 + 1]);
		}
		if(n == 1)a = b = c = d = e = x[0];
		int f = 0;
		if(e - c > c - a || (e - c == c - a && d - c > c - b))f = 1;
		else if(e - c < c - a || (e - c == c - a && d - c < c - b))f = 2;
		string s;
		if(f == 0)s = "symmetric";
		else if(f == 1)s = "right-skewed";
		else s = "left-skewed";
		//printf("%.1lf %.1lf %.1lf %.1lf %.1lf ",a,b,c,d,e);
		if(a * 10 - int(a) * 10 != 0)printf("%.1lf",a);
		else printf("%.0lf",a);
		if(b * 10 - int(b) * 10 != 0)printf(" %.1lf",b);
		else printf(" %.0lf",b);
		if(c * 10 - int(c) * 10 != 0)printf(" %.1lf",c);
		else printf(" %.0lf",c);
		if(d * 10 - int(d) * 10 != 0)printf(" %.1lf",d);
		else printf(" %.0lf",d);
		if(e * 10 - int(e) * 10 != 0)printf(" %.1lf ",e);
		else printf(" %.0lf ",e);
		cout<<s<<endl;
	}
	return 0;
}
