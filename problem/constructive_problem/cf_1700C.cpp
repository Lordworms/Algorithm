#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<ll>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  ll ans=0;
  ll h=a[1];
  for(int i=2;i<=n;++i)
  {
    ll dif=a[i-1]-a[i];
    ans+=abs(dif);
    if(dif>0)
    {
        h-=dif;
    }
  }
  ans+=abs(h);
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