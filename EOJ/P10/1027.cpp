#include <iostream>
using namespace std;
const int MAXN=101;
int n, m;
int v[MAXN], c[MAXN];
bool f[100001];
int coun[100001];
int main()
 {
	 int t;
	 cin>>t;
         while(t--){
			 scanf("%d", &n);
			 memset(f, 0, sizeof(f));
			 f[0] = 1;
			 for(int i = 1; i <= n; i++)
				 scanf("%d", v + i);
			 for(int i = 1; i <= n; i++)
				 scanf("%d", c + i);
			 m=0;
			 for(int i = 1; i <= n; i++){
				 m+=v[i]*c[i];
			 }
			 for(int i = 1; i <= n; i++)
			 {
				 memset(coun,0,sizeof(coun));
				 for(int j = v[i]; j <= m; j++)
					 if(f[j - v[i]] && !f[j] && coun[j - v[i]] < c[i])
					 {
						 coun[j] = coun[j - v[i]] + 1;
						 f[j] = 1;
					 }
			 }
			 int ans = 0;
			 for(int i = 0; i <= m; i++)
				 if(f[i]) ans++;
			 printf("%d\n", ans);
     }
     return 0;
 }
