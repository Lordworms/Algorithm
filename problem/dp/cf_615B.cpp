#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct edge
{
    int u,v;
};
void add_edge(vector<edge>& E,int u,int v)
{
    E.push_back({u,v});
}
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<ll>dp(n+1);
  vector<int>deg(n+1);
  vector<edge>E;
  for(int i=0;i<m;++i)
  {
    int u,v;
    cin>>u>>v;
    if(u>v)swap(u,v);
    add_edge(E,u,v);
    deg[u]++;
    deg[v]++;
  }
  sort(E.begin(),E.end(),[&](edge a,edge b){
        return a.u!=b.u?a.u<b.u:a.v<b.v;
  });
  for (auto [u,v]:E)
  {
    dp[v]=max(dp[v],dp[u]+1);
  }
  ll ans=0;
  for(int i=1;i<=n;++i)
  {
    ans=max(ans,(dp[i]+1)*deg[i]);
  }
  cout<<ans<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}