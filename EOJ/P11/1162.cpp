#include<stdio.h>
#include<string.h>
int main()
{
	char map[11][11];
	char c;
	int i,j,tx,ty,jx,jy;
	int ft=3,fj=3;
	int t;
	scanf("%d",&t);
	while(t--){
		ft=fj=3;
		for(i=0;i<10;){
			for(j=0;j<10;){
				c=getchar();
				if(c=='.'){
					map[i][j]='.';
					j++;
				}
				else if(c=='*'){
					map[i][j]='*';
					j++;
				}
				else if(c=='C'){
					map[i][j]='C';
					tx=i;
					ty=j;
					j++;
				}
				else if(c=='M'){
					map[i][j]='M';
					jx=i;
					jy=j;
					j++;
				}
			}
			i++;
		}
		for(i=0;i<100000;i++){
			if(jx==tx&&jy==ty)break;
			if(ft==1){
				if(tx+1>=10){
					ft=2;
				}
				else if(map[tx+1][ty]=='*'){
					ft=2;
				}
				else tx++;
			}
			else if(ft==2){
				if(ty-1<0){
					ft=3;
				}
				else if(map[tx][ty-1]=='*'){
					ft=3;
				}
				else ty--;
			}
			else if(ft==3){
				if(tx-1<0){
					ft=4;
				}
				else if(map[tx-1][ty]=='*'){
					ft=4;
				}
				else tx--;
			}
			else if(ft==4){
				if(ty+1>=10){
					ft=1;
				}
				else if(map[tx][ty+1]=='*'){
					ft=1;
				}
				else ty++;
			}
		    if(fj==1){
				if(jx+1>=10){
					fj=2;
				}
				else if(map[jx+1][jy]=='*'){
					fj=2;
				}
				else jx++;
			}
			else if(fj==2){
				if(jy-1<0){
					fj=3;
				}
				else if(map[jx][jy-1]=='*'){
					fj=3;
				}
				else jy--;
			}
			else if(fj==3){
				if(jx-1<0){
					fj=4;
				}
				else if(map[jx-1][jy]=='*'){
					fj=4;
				}
				else jx--;
			}
			else if(fj==4){
				if(jy+1>=10){
					fj=1;
				}
				else if(map[jx][jy+1]=='*'){
					fj=1;
				}
				else jy++;
			}
		}
		printf("%d\n",i==100000?-1:i);
	}
	return 0;
}
