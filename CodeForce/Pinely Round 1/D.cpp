/*
assume we have the a,b,c array
the array c represent the whether this bit carries or not
so let assume there are q consecutive pair which ci != ci-1
so for ci==ci-1 we have 3 choice of pair {a,b} otherwise, we have one choice of {a,b}
so we must have q/2 consecutive ranges of 1's and (q+1)/2 consecutive range of 0's
so the answer is easy, we just need to arrange those k element in to this ranges, and the answer is the sum of all different q
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int MAXN=1e6+10;
int n,k;
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
ll inv[MAXN],fac[MAXN],p3[MAXN];
void init(int n,int p)
{
  memset(inv,0,sizeof(inv));
  memset(fac,0,sizeof(fac));
  inv[0]=fac[0]=p3[0]=1;
  for(int i=1;i<=n;++i)
  {
    fac[i]=fac[i-1]*i%p;
    p3[i]=p3[i-1]*3%p;
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
    ll ans=0;
    if(k==0)
    {
        ans=quick_pow(3,n,MOD);
        cout<<ans<<"\n";
        return;
    }
    for(int i=0;i<=n;++i)
    {
        ll c1=(1+i)/2;
        ll c0=(2+i)/2;
        ll c=1;
        if(c1>k)continue;
        int rem=n+1-c0-c1;
        if(c1==0)continue;
        ans+=(C(k-1,c1-1,MOD)*C(n-k,c0-1,MOD))%MOD*p3[n-i]%MOD;
        ans%=MOD;
    }
    cout<<ans<<"\n";
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
  cin>>n>>k;
  init(n,MOD);
  solve();
  return 0;
}