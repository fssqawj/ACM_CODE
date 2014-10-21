//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n,i;
//	double sum=0;
//	while(scanf("%d",&n)){
//		if(n==0)printf("0\n");
//		else {
//		for(i=1;i<=n;i++)
//			sum+=log((double)i)/log(10.0);
//	sum-=(int)sum;
//	printf("%d\n",(int)exp(sum*log(10.0)));
//	sum=0;
//		}
//}
//return 0;
//}
 
 
#include<iostream>
#include<math.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;
const int m[9] = {1,1,2,6,2,1,7,5,4};
int main(void)
{
    int n;
    double k;
    while(cin >> n)
    {
        if(n<=8)
        {
            cout << m[n] << endl;
            continue;
        }
        k = log10(2*PI*n)/2 + n*log10(n/E);
        cout << int(pow(10, k-int(k))) << endl;
    }
    return 0;
}
