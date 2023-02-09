#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=3e6+10;
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
  ll n,mod;
  cin>>n>>mod;
  auto sub=[&](ll a,ll b){return a-b<0?a-b+mod:a-b;};
  auto add=[&](ll a,ll b){return a+b>=mod?a+b-mod:a+b;};
  init(MAXN-1,mod);
  ll t0=1;
  ll t1=sub(sub(2ll*fac[2*n],fac[n]),t0);
  ll t2=2*fac[2*n]%mod*fac[n]%mod*C(2*n,n,mod);
  for(int i=0;i<=n;++i)
  {
    t2=sub(t2,C(n,i,mod)%mod*C(n,n-i,mod)%mod*C(2*n-i,n,mod)%mod*fac[n]%mod*fac[n]%mod*fac[n]%mod);
  }
  t2=sub(t2,add(t0,t1))%mod;
  ll t3=sub(fac[3*n],add(add(t0,t1),t2));
  ll ans=(t1+2*t2+3*t3)%mod;
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}