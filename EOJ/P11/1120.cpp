#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct data{
	char s[8][8];
	int id;
};
struct point{
	int sx,sy,ex,ey;
};
point p[1000050];
int pre[1000050];
int ex,ey;
int id;
int ca = 1;
void pmath(int id){
	//printf("id = %d\n",id);
	if(id)pmath(pre[id]);
	if(id)printf("%d. (%d, %d) to (%d, %d)\n",ca ++,p[id].sy + 1,p[id].sx + 1,p[id].ey + 1,p[id].ex + 1);
}
bool judge(data a){
	int cnt = 0;
	int tx = -1,ty = -1;
	for(int i = 0;i < 7;i ++){
		for(int j = 0;j < 7;j ++){
			//printf("%c",a.s[i][j]);
			if(a.s[i][j] == 'o'){
				cnt ++;
				tx = i;
				ty = j;
			}
		}
		//printf("\n");
	}
	return cnt == 1 && tx == ex && ty == ey;
}
bool in(int x,int y){
	return x >= 0 && x < 7 && y >= 0 && y < 7;
}
int main(){
	int t;
	int cc = 1;
	scanf("%d",&t);
	getchar();
	while(t --){
		data tp;
		char c;
		for(int i = 0;i < 7;i ++){
			for(int j = 0;j < 7;j ++){
				//scanf("%c%c",&tp.s[i][j],&c);
				cin>>tp.s[i][j];
				//printf("%c%c",tp.s[i][j],c);
				if(tp.s[i][j] == 'O'){
					ex = i;ey = j;
					tp.s[i][j] = 'o';
				}
				else if(tp.s[i][j] == 'E'){
					ex = i;ey = j;
					tp.s[i][j] = 'e';
				}
			}
		}
		memset(pre,0,sizeof(pre));
		id = 0;
		ca = 1;
		tp.id = id++;
		queue<data>q;
		bool flag = false;
		q.push(tp);
		while(!q.empty()){
			tp = q.front();
			q.pop();
			if(judge(tp)){
				flag = true;
				break;
			}
			//printf("id = %d\n",tp.id);
			data pp = tp;
			for(int i = 0;i < 7;i ++){
				for(int j = 0;j < 7;j ++){
					if(tp.s[i][j] == 'o'){
						if(in(i - 2,j) && tp.s[i - 1][j] == 'o' && tp.s[i - 2][j] == 'e'){
							pp.s[i][j] = 'e';
							pp.s[i - 1][j] = 'e';
							pp.s[i - 2][j] = 'o';
							
							p[id].sx = i;
							p[id].sy = j;
							p[id].ex = i - 2;
							p[id].ey = j;
							pp.id = id;
							//printf("%d %d %d %d\n",p[id].sx,p[id].sy,p[id].ex,p[id].ey);
							q.push(pp);
							pre[id ++] = tp.id;
						}
						pp = tp;
						if(in(i,j + 2) && tp.s[i][j + 1] == 'o' && tp.s[i][j + 2] == 'e'){
							pp.s[i][j] = 'e';
							pp.s[i][j + 1] = 'e';
							pp.s[i][j + 2] = 'o';
							
							p[id].sx = i;
							p[id].sy = j;
							p[id].ex = i;
							p[id].ey = j + 2;
							pp.id = id;
							//printf("%d %d %d %d\n",p[id].sx,p[id].sy,p[id].ex,p[id].ey);
							q.push(pp);
							pre[id ++] = tp.id;
						}
						pp = tp;
						if(in(i + 2,j) && tp.s[i + 1][j] == 'o' && tp.s[i + 2][j] == 'e'){
							pp.s[i][j] = 'e';
							pp.s[i + 1][j] = 'e';
							pp.s[i + 2][j] = 'o';
							
							p[id].sx = i;
							p[id].sy = j;
							p[id].ex = i + 2;
							p[id].ey = j;
							pp.id = id;
							//printf("%d %d %d %d\n",p[id].sx,p[id].sy,p[id].ex,p[id].ey);
							q.push(pp);
							pre[id ++] = tp.id;
						}
						pp = tp;
						if(in(i,j - 2) && tp.s[i][j - 1] == 'o' && tp.s[i][j - 2] == 'e'){
							pp.s[i][j] = 'e';
							pp.s[i][j - 1] = 'e';
							pp.s[i][j - 2] = 'o';
							
							p[id].sx = i;
							p[id].sy = j;
							p[id].ex = i;
							p[id].ey = j - 2;
							pp.id = id;
							//printf("%d %d %d %d\n",p[id].sx,p[id].sy,p[id].ex,p[id].ey);
							q.push(pp);
							pre[id ++] = tp.id;
						}
					}
				}
			}
		}
		printf("Dataset %d:\n",cc ++);
		if(flag)pmath(tp.id);
		else printf("No solution.\n");
		if(t)printf("\n");
	}
	return 0;
}
