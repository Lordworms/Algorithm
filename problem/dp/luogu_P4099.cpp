#include <bits/stdc++.h>
using namespace std;
const int MAXN=6e3+10;
struct edge{
    int v,nxt;
}E[MAXN];
int head[MAXN];
int cnt,n;
bool vis[MAXN];
int dp[MAXN][2];
int in[MAXN];
void add_edge(int x,int y)
{
    E[cnt].nxt=head[x];
    E[cnt].v=y;
    head[x]=cnt++;
}
void dfs(int x)
{
    vis[x]=true;
    for(int i=head[x];i!=-1;i=E[i].nxt)
    {
        int v=E[i].v;
        if(vis[v])continue;
        dfs(v);
        dp[x][1]+=dp[v][0];
        dp[x][0]+=max(dp[v][0],dp[v][1]);
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  int x,y;
  memset(head,-1,sizeof(head));
  for(int i=1;i<=n;++i)cin>>dp[i][1];
  for(int i=0;i<n-1;++i)
  {
    cin>>x>>y;
    add_edge(y,x);
    in[x]++;
  }
  for(int i=1;i<=n;++i)
  {
    if(in[i]==0)
    {
        dfs(i);
        cout<<max(dp[i][0],dp[i][1])<<endl;
    }
  }
  return 0;
}