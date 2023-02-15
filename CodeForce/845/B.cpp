#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1e5+10;
ll fac[N];
void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<N;++i)
    {
        fac[i]=fac[i-1]*i%MOD;
    }
}
void solve()
{
  ll n;cin>>n;
  if(n==1)cout<<0<<'\n';
  else
  { 
    cout<<n*(n-1)%MOD*fac[n]%MOD<<'\n';
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
  init();
  while(T--)
  {
    solve();
  }
  return 0;
}