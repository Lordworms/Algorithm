#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int LIM=1e9;
#define int long long
void solve()
{
  int n;cin>>n;
  vector<int>a(n+1);
  vector dp(2,vector<int>(n+1));//dp[0][i] means the greatest element of the decrease sequence of (1,i)
  //dp[1][i] means the smallest elemnt of the increase sequence of (1,i)
  int end=n;
  for(int i=1;i<=n;++i)cin>>a[i];
  auto update=[&](int i)
  {
    dp[0][i]=LIM;
    dp[1][i]=-LIM;
    for(int j=i+1;j<=n;++j)
    {
        int v0=-LIM;
        int v1=LIM;
        if(dp[0][j-1]!=-LIM)
        {
            if(a[j]>a[j-1])
            {
                v0=max(v0,dp[0][j-1]);//puts in decrease
            }
            if(a[j]<dp[0][j-1])
            {
                v1=min(v1,a[j-1]);//puts in increase
            }
        }
        if(dp[1][j-1]!=LIM)
        {
            if(a[j]<a[j-1])
            {
                v1=min(v1,dp[1][j-1]);
            }
            if(a[j]>dp[1][j-1])
            {
                v0=max(v0,a[j-1]);
            }
        }
        if(v0==dp[0][j]&&v1==dp[1][j])break;
        dp[0][j]=v0,dp[1][j]=v1;
        if(dp[0][j]==-LIM&&dp[1][j]==LIM)//no answer
        {
            end=j-1;
            return j-i;
        }
    }
    return end-i+1;
  };
  int ans=0;
  for(int i=n;i>=1;--i)
  {
    ans+=update(i);
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}