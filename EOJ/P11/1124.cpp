#include<iostream>
#include<stdio.h>
 
using namespace std;
 
int f(int a,int b,int c){
     int t;
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
 
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c&&!(a==0&&b==0&&c==0)){
         int t=f(a,b,c);
         cout<<t%c<<endl;
    }
    return 0;
}
