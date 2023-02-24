/*
    dp[i]表示从i-1个相同转化为i个相同需要的操作数
    dp[i+1]=i/n *(dp[i]+1+dp[i+1]) + (n-i)/n *1
    dp[i+1]=
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=998244353;
const int N=1e6+10;
ll dp[N];
ll quick_pow(ll a,ll b)
{
    a%=MOD;
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%MOD;
        }
        b>>=1;
        a=a*a%MOD;
    }
    return ans;
}
void solve()
{
  string a,b;
  int n;cin>>n>>a>>b;
  int cnt=0;
  for(int i=0;i<n;++i)
  {
    if(a[i]==b[i])++cnt;
  }
  for(int i=0;i<n;++i)
  {
    ll u=(dp[i]+1)*i%MOD*quick_pow(n-i,MOD-2)%MOD;
    dp[i+1]=(u+1)%MOD;
  }
  ll ans=0;
  for(int i=cnt+1;i<=n;++i)
  {
    ans=(ans+dp[i])%MOD;
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