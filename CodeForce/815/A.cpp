#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll p=a*d,q=b*c;
  if(p==q)
  {
    cout<<0<<'\n';
  }
  else
  {
    if((p==0||q==0)||p%q==0||(q%p==0))
    {
        cout<<1<<'\n';
    }
    else
    {
        cout<<2<<'\n';
    }
  }
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