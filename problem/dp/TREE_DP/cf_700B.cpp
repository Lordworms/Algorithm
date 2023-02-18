/*
    一条边要么左侧子树经过，要么右侧子树经过
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=200010;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<vector<int>>E(n+1);
  vector<int>have(MAXN),siz(MAXN);
  for(int i=1;i<=2*k;++i)
  {
    int u;
    cin>>u;
    have[u]++;
  }
  for(int i=1;i<=n-1;++i)
  {
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  ll ans=0;
  function<void(int,int)>dfs=[&](int u,int f)
  {
    if(have[u])siz[u]=1;
    for(int v:E[u])
    {
        if(f==v)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    ans+=min(siz[u],2*k-siz[u]);
  };
  dfs(1,-1);
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