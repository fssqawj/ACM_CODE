#include<iostream>
using namespace std;
int main(){
  int t;
  int sum=0;
  int n;
  cin>>t;
  while(t--){
	   sum=0;
       scanf("%d",&n);
       for(int i=0;i<n;i++){
		   int tt;
		   scanf("%d",&tt);
		   sum+=tt;
       }
       cout<<sum-n+1<<endl;
  }
return 0;
}
