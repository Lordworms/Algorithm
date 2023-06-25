#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=2e6+10;
vector<int>pi(MAXN);
vector<int>prime;
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
  for(int i=2;i<MAXN;++i){
    if(!pi[i]){
        prime.push_back(i);
    }
    for(int j=0;j<prime.size()&&prime[j]*i<MAXN;++j){
        pi[prime[j]*i]=1;
        if(i%prime[j]){
            break;
        }
    }
  }
}
ll C(ll n,ll m,ll p)
{
  if(m>n||m<0)return 0;
  return fac[n]*inv[n-m]%p*inv[m]%p;
}
void solve(){
  int x,y;
  cin>>x>>y;
  ll ans=1;
  for(int i=0;prime[i]*prime[i]<=x;++i){
    int cnt=0;
    while(x%prime[i]==0){
      x/=prime[i];
      ++cnt;
    }
    if(cnt>0)ans=(ans*C(cnt+y-1,y-1,MOD))%MOD;
  }
  if(x>1){
    ans=(ans*C(y,y-1,MOD))%MOD;
  }
  cout<<ans*quick_pow(2,y-1,MOD)%MOD<<'\n';
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
  int T;
  cin>>T;
  while(T--){
    solve();
  }
  return 0;
}