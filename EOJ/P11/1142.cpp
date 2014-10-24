#include<iostream>
#include<math.h>
using namespace std;
double map[105][105];
double x[105];
double y[105];
bool v[105];
int n;
double d[105];
double prime(){
	int i,j,k;
	double sum=0,min= 999999999;
	for(i=1;i<n;i++){
		d[i]=map[i][0];
	}
	for(i=1;i<n;i++){
		min=999999999;
		for(j=1;j<n;j++){
			if(!v[j]&&d[j]<min){
				min=d[j];
				k=j;
			}
		}
		v[k]=true;
		sum+=min;
		for(j=1;j<n;j++){
			if(d[j]>map[k][j]&&!v[j])d[j]=map[k][j];
		}
	}
	return sum;
}
int main()
{
	int i,j;
	while(cin>>n){
		memset(v,false,sizeof(v));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				map[i][j]=999999999;
			}
		}
		for(i=0;i<n;i++){
			cin>>x[i]>>y[i];
		}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				map[i][j]=map[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
		double temp=prime();
		printf("%.2lf\n",temp);
	}
	return 0;
}
