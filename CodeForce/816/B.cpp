#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll n,k,b,s;
  cin>>n>>k>>b>>s;
  vector<ll>ans(n);
  ans[0]=k*b;
  s-=k*b;
  if(s<0)
  {
    cout<<-1<<'\n';
  }
  else
  {
    for(ll i=0;i<n;++i)
    {
        ans[i]+=min(s,k-1);
        s-=min(s,k-1);
    }
    if(s)
    {
        cout<<-1<<'\n';
    }
    else
    {
        for(ll i=0;i<n;++i)cout<<ans[i]<<" \n"[i==n-1];
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