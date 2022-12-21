#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll INF=1e18;
struct node
{
  int u;
  ll dis;
  bool operator<(const node& a)const
  {
    return dis>a.dis;
  }
};
void solve()
{
  int n,m,p,q;
  cin>>n>>m>>p>>q;
  vector<string>s(n);
  for(int i=0;i<n;++i)cin>>s[i];
  vector<pii>G[n*m+1];
  auto add_edge=[&](int i,int j,int from,int w)
  {
    if(i<0||i>=n||j<0||j>=m)return;
    int u=i*m+j;
    G[u].push_back({from,w});
  };
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m;++j)
    {
      int from=i*m+j;
      if(s[i][j]=='L')
      {
        add_edge(i,j+2,from,q);
        add_edge(i+1,j+1,from,p);
        add_edge(i-1,j+1,from,p);
      }
      else if(s[i][j]=='R')
      {
        add_edge(i,j-2,from,q);
        add_edge(i+1,j-1,from,p);
        add_edge(i-1,j-1,from,p);
      }
      else if(s[i][j]=='U')
      {
        add_edge(i+2,j,from,q);
        add_edge(i+1,j+1,from,p);
        add_edge(i+1,j-1,from,p);
      }
      else if(s[i][j]=='D')
      {
        add_edge(i-2,j,from,q);
        add_edge(i-1,j+1,from,p);
        add_edge(i-1,j-1,from,p);
      }
      else if(s[i][j]=='.')
      {
        G[n*m].push_back({from,0});
      }
    }
  }
  vector<bool>vis(n*m+1,false);
  vector<ll>dist(n*m+1,INF);
  dist[n*m]=0;
  priority_queue<node>que;
  que.push({n*m,0});
  //get the distance between n*m and every empty point
  while(!que.empty())
  {
    auto [u,dis]=que.top();
    que.pop();
    if(vis[u])continue;
    vis[u]=true;
    for(auto&[v,w]:G[u])
    {
      if(dist[v]>dis+w)
      {
        dist[v]=dis+w;
        que.push({v,dist[v]});
      }
    }
  }
  auto get=[&](int i,int j)
  {
    if(i<0||i>=n||j<0||j>=m)return INF;
    return dist[i*m+j];
  };
  ll ans=INF;
  //dist[u]: cost  to move any '.' to position u 
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m;++j)
    {
      int u=i*m+j;
      ll one=get(i+1,j),two=get(i,j+1);
      ans=min({ans,dist[u]+one,dist[u]+two});
    }
  }
  if(ans>=INF)
  {
    cout<<-1<<'\n';
  }
  else
  {
    cout<<ans<<'\n';
  }
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  solve();
  return 0;
}