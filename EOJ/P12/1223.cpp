#include<iostream>
#include<stdio.h>
using namespace std;
int map[305][305];
bool v[305];
int d[305];
    int n,m;
int prime(){
	int i,j,k;
	int minn=1<<30;
	int ans=0;
	for(i=1;i<=n;i++){
		d[i]=map[i][1];
		v[i]=false;
	}
	v[1]=true;
	for(i=2;i<=n;i++){
		minn=1<<30;
		for(j=2;j<=n;j++){
			if(!v[j]&&d[j]<minn){
				minn=d[j];
				k=j;
			}
		}
		//cout<<"k = "<<k<<" 
		v[k]=true;
		ans+=d[k];
		for(j=2;j<=n;j++){
			if(!v[j]&&map[k][j]<d[j]){
				d[j]=map[k][j];
			}
		}
	}
	return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        int a,b;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            map[a][b]=map[b][a]=0;
        }
        printf("%d\n",prime());
    }
    return 0;
}
