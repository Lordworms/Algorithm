#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll l,r;
  cin>>l>>r;
  ll ans=max(0ll,r/2-l+1);
  auto ceil_div=[&](ll a,ll b)
  {
    return (a+b-1)/b;
  };
  for(ll left=1,right;left<l;left=right+1)
  {
    ll f=ceil_div(l,left);
    right=ceil_div(l,f-1)-1;
    ans+=max(0ll,min(r/(f+1),right)-left+1);
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