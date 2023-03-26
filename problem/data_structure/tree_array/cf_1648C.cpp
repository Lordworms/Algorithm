#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
const int MAXN=200010;
#define lowbit(x) x&-x
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
  int n,m;
  cin>>n>>m;
  vector<int>tree(MAXN+1);
  auto add=[&](int x,int v){
    while(x<=MAXN){
      tree[x]+=v;
      x+=lowbit(x);
    }
  };
  auto sum=[&](int x){
    ll ans=0;
    while(x){
      ans+=tree[x];
      x-=lowbit(x);
    }
    return ans;
  };
  vector<int>s(n+1),t(m+1);
  vector<int>cnt(MAXN);
  for(int i=1;i<=n;++i){
    cin>>s[i];
    cnt[s[i]]++;
    add(s[i],1);
  }
  for(int i=1;i<=m;++i){
    cin>>t[i];
  }
  ll total=1;
  for(int i=0;i<MAXN;++i){
    if(cnt[i]){
      total=total*fac[cnt[i]]%MOD;
    }
  }
  ll total_inv=quick_pow(total,MOD-2,MOD);
  int lim=min(n,m);
  int eq=1;
  if(n>=m){eq=0;}
  ll ans=0;
  for(int i=1;i<=lim;++i){
    int p=sum(t[i]-1);
    ans=(ans+fac[n-i]*p%MOD*total_inv%MOD)%MOD;
    if(!cnt[t[i]]){
      eq=0;
      break;
    }
    total_inv=total_inv*cnt[t[i]]%MOD;
    cnt[t[i]]--;
    add(t[i],-1);
  }
  ans+=eq;
  ans%=MOD;
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