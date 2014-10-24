#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
const int maxn = 1000;
struct sub_t{
	int l,r;
	int maxx;
	int minn;
};
struct tree{
	int l,r;
	//int maxx;
	sub_t s_t[maxn];
};
tree t[maxn];
int a[maxn][maxn];
int n;
int ans[255][255];
inline int INP(){
	int x = 0;
	char c;
	while((c = getchar()) != ' ' && c != '\n'){
		x = x * 10 + c - '0';
	}
	return x;
}
void build_subtree(int rt,int sb_rt,int l,int r,int id){
	//printf("rt = %d sb_rt = %d l = %d r = %d\n",rt,sb_rt,l,r);
	t[rt].s_t[sb_rt].l = l;
	t[rt].s_t[sb_rt].r = r;
	if(l == r){
		if(id != -1){
			//printf("rt = %d sb_rt = %d id = %d l = %d\n",rt,sb_rt,id,l);
			t[rt].s_t[sb_rt].maxx = a[id][l];
			t[rt].s_t[sb_rt].minn = a[id][l];
			//printf("rt = %d sb_rt = %d mx = %d mi = %d\n",rt,sb_rt,t[rt].s_t[sb_rt].maxx,t[rt].s_t[sb_rt].minn);
		}
		//else {
		//	t[rt].s_t[sb_rt].maxx = max(t[rt<<1].s_t[sb_rt].maxx,t[rt<<1|1].s_t[sb_rt].maxx);
		//	t[rt].s_t[sb_rt].minn = min(t[rt<<1].s_t[sb_rt].minn,t[rt<<1|1].s_t[sb_rt].minn);
		//}
		return ;
	}
	int mid = (l + r)>>1;
	build_subtree(rt,sb_rt<<1,l,mid,id);
	build_subtree(rt,sb_rt<<1|1,mid + 1,r,id);
	//printf("id = %d\n",id);
	if(id != -1){
		//printf("rt = %d sb_rt = %d sb_rt<<1 = %d sb_rt<<1|1 = %d\n",rt,sb_rt,sb_rt<<1,sb_rt<<1|1);
		//printf("lx = %d rx = %d\n",t[rt].s_t[sb_rt<<1].maxx,t[rt].s_t[sb_rt<<1|1].maxx);
		t[rt].s_t[sb_rt].maxx = max(t[rt].s_t[sb_rt<<1].maxx,t[rt].s_t[sb_rt<<1|1].maxx);
		t[rt].s_t[sb_rt].minn = min(t[rt].s_t[sb_rt<<1].minn,t[rt].s_t[sb_rt<<1|1].minn);
		//printf("rt = %d sb_rt = %d id = %d l = %d r = %d maxx = %d minn = %d\n",rt,sb_rt,id,t[rt].s_t[sb_rt].l,t[rt].s_t[sb_rt].r,t[rt].s_t[sb_rt].maxx,t[rt].s_t[sb_rt].minn);
	}
	//else {
	//	printf("rt = %d sb_rt = %d\n",rt,sb_rt);
	//	printf("lx = %d rx = %d\n",t[rt<<1].s_t[sb_rt].maxx,t[rt<<1|1].s_t[sb_rt].maxx);
	//	t[rt].s_t[sb_rt].maxx = max(t[rt<<1].s_t[sb_rt].maxx,t[rt<<1|1].s_t[sb_rt].maxx);
	//	t[rt].s_t[sb_rt].minn = min(t[rt<<1].s_t[sb_rt].minn,t[rt<<1|1].s_t[sb_rt].minn);
	//}
}
void push_up(int rt,int sb_rt,int l,int r){
	if(l == r){
		t[rt].s_t[sb_rt].maxx = max(t[rt<<1].s_t[sb_rt].maxx,t[rt<<1|1].s_t[sb_rt].maxx);
		t[rt].s_t[sb_rt].minn = min(t[rt<<1].s_t[sb_rt].minn,t[rt<<1|1].s_t[sb_rt].minn);
		return ;
	}
	int mid = (l + r)>>1;
	push_up(rt,sb_rt<<1,l,mid);
	push_up(rt,sb_rt<<1|1,mid + 1,r);
	//printf("push rt = %d sb_rt = %d\n",rt,sb_rt);
	t[rt].s_t[sb_rt].maxx = max(t[rt<<1].s_t[sb_rt].maxx,t[rt<<1|1].s_t[sb_rt].maxx);
	t[rt].s_t[sb_rt].minn = min(t[rt<<1].s_t[sb_rt].minn,t[rt<<1|1].s_t[sb_rt].minn);
	//printf("rt = %d sb_rt = %d l = %d r = %d d = %d u = %d maxx = %d minn = %d\n",rt,sb_rt,t[rt].l,t[rt].r,t[rt].s_t[sb_rt].l,t[rt].s_t[sb_rt].r,t[rt].s_t[sb_rt].maxx,t[rt].s_t[sb_rt].minn);
}
void build(int rt,int l,int r){
	t[rt].l = l;
	t[rt].r = r;
	if(l == r){
		build_subtree(rt,1,1,n,l);
		return ;
	}
	else build_subtree(rt,1,1,n,-1);
	int mid = (l + r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid + 1,r);
	push_up(rt,1,1,n);
	//t[rt].l = 
	//t[rt].maxx = max(t[rt<<1].maxx,t[rt<<1|1].maxx);
}
int query_subtree(int rt,int sb_rt,int l,int r,bool can){
	//printf("sub rt = %d sb_rt = %d sl = %d l = %d sr = %d r = %d\n",rt,sb_rt,t[rt].s_t[sb_rt].l,l,t[rt].s_t[sb_rt].r,r);
	if(t[rt].s_t[sb_rt].l >= l && t[rt].s_t[sb_rt].r <= r){
		//printf("ma = %d mi = %d\n",t[rt].s_t[sb_rt].maxx,t[rt].s_t[sb_rt].minn);
		if(can)return t[rt].s_t[sb_rt].maxx;
		return t[rt].s_t[sb_rt].minn;
	}
	int mid = (t[rt].s_t[sb_rt].l + t[rt].s_t[sb_rt].r)>>1;
	if(l > mid)return query_subtree(rt,sb_rt<<1|1,l,r,can);
	else if(r <= mid)return query_subtree(rt,sb_rt<<1,l,r,can);
	else {
		if(can)return max(query_subtree(rt,sb_rt<<1,l,mid,can),query_subtree(rt,sb_rt<<1|1,mid + 1,r,can));
		return min(query_subtree(rt,sb_rt<<1,l,mid,can),query_subtree(rt,sb_rt<<1|1,mid + 1,r,can));
	}
}
int query(int rt,int l,int r,int d,int u,bool can){
	//printf("rt = %d tl = %d l = %d tr = %d r = %d d = %d u = %d\n",rt,t[rt].l,l,t[rt].r,r,d,u);
	if(t[rt].l >= l && t[rt].r <= r){
		return query_subtree(rt,1,d,u,can);
	}
	int mid = (t[rt].l + t[rt].r)>>1;
	if(l > mid)return query(rt<<1|1,l,r,d,u,can);
	else if(r <= mid)return query(rt<<1,l,r,d,u,can);
	else {
		if(can)return max(query(rt<<1,l,mid,d,u,can),query(rt<<1|1,mid + 1,r,d,u,can));
		return min(query(rt<<1,l,mid,d,u,can),query(rt<<1|1,mid + 1,r,d,u,can));
	}
}
int main(){
	int b,m;
	while(scanf("%d%d%d",&n,&b,&m) != EOF){
 
		memset(ans,-1,sizeof(ans));
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				scanf("%d",&a[i][j]);
			}
		}
		getchar();
		build(1,1,n);
		for(int i = 0;i < m;i ++){
			int x = INP(),y = INP();
			//scanf("%d%d",&x,&y);
			if(ans[x][y] != -1){
				printf("%d\n",ans[x][y]);
				continue;
			}
			int maxx = query(1,x,x + b - 1,y,y + b - 1,1);
			int minn = query(1,x,x + b - 1,y,y + b - 1,0);
			//printf("maxx = %d minn = %d\n",maxx,minn);
			printf("%d\n",maxx - minn);
			ans[x][y] = maxx - minn;
		}
		//break;
	}
	return 0;
}
