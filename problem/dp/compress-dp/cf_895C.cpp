/*
  total 19 prime number in [1,70]
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=71;
vector<int>prime={2,3,5,7,11, 13,17,19,23,29, 31,37,41,43,47, 53,59,61,67};
void solve()
{
  int n;cin>>n;
  vector<int>a(N),st(N);
  vector<ll>p(n+1);
  p[0]=1;
  for(int i=1;i<=n;++i)
  {
    int x;cin>>x;
    a[x]++;
    p[i]=(p[i-1]*2)%MOD;//ways to choose odd number or even number
  }
  for(int i=2;i<=70;++i)
  {
    int x=i;
    for(int j=0;j<prime.size();++j)
    {
      while(!(x%prime[j]))
      {
        st[i]^=(1<<j);
        x/=prime[j];
      }
    }
  }
  vector dp(71,vector<int>(1<<19));
  dp[0][0]=1;
  for(int i=1;i<=70;++i)
  {
    for(int j=0;j<(1<<18);++j)
    {
      if(!a[i])dp[i][j]=dp[i-1][j];
      else dp[i][j]=(dp[i-1][j]+dp[i-1][j^st[i]])%MOD*p[a[i]-1]%MOD;//choose odd or even
    }
  }
  cout<<(dp[70][0]-1+MOD)%MOD<<'\n';
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