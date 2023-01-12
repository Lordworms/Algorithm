#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>dp(n,1),a(n);
  ll ans=-1e10;
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=0;i<n;++i)
  {
    for(int j=max(0,i-256);j<i;++j)
    {
        if((a[i]^j)>(a[j]^i))
        {
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
    ans=max(ans,(ll)dp[i]);
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