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
  if(m==n)return 1;
  return fac[n]*inv[n-m]%p*inv[m]%p;
}
void solve(){
  int n,k;
  cin>>n>>k;
  vector<vector<int>>E(n+1);
  vector<int>fa(n+1);
  for(int i=1;i<=n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int>size(n+1);
  function<void(int,int)>dfs=[&](int x,int f){
    fa[x]=f;
    size[x]=1;
    for(int v:E[x]){
      if(v!=f){
        dfs(v,x);
        size[x]+=size[v];
      }
    }
  };
  dfs(1,0);
  ll ans=0;
  for(int u=1;u<=n;++u){
    // r=u two situation that r in S or r not in S
    ll sum=0;
    for(int v:E[u]){
      int siz=v==fa[u]?n-size[u]:size[v];
      sum=sum+C(siz,k,MOD);
      sum%=MOD;
    }
    ans+=(C(n-1,k,MOD)-sum+C(n-1,k-1,MOD))*n;//two parts, first part is when r not in S,second is r in S
    ans%=MOD;
    // r!=u two situation that u in S or u not in S
    for(int r:E[u]){
      int cnt=r==fa[u]?n-size[u]:size[r];
      //u in S now the total size if n-cnt
      ans+=C(n-cnt-1,k-1,MOD)*cnt%MOD*(n-cnt)%MOD;//*cnt ,the size of subtree r is cnt
      ans%=MOD;
      //u not in S，choose the subtree which does not contain r and compute the value
      ans+=(C(n-cnt-1,k,MOD)-(sum-C(cnt,k,MOD))+MOD)%MOD*cnt%MOD*(n-cnt);
      ans%=MOD;
    }
  }
  cout<<(ans+MOD)%MOD<<'\n';
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