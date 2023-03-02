/*
    lemma: an array could be fully delete only if 
    1.n is even
    2.the frequency of an element is not greater than n/2
    let dp[i] be the maximum length of array end with a[i]
    we could pre process all array that could be empty O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  vector f(n+2,vector<int>(n+1));
  for(int i=1;i<=n;++i)
  {
    vector<int>cnt(n+1);
    int mx=1;++cnt[a[i]];
    for(int j=i+1;j<=n;++j)
    {
        mx=max(++cnt[a[j]],mx);
        int len=j-i+1;
        if((len%2)==0&&mx<=len/2)
        {
            f[i][j]=1;
        }
        else f[i][j]=0;
    }
  }
  vector<int>dp(n+1);
  for(int i=1;i<=n;++i)
  {
    dp[i]=(f[1][i-1]==1||i==1);
  }
  dp[0]=1;
  for(int i=1;i<=n;++i)
  {
    for(int j=i+1;j<=n;++j)
    {
        if(dp[i]&&a[i]==a[j]&&(j==i+1||f[i+1][j-1]))
        {
            dp[j]=max(dp[j],dp[i]+1);
        }
    }
  }
  int ans=0;
  for(int i=1;i<=n;++i)
  {
    if(f[i+1][n]||i==n)
    {
        ans=max(ans,dp[i]);
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}