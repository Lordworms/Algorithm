#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=2e5+10;
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
  int n,k;cin>>n>>k;
  using pii=pair<int,int>;
  vector<pii>vec;
  for(int i=1;i<=n;++i){
    int l,r;
    cin>>l>>r;
    vec.push_back({l-1,1});
    vec.push_back({r,-1});
  }
  sort(vec.begin(),vec.end());
  ll cnt=0,ans=0,left=-1;
  for(auto pi:vec){
    ans=(ans+C(cnt,k,MOD)*(pi.first-left))%MOD;
    left=pi.first;
    cnt+=pi.second;
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