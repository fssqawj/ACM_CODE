#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{double a,r;
string u,v,out;
while(cin>>a>>u>>r)
{cin.get();
getline(cin,v);
if(a<0)break;
else {if(a/r<0.01)
      out=out+v+'\n';
      else cout <<v<<" "<< fixed << setprecision(1) <<a<< " "<<u
            <<" "<<setprecision(0) << a/r*100 <<"%"<<endl;
     }
}
cout<<"Provides no significant amount of:\n"<<out;
return 0;
}
