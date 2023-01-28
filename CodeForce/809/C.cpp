/*
    note that you can only use reverse order when calculate them
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<ll>a(n);
  auto get=[&](int i)
  {
    return max(0ll,(ll)max(a[i-1],a[i+1])-a[i]+1);
  };
  for(int i=0;i<n;++i)cin>>a[i];
  ll ans=0;
  for(int i=1;i<n-1;i+=2)
  {
    ans+=get(i);
  }
  if(n&1)
  {
    cout<<ans<<'\n';
    return;
  }
  ll tmp=ans;
  for(int i=n-2;i>=1;i-=2)
  {
    tmp-=get(i-1);
    tmp+=get(i);
    ans=min(ans,tmp);
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