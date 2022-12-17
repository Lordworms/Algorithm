#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=5e6+10;
const int MOD=1e9+7;
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
ll inv[MAXN],fac[MAXN],pw[MAXN];
void init(int n,int p)
{
  memset(inv,0,sizeof(inv));
  memset(fac,0,sizeof(fac));
  memset(pw,0,sizeof(pw));
  inv[0]=fac[0]=pw[0]=1;
  for(int i=1;i<=n;++i)
  {
    fac[i]=fac[i-1]*i%p;
    pw[i]=pw[i-1]*2%p;
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
  int n,m;
  cin>>n>>m;
  ll ans=0;
  for(ll i=0;i<=min(n,m);++i)
  {
    int s=n+m-i-1;
    ans = (ans + C(n, i,MOD) * C(m, i,MOD) % MOD * (pw[s] * (i + 2) % MOD + (s - 1 >= 0 ?s *pw[s - 1] % MOD : 0)) % MOD) % MOD;
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
  init(MAXN-1,MOD);
  while(T--)
  {
    solve();
  }
  return 0;
}