#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{int f(string s);
int n;string  c1,c2,c3,c4,c;
cin>>n;
 
while(n--)
{cin>>c;
 
 c1=c.substr(0,8);
 c2=c.substr(8,8);
 c3=c.substr(16,8);
 c4=c.substr(24,8);
 cout<<f(c1)<<'.'<<f(c2)<<'.'<<f(c3)<<'.'<<f(c4)<<'\n';
}
return 0;
}
int f(string s)
{int sum=0,i;
for(i=0;i<8;i++)
	sum=sum+(s[i]-48)*pow(2.0,7-i);
return sum;
}
