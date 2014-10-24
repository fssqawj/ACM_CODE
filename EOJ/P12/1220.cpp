#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 200005;
struct data{
	int l,r,maxx;
};
data tree[MAX<<2];
int h[MAX];
void build(int l,int r,int root){
	tree[root].l=l;
	tree[root].r=r;
	if(l==r){
		tree[root].maxx=h[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	tree[root].maxx=max(tree[root<<1].maxx,tree[root<<1|1].maxx);
}
void update(int id,int v,int root){
	if(tree[root].l==id&&tree[root].r==id){
		tree[root].maxx=v;
		return ;
	}
	int mid=(tree[root].l+tree[root].r)>>1;
	if(id<=mid)update(id,v,root<<1);
	else update(id,v,root<<1|1);
	tree[root].maxx=max(tree[root<<1].maxx,tree[root<<1|1].maxx);
}
int getmax(int l,int r,int root){
	if(tree[root].l==l&&tree[root].r==r){
		return tree[root].maxx;
	}
	int mid=(tree[root].l+tree[root].r)>>1;
	if(r<=mid)return getmax(l,r,root<<1);
	else if(l>mid)return getmax(l,r,root<<1|1);
	else return max(getmax(l,mid,root<<1),getmax(mid+1,r,root<<1|1));
}
int main()
{
	int n,m;
	int a,b,i;
	char s[3];
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%d",&h[i]);
		}
		build(1,n,1);
		for(i=0;i<m;i++){
			scanf("%s",s);
			if(s[0]=='Q'){
				scanf("%d%d",&a,&b);
				int temp=getmax(a,b,1);
				printf("%d\n",temp);
			}
			else {
				scanf("%d%d",&a,&b);
				update(a,b,1);
			}
		}
	}
	return 0;
}
