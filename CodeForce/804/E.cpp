/*
    dp[i]表示i作为最小因子的时候的比i大的最小因子
    dp[i]=min(dp[i],dp[j/i]);
    https://www.acwing.com/solution/content/124601/
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
void solve()
{
  int n,m;
  cin>>n>>m;
  int maxx=-1,minx=m+1;
  vector<int>vis(m+1),exi(m+1);
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    maxx=max(a[i],maxx);
    minx=min(a[i],minx);
    vis[a[i]]=exi[a[i]]=1;
  }
  vector<int>dp(maxx+1);
  for(int i=1;i<=maxx;++i)dp[i]=i;
  int ptr=maxx;
  int ans=maxx-minx;
  for(int i=maxx;i>=1;--i)
  {
    for(int j=i*i;j<=maxx;j+=i)
    {
        if(vis[j])exi[dp[j]]--;
        dp[j]=min(dp[j],dp[j/i]);
        if(vis[j])exi[dp[j]]++;
    }
    while(!exi[ptr])--ptr;
    if(i<=minx)ans=min(ans,ptr-i);
  }
  cout<<ans<<'\n';
  return;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}