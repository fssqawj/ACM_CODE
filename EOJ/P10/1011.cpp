#include<iostream>
using namespace std;
int main()
{
	int z,i,m,l,j,t=1;
	int a[10001]={0};
	int b[10001]={0};
	while(cin>>z>>i>>m>>l){
		if(z==0&&i==0&&m==0&&l==0)break;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[l]=1;
		b[l]=1;
		for(j=2;;j++){
			l=(z*l+i)%m;
			if(a[l]==1){
				j-=b[l];
				break;
			}
			a[l]=1;
			b[l]=j;
		}
		cout<<"Case "<<t++<<": "<<j<<endl;
	}
	return 0;
}
