/*
    combo, let us image a tree, that if a line is black, means the node lose, else the node win,
    if a road from root to leaf has less or equal than min(n,k) black line, then the sponsor could always make those guys win
    just image every road is a binary string of length n, and the number of 1 in the string denote the number of the black line, so the answer is clear
    C(n,1)+....C(n,min(n,k)) is the minimal points that satisfy the condition
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
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
  int n,k;
  cin>>n>>k;
  ll ans=1;
  for(int i=1;i<=min(n,k);++i)
  {
    ans=(ans+C(n,i,MOD)%MOD)%MOD;
  }
  cout<<ans<<'\n';
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  init(MAXN-1,MOD);
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}