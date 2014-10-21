#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int l,n,i,j,m=0,a[100005];
	cin>>n>>l;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=0,j=n-1;i<=j;){
		if(a[i]+a[j]<=l){m++;i++;j--;}
		else {m++;j--;}
	}
	cout<<m<<endl;
	return 0;
}
