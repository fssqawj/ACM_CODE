#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c,d,s;
    while(cin>>a>>b>>c>>d&&a+b+c+d)
    {
        s=720;
        s+=(a-b+40)%40*360/40;
        s+=360;
        s+=(c-b+40)%40*360/40;
        s+=(c-d+40)%40*360/40;
        cout<<s<<endl;
    }
	return 0;
}
