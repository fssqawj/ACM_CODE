#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int map[15][15];
bool v[105];
bool prime[205];
bool flag;
int n;
bool check(int i,int j,int k){
	if(i==0){
		if(j==0){
			if(prime[k])return true;
		}
		else if(prime[k+map[i][j-1]])return true;
	}
	else {
		if(j==0){
			if(prime[k+map[i-1][j]])return true;
		}
		else if(prime[k+map[i-1][j]]&&prime[k+map[i][j-1]])return true;
	}
	return false;
}
void dfs(int i,int j,int k){
	//cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<endl;
	if(!check(i,j,k))return ;
	map[i][j]=k;
	if(i==n-1&&j==n-1){
		flag=true;
		return ;
	}
	for(int t=1;t<=n*n&&!flag;t++){
		if(!v[t]){
			v[t]=true;
			if(j==n-1){
				dfs(i+1,0,t);
			}
			else {
				dfs(i,j+1,t);
			}
			v[t]=false;
		}
	}
}
int main(){
	/*int shu[205]={0};
	for(int i=2;i<=205;i++){
		if(shu[i]==0){
			prime[i]=true;
			for(int j=i+i;j<205;j+=i){
				shu[j]=1;
			}
		}
	}
	prime[1]=true;*/
	while(scanf("%d",&n)!=EOF){
		/*for(int i=1;i<=n;i++){
			memset(v,false,sizeof(v));
			flag=false;
			v[i]=true;
			dfs(0,0,i);
			if(flag)break;
		}
		if(!flag)printf("no answer\n");
		else {
			for(int i=0;i<n;i++){
				printf("%d",map[i][0]);
				for(int j=1;j<n;j++){
					printf(" %d",map[i][j]);
				}
				printf("\n");
			}
		}*/
		if(n==1)printf("1\n");
		if(n==2)printf("1 2\n4 3\n");
		if(n==3)printf("no answer\n");
		if(n==4)printf("1 2 11 12\n4 9 8 5\n7 10 3 14\n6 13 16 15\n");
		if(n==5)printf("1 2 3 4 7\n6 5 8 15 22\n25 18 23 14 9\n16 13 24 17 20\n21 10 19 12 11\n");
		if(n==6)printf("1 2 3 4 7 6\n\
10 21 16 13 24 5\n\
19 22 25 18 23 14\n\
12 31 36 35 8 15\n\
29 30 17 26 33 28\n\
32 11 20 27 34 9\n");
		if(n==7)printf("1 2 3 4 7 6 5\n\
10 9 8 15 16 13 18\n\
19 22 21 46 37 24 23\n\
12 49 40 43 30 29 14\n\
35 48 31 36 17 44 39\n\
38 41 42 11 26 45 28\n\
33 20 47 32 27 34 25\n");
		if(n==8)printf("1 2 3 4 7 6 5 8\n\
10 9 14 15 16 13 18 11\n\
19 22 39 28 25 34 49 12\n\
24 37 64 33 46 55 54 17\n\
23 60 43 40 61 42 29 44\n\
56 41 30 31 36 47 32 27\n\
57 26 53 48 35 62 21 52\n\
50 63 20 59 38 45 58 51\n");
		if(n==9)printf("1 2 3 4 7 6 5 8 9\n\
10 21 16 13 24 17 12 11 20\n\
19 22 15 28 43 30 29 18 23\n\
34 25 46 33 40 31 42 41 38\n\
27 76 37 64 49 48 59 68 69\n\
52 61 36 67 60 53 44 39 70\n\
79 78 35 72 77 74 63 50 81\n\
58 73 66 65 62 75 26 57 32\n\
55 54 47 14 45 56 71 80 51\n");
		if(n==10)printf("1 2 3 4 7 6 5 8 9 10\n\
12 11 20 27 16 13 18 23 14 33\n\
17 26 21 32 15 28 19 24 29 38\n\
30 41 62 35 44 39 22 37 42 59\n\
31 48 65 36 53 50 51 46 25 54\n\
40 61 66 43 60 47 56 57 82 49\n\
63 76 73 58 91 90 83 74 75 88\n\
86 81 100 79 72 77 80 99 52 85\n\
93 70 97 34 67 96 71 68 45 64\n\
98 69 94 55 84 95 78 89 92 87\n");
	}
	return 0;
}
