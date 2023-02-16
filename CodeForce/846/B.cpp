#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
void solve()
{
  int n;cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  ll sum=accumulate(a.begin(),a.end(),0ll);
  ll now=a[0],rem=sum-a[0];
  ll ans=gcd(now,rem);
  for(int i=1;i<n-1;++i)
  {
    now+=a[i];rem-=a[i];
    ans=max(ans,gcd(now,rem));
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