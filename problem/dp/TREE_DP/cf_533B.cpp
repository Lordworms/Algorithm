#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e18;
void solve()
{
  int n;cin>>n;
  vector<ll>a(n+1);
  vector<vector<int>>E(n+1);
  for(int i=1;i<=n;++i)
  {
    int fa;cin>>fa>>a[i];
    if(fa!=-1)
    {
      E[fa].push_back(i);
    }
  }
  vector dp(n+1,vector<ll>(2));
  function<void(int)>dfs=[&](int now)
  { 
      dp[now][1]=-INF;
      if(E[now].size()==0)
      {
        dp[now][1]=a[now];
        dp[now][0]=0;
        return;
      }
      for(int v:E[now])
      {
        dfs(v);
        ll v0=dp[now][0],v1=dp[now][1];
        dp[now][1]=max(dp[v][1]+v0,dp[v][0]+v1);
        dp[now][0]=max(dp[v][1]+v1,dp[v][0]+v0);
      }
      dp[now][1]=max(dp[now][1],dp[now][0]+a[now]);
  };
  dfs(1);
  cout<<dp[1][1]<<'\n';
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