/*
1. if n is odd, then there is no answer.
2. let the size of subtree of edge i is i, then we could know that we could choose our sons with C(n-2,i-1) ways and the number of connect the two vertex is (i)*(n-i)
also the number of 
3. the edge connect the leaf must be -1
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
const int MAXN=5e5+10;
ll quick_pow(ll x,ll exp,int p)
{
      ll ans=1;
      while(exp)
      {
        if(exp&1)ans=ans*x%p;
        exp>>=1;
        x=x*x%p;
      }
      return ans;
}
ll inv[MAXN],fac[MAXN];
void init(int n,int p)
{
  memset(inv,0,sizeof(inv));
  memset(fac,0,sizeof(fac));
  inv[0]=fac[0]=1;
  for(int i=1;i<=n;++i)
  {
    fac[i]=fac[i-1]*i%p;
  }
  inv[n]=quick_pow(fac[n],p-2,p)%p;
  for(int i=n;i>=1;--i)inv[i-1]=inv[i]*i%p;
}
ll C(ll n,ll m,ll p)
{
  if(m>n||m<0)return 0;
  return fac[n]*inv[n-m]%p*inv[m]%p;
}
void solve()
{
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n-1;++i)
    {
        ans=(ans+(i&1?-1:1)*C(n-2,i-1,MOD)%MOD*(n-i)%MOD*i%MOD*quick_pow(i,max(0,i-2),MOD)%MOD*quick_pow(n-i,max(0,n-i-2),MOD)%MOD+MOD)%MOD;
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
  init(MAXN-1,MOD);
  solve();
  return 0;
}