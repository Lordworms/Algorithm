#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  vector dp(n+1,vector<ll>(k+1));
  vector<ll>sum(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>sum[i];
    sum[i]+=sum[i-1];
  }
  for(int i=m;i<=n;++i)
  {
    for(int j=1;j<=k;++j)
    {
      dp[i][j]=dp[i-1][j];
      if(j*m>i)break;
      dp[i][j]=max(dp[i][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
    }
  }
  cout<<dp[n][k]<<'\n';
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