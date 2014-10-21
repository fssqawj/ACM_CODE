#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;
const int MAX = 0x3f3f3f3f;
int main()
{
     map<string,int>m;
     int a[105][105];
     int n,mm,kk;
     int c=0;
     string s1,s2;
     int v;
     cin>>n>>mm;
     memset(a,0x3f,sizeof(a));
     for(int i=0;i<mm;i++){
         cin>>s1>>s2>>v;
         if(m.find(s1)==m.end())m[s1]=c++;
         if(m.find(s2)==m.end())m[s2]=c++;
         a[m[s1]][m[s2]]=a[m[s2]][m[s1]]=v;
     }
     for(int k=0;k<n;k++){
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(a[i][k]+a[k][j]<a[i][j])a[i][j]=a[i][k]+a[k][j];
             }
         }
     }
     cin>>kk;
     for(int i=0;i<kk;i++){
         cin>>s1>>s2;
         if(m.find(s1)==m.end()||m.find(s2)==m.end()||a[m[s1]][m[s2]]==MAX)cout<<"-1"<<endl;
         else cout<<a[m[s1]][m[s2]]<<endl;
     }
     return 0;
}
