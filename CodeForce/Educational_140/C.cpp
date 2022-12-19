#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
void solve()
{
  int n;
  cin>>n;
  bool flag=false;
  vector<vector<int>>a(n+1,vector<int>(n+1,0));
  for(int i=0;i<n;++i)
  {
    for(int j=i;j<n;++j)
    {
      cin>>a[i][j];
      if(i==j&&a[i][j]==2)flag=true;
    }
  }
  if(flag)
  {
    cout<<0<<'\n';
    return;
  }
  vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
  if(a[0][0]!=2)dp[1][0]=2;
  auto check=[&](int last,int dif)
  { 
    --last;
    for(int i=0;i<last;++i)
    {
      if(a[i][last]==0)continue;
      if(a[i][last]==1&&dif>i)return false;
      if(a[i][last]==2&&dif<=i)return false;
    }
    return true;
  };
  for(int i=1;i<n;++i)
  {
    for(int j=0;j<i;++j)
    {
      for(int k:{j,i})
      {
        if(check(i+1,k))
        {
          dp[i+1][k]=(dp[i+1][k]+dp[i][j])%MOD;
        }
      }
    }
  }
  ll ans=0;
  for(int i=0;i<n;++i)
  {
    ans=(ans+dp[n][i])%MOD;
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
  solve();
  return 0;
}