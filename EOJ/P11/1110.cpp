#include<iostream>
using namespace std;
int main()
{
	int map[202][202];
	int i,j,k;
	int u,v,l;
	int t;
	int n,m;
	int a,b;
	while(cin>>n>>m){
		memset(map,-1,sizeof(map));
		for(i=0;i<m;i++){
			cin>>u>>v>>l;
			if(map[u][v]<l)
			map[u][v]=l;
		}
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(i!=j&&j!=k&&i!=k)
					if(map[i][j]<map[i][k]+map[k][j]&&map[i][k]>=0&&map[k][j]>=0)map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
		cin>>t;
		while(t--){
		cin>>a>>b;
		cout<<map[a][b]<<endl;
		}
	}
	return 0;
}
