/*
    we could always find a index x, for any contest i before x and a[i]<p, we would always takes it
    and for any contest i after x ,we would take it no matter a[i]<p or not
    use binary search to find the minimum x
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,q;
  cin>>n>>q;
  string ans(n+1,'0');
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  auto check=[&](int x)
  {
    fill(ans.begin(),ans.end(),'0');
    int iq=q;
    for(int i=1;i<x;++i)if(a[i]<=q)ans[i]='1';
    for(int i=x;i<=n;++i)
    {
        ans[i]='1';
        if(iq==0)return false;
        if(a[i]>iq)--iq;
    }
    if(iq<0)return false;
    return true;
  };
  int l=1,r=n,m;
  while(l<=r)
  {
    m=(l+r)>>1;
    if(check(m))
    {
        r=m-1;
    }
    else
    {
        l=m+1;
    }
  }
  check(l);
  cout<<ans.substr(1,n)<<'\n';
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