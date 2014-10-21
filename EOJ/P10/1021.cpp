#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
using namespace std;
const int maxn = 105;
const double R = 4000;
const double Pi = acos(-1.0);
double dis[maxn][maxn];
string str[maxn];
double lon[maxn];
double lat[maxn];
double getdis(double MLonA,double MLatA,double MLonB,double MLatB){
	double C = sin(MLatA*Pi/180)*sin(MLatB*Pi/180)*cos((MLonA-MLonB)*Pi/180) + cos(MLatA*Pi/180)*cos(MLatB*Pi/180);
	return R*acos(C)*Pi/180;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t --){
		int n,m;
		map<string,int>mp;
		string f1,f2;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i ++){
			cin>>str[i]>>lat[i]>>f1>>lon[i]>>f2;
			mp[str[i]] = i;
			if(f1 == "N")lat[i] = 90 - lat[i];
			else lat[i] = 90 + lat[i];
			if(f2 == "W")lon[i] = -1.0 * lon[i];
		}
		string str1,str2;
		for(int i = 0;i < maxn;i ++){
			for(int j = 0;j < maxn;j ++){
				dis[i][j] = 1e11;
			}
		}
		for(int i = 0;i < m;i ++){
			cin>>str1>>str2;
			dis[mp[str1]][mp[str2]] = dis[mp[str2]][mp[str1]] = getdis(lon[mp[str1]],lat[mp[str1]],lon[mp[str2]],lat[mp[str2]]);
			//printf("i = %d j = %d dis = %.2lf\n",mp[str1],mp[str2],dis[mp[str1]][mp[str2]]);
		}
		for(int k = 1;k <= n;k ++){
			for(int i = 1;i <= n;i ++){
				for(int j = 1;j <= n;j ++){
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		int i1,i2;
		double maxx = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n;j ++){
				//printf("i = %d j = %d dis = %.2lf\n",i,j,dis[i][j]);
				if(dis[i][j] > maxx){
					i1 = i;i2 = j;
					maxx = dis[i][j];
				}
			}
		}
		if(str[i1] < str[i2])cout<<str[i1]<<" "<<str[i2]<<endl;
		else cout<<str[i2]<<" "<<str[i1]<<endl;
	}
	return 0;
}
