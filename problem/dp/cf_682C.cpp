#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  map<ll,map<ll,ll>>c;
  vector<ll>a(n+1);
  vector<vector<ll>>E(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n-1;++i)
  {
    int pi,ci;
    cin>>pi>>ci;
    E[i+1].push_back(pi);
    E[pi].push_back(i+1);
    c[i+1][pi]=c[pi][i+1]=ci;
  }
  vector<int>vis(n+1);
  function<void(ll,ll)>dfs=[&](ll now,ll maxx)
  {
    ll now_max,next_max;
    for(int v:E[now])
    {
        if(!vis[v])
        {
            now_max=maxx+c[now][v];
            next_max=max(now_max,c[now][v]);
            if(next_max<=a[v])
            {
                vis[v]=1;
                dfs(v,next_max);
            }
        }
    }
  };
  vis[1]=1;
  dfs(1ll,0ll);
  ll ans=0;
  for(int i=1;i<=n;++i)
  {
    if(!vis[i])
    {
        ++ans;
    }
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