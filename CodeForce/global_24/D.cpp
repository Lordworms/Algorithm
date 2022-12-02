/*
    1. let's pick up the start point to s=0, then rightmost point must be x=(n+1)/2-1
    Then the points ranging in [n/2+1,n] are must delete
    2. then we have may delete set, which is those points ranging in [1,x-1]
    3. we also have to notice that, if we choose x+1 or s-1 to be the last point to delete, then we are not able to, so we need to delete from that
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=5010;
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
    init(n,mod);
    ll ans=0;
    for(ll x=0;x<(n+1)/2;++x)
    {
        ll M=n-(x+1);
        ll P=max(x-1,0ll);
        ll L=n/2+x-(n+1)/2+1;
        for(int s=0;s<=P;++s)
        {
            ans+=C(P,s,mod)*fac[M-1+s]%mod*L%mod;
            ans%=mod;
        }
    }
    ans*=n;
    ans%=mod;
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
  solve();
  return 0;
}