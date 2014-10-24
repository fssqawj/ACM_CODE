#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct data{
       int num[15][15];
};
data a;
data ans;
int n,m;
data mul(data a,data b){
     data temp;
     memset(temp.num,0,sizeof(temp.num));
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             for(int k=0;k<n;k++){
                 temp.num[i][j]+=((a.num[i][k]*b.num[k][j])%9973);
                 temp.num[i][j]%=9973;
             }
         }
     }
     return temp;
}
 
int main()
{
    int t;
    int i,j,k;
    cin>>t;
    while(t--){
         cin>>n>>m;
         for(i=0;i<n;i++){
             for(j=0;j<n;j++){
                 cin>>a.num[i][j];       
             }
         }
         memset(ans.num,0,sizeof(ans.num));
         for(i=0;i<n;i++){
             ans.num[i][i]=1;
         }
         while(m){
             if(m%2==1){
                ans=mul(a,ans);
             }
             a=mul(a,a);
             m=m>>1;
         }
             int res=0;
             for(i=0;i<n;i++){
                 res+=ans.num[i][i];
             }
             cout<<res%9973<<endl;
   }
   return 0;
}
