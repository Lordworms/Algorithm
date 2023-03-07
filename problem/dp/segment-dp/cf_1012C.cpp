#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
void solve()
{
  int n;cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  int k=(n+1)/2;
  a[0]=INF;
  vector dp(n+1,vector<vector<int>>(k+1,vector<int>(2,INF)));
  dp[0][0][0]=dp[1][0][0]=dp[1][1][1]=0;//only transfer from these 3 situation
  for(int i=2;i<=n;++i)
  {
    dp[i][0][0]=dp[i-1][0][0];
    for(int j=1;j<=(i+1)/2;++j)
    {
        dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]+max(0,a[i]-a[i-1]+1));
        dp[i][j][1]=min(dp[i-2][j-1][0]+max(0,a[i-1]-a[i]+1),dp[i-2][j-1][1]+max(0,a[i-1]-min(a[i],a[i-2])+1));
    }
  }
  for(int i=1;i<=(n+1)/2;++i)
  {
    cout<<min(dp[n][i][0],dp[n][i][1])<<' ';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}