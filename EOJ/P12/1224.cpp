#include<stdio.h>
#include<queue>
#include<limits.h>
#define max 250
using namespace std;
struct node{int x,y;};
struct point{int c,step;};
point maze[max][max];
int direction[4][2]={-1,0,0,1,1,0,0,-1};
int main()
{
         int n,m,i,j,k,x,y;
         node start,end,a,b;
         queue<node> q;
         char c;
         bool flag;
         while(scanf("%d%d",&n,&m)!=EOF)
         {
               for(i=0;i<n;i++)
                    for(j=0,getchar();j<m;j++)
                    {
                               scanf("%c",&c);
                               if(c=='X')
                                         maze[i][j].c=2;
                               else
                                         if(c=='#')
                                                maze[i][j].c=0;
                                         else
                                         {
                                                 if(c=='S')
                                                 {
                                                        start.x=i;
                                                        start.y=j;
                                                 }
                                                 else
                                                 {
                                                         if(c=='T')
                                                         {
                                                              end.x=i;
                                                              end.y=j;
                                                         }
                                                  }
                                                  maze[i][j].c=1;
                                         }
                                 maze[i][j].step=INT_MAX;
                      }
           flag=false;
           maze[start.x][start.y].step=0;
           q.push(start);
           while(!q.empty())
           {
                  a=q.front();
                  q.pop();
                  if(a.x==end.x&&a.y==end.y)
                      flag=true;
                  for(i=0;i<4;i++)
                  {
                          x=a.x+direction[i][0];
                          y=a.y+direction[i][1];
                          if(x>=0&&y>=0&&x<n&&y<m&&maze[x][y].c)
                                    if(maze[x][y].step>maze[a.x][a.y].step+maze[x][y].c)
                                    {
                                                maze[x][y].step=maze[a.x][a.y].step+maze[x][y].c;
                                                b.x=x;
                                                b.y=y;
                                                q.push(b);
                                    }
                  }
 
           }
           if(flag)
                 printf("%d\n",maze[end.x][end.y].step);
          else
                 printf("impossible\n");
 
       }
}
