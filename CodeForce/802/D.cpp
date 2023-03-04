#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using db=double;
void solve()
{
  ll n;cin>>n;
  vector<ll>a(n+1);
  ll sum=0;
  db average=0;
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    sum+=a[i];
    average=max(average,(double)sum*1.0/i);
  }
  int q;
  cin>>q;
  while(q--)
  {
    ll t;cin>>t;
    if(t<average)
    {
        cout<<-1<<'\n';
    }
    else
    {
        cout<<(sum-1)/t+1<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}