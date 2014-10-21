#include<iostream>
using namespace std;
int w[55][3];
int c[55][3];
int n,m;
int w1=999999,tw,tc;
void dfs(int i){
	int j;
	if(i>=n){
		w1=tw;
		return;
	}
	for(j=0;j<3;j++){
		tw+=w[i][j];
		tc+=c[i][j];
		if(tc<m&&tw<w1)dfs(i+1);
		tw-=w[i][j];
		tc-=c[i][j];
	}
}
int main()
{
	int i,j;
	while(cin>>n>>m){
		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				cin>>w[i][j]>>c[i][j];
			}
		}
		w1=999999;
		tc=tw=0;
		dfs(0);
		cout<<w1<<endl;
	}
	return 0;
}
