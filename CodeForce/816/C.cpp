/*
    let's define the contribution of a element to a range is the most left element
    example:
        1 3 3 4 5
    then for left part, the 3 would contribute to 1 3, for right part, 3 would contribute to 3 4 5
    so the contribution of 3 is 2X3

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll n,m;
  cin>>n>>m;
  vector<ll>a(n+2,0);
  for(int i=1;i<=n;++i)cin>>a[i];
  auto cal=[&](int pos)
  {
    ll l;
    if(pos<1||pos>n)return 0ll;
    if(pos==1)
    {
        l=1;
    }
    else
    {
        if(a[pos]==a[pos-1])
        {
            l=1;
        }
        else
        {
            l=pos; 
        }
    }
    return 1ll*l*(n-pos+1);
  };
  ll ans=0;
  for(int i=1;i<=n;++i)ans+=cal(i);
  for(int i=0;i<m;++i)
  {
    int p,x;
    cin>>p>>x;
    ans-=cal(p-1);
    ans-=cal(p);
    ans-=cal(p+1);
    a[p]=x;
    ans+=cal(p-1);
    ans+=cal(p);
    ans+=cal(p+1);
    cout<<ans<<'\n';
  }
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