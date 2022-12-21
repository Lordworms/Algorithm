/*
    probability dp
    suppose that there are k 1 in x and k 0 in last y
    then a valid operation is (k*k)/(n*(n-1)/2)
    dp[i]=p*dp[i-1]+(1-p)*dp[i];
    we want to get the inv of i not i!
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2000100;
const ll MOD=998244353;
ll quick_pow(ll x,ll exp,ll p)
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
void init(int n,ll p)
{
  memset(inv,0,sizeof(inv));
  memset(fac,0,sizeof(fac));
  inv[0]=fac[0]=1;
  for(int i=1;i<=n;++i)
  {
    fac[i]=fac[i-1]*i%p;
  }
  inv[n]=quick_pow(fac[n],p-2,p)%p;
  for(int i=n;i>=1;--i)inv[i]=quick_pow(i,MOD-2,MOD);
}
void solve()
{
  int tot=0,cnt=0;
  ll n;
  cin>>n;
  vector<int>arr(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>arr[i];
    if(arr[i]==0)
    {
        ++tot;
        if(arr[tot]==1)
        {
            ++cnt;
        }
    }
  }
  ll ans=0;
  ll base=(1ll*n*(n-1)/2)%MOD;
  for(int i=cnt;i>=1;--i)
  {
    ans=(ans+base*inv[i]%MOD*inv[i]%MOD)%MOD;
  }
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
  init(MAXN-1,MOD);
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}