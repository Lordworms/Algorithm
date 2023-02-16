/*
    
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e18;
void solve()
{
  int n;
  cin>>n;
  vector<int>c(n+1);
  vector<string>rev(n+1),s(rev);
  for(int i=1;i<=n;++i)
  {
    cin>>c[i];
  }
  for(int i=1;i<=n;++i)
  {
    cin>>s[i];
    rev[i]=s[i];
    reverse(rev[i].begin(),rev[i].end());
  }
  vector<vector<ll>>dp(n+1,vector<ll>(2,MOD));
  dp[1][0]=0;
  dp[1][1]=c[1];
  for(int i=2;i<=n;++i)
  {
    if(s[i]>=s[i-1])dp[i][0]=min(dp[i-1][0],dp[i-1][0]);
    if(s[i]>=rev[i-1])dp[i][0]=min(dp[i-1][1],dp[i][0]);
    if(rev[i]>=s[i-1])dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
    if(rev[i]>=rev[i-1])dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
  }
  if(dp[n][0]==dp[n][1]&&dp[n][0]==MOD)
  {
    cout<<-1<<'\n';
  }
  else
  {
    cout<<min(dp[n][0],dp[n][1])<<'\n';
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