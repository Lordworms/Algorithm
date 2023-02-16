/*
    we could get low bit by every query
    if lowbit is i , last=1
    then every subtract:
        i->0
        [0:i-1]->1
        so 
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll cnt;cin>>cnt;
  auto query=[&](int x)
  {
    cout<<" - "<<x<<'\n';
    cout.flush();
    int res;
    cin>>res;
    return res;
  };
  auto report=[&](int x)
  {
    cout<<"! "<<x<<'\n';
  };
  ll ans=0,tt=0;
  for(int i=0;i<30;++i)
  {
    int t=query(1<<i);
    if(t<cnt)
    {
        ans+=(1<<i);
    }
    else if(t>=cnt)
    {
        ans+=(1<<(i+1));
        ++tt;
    }
    cnt=t;
    if(!cnt||tt==t)
    {
        break;
    }
  }
  report(ans);
  cout.flush();
  return;
}
int main()
{
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