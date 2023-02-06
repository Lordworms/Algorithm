#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
void solve()
{
  ll n;
  cin>>n;
  ll ans=n;
  for(ll i=2;i*i<=n;++i)
  {
    if(n%i==0)
    {
        ans=gcd(ans,i);
        ans=gcd(n/i,ans);
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}