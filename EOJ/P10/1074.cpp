#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
            unsigned long n;
            while( cin>>n&&n){
            double x=n*log10(n*1.0);
            x-=(__int64)x;
            int a=pow(10.0, x);
            cout<<a<<endl;
    }
    return 0;
}
