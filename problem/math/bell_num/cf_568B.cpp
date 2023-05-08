/*
    Bell number is the kind of way to separate sets
    $B_{k+1}=\sum _{k=0}^{n} C_{n}^{k} B_{k}$
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=4e3+10;
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
  int n;
  cin>>n;
  ll ans=0;
  vector dp(n+1,vector<ll>(n+1));
  vector<ll>bell(n+1);
  dp[0][0]=1;
  bell[0]=1;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=i;++j){
        dp[i][j]=((dp[i-1][j-1]+dp[i-1][j]*j)%MOD);
        dp[i][j]%=MOD;
        bell[i]+=dp[i][j];
        bell[i]%=MOD;
    }
  }
  for(int i=0;i<n;++i){
    ans+=(C(n,i,MOD)*bell[i])%MOD;
    ans%=MOD;
  }
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
  int T=1;
  init(MAXN-1,MOD);
  while(T--){
    solve();
  }
  return 0;
}