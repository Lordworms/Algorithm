#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
const int MAXN=5e3+10;
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
void solve(){
  ll a,b,c;cin>>a>>b>>c;
  ll ans=1;
  auto calc=[&](ll x,ll y){
    ll minx=min(x,y);
    ll res=0;
    for(int i=0;i<=minx;++i){
        res=(res+C(x,i,MOD)*C(y,i,MOD)%MOD*fac[i]%MOD)%MOD;
    }
    return res;
  };
  ans=(ans*calc(a,b))%MOD;
  ans=(ans*calc(b,c))%MOD;
  ans=(ans*calc(a,c))%MOD;
  cout<<ans<<'\n';
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  init(MAXN-1,MOD);
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}