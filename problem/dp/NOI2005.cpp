#include <bits/stdc++.h>
using namespace std;
const int MAXN=210;
int n,m,sx,sy,K;
struct node{int v,pos;};
char mp[MAXN][MAXN];
int dp[MAXN][MAXN];
node q[MAXN];
int ans;
int dir[][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int x,int y,int len,int d)
{
  int l=0,r=-1;
  for(int i=1;x<=n&&x>=1&&y<=m&&y>=1;x+=dir[d][0],y+=dir[d][1],++i)
  {
    if(mp[x][y]=='x'){l=0,r=-1;}
    while(l<=r&&q[r].v-q[r].pos+i<=dp[x][y])--r;
    q[++r]=node{dp[x][y],i};
    if(q[r].pos-q[l].pos>len)++l;
    dp[x][y]=q[l].v+i-q[l].pos;
   if(dp[x][y]>ans)
   {
      ans=dp[x][y];
   }
  }
}
int main()
{
  cin>>n>>m>>sx>>sy>>K;
  memset(dp,-0x3f3f3f3f,sizeof(dp));
  for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
  dp[sx][sy]=0;
  int s,t,d;
  for(int i=0;i<K;++i)
  {
    cin>>s>>t>>d;
    int len=t-s+1;
    if(d==1)for(int i=1;i<=m;++i)dfs(n,i,len,d);
    if(d==2)for(int i=1;i<=m;++i)dfs(1,i,len,d);
    if(d==3)for(int i=1;i<=n;++i)dfs(i,m,len,d);
    if(d==4)for(int i=1;i<=n;++i)
                dfs(i,1,len,d);
  } 
  cout<<ans<<endl;
  return 0;
}