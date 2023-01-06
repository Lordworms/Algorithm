#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,x;
  cin>>n;
  vector<int>dp(n+1,0);
  ll ans=0;
  for(int i=1;i<=n;++i)
  {
    cin>>x;
    dp[i]=min(dp[i-1]+1,x);
    ans+=dp[i];
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}