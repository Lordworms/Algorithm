/*
    树的直径是树的所有最短路径中最长的那一条
    用两次dfs求
    第一次dfs求最出的点再以这个点做一次dfs
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
vector<int>E[MAXN];
int dis[MAXN];
int c,n;
void dfs(int now,int fa)
{
    for(int v:E[now])
    {
        if(v==fa)continue;
        dis[v]=dis[now]+1;
        if(dis[v]>dis[c])c=v;
        dfs(v,now);
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  int u,v;
  for(int i=0;i<n;++i)
  {
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(1,0);
  dis[c]=0;
  dfs(c,0);
  return 0;
}