#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
const int MOD=998244353;
using ll=long long;
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
int main(){
    init(MAXN-1,MOD);
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<ll>dp(n+2);
    dp[n+1]=1;
    for(int i=n;i>=1;--i){
        if(a[i]<=0)continue;
        for(int j=a[i]+i+1;j<=n+1;++j){
            dp[i]=(dp[i]+(dp[j]*C(j-i-1,a[i],MOD))%MOD)%MOD;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        ans+=dp[i];
        ans%=MOD;
    }
    cout<<ans<<'\n';
}