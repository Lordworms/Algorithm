/*
    it is always possible to delete everything on the first position
    so what we need on a[i] is that a[i] needs to be the multiple of all
    prime number between 1~i-1
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=998244353;
const int MAXN=3e5+10;
const ll LIM=1e12;
int prime[MAXN],p[MAXN],cnt;//p stands for the biggest prim factor of i and prime stands for whether it is a prim
void init_prim()
{
    p[0]=p[1]=-1;
    for(int i=2;i<MAXN;++i)
    {
        if(!p[i])
        {
          prime[++cnt]=i;
          p[i]=i;  
        }
        for(int j=1;j<=cnt&&i*prime[j]<MAXN;++j)
        {
            p[i*prime[j]]=prime[j];
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
ll quick_pow(ll x,ll exp,int p)
{
      ll ans=1;
      x%=MOD;//you can predo it
      while(exp)
      {
        if(exp&1)ans=ans*x%p;
        exp>>=1;
        x=x%p*x%p;
      }
      return ans%MOD;
}
void solve()
{
  ll n,m,tmp=1,res=1,ans=0;
  cin>>n>>m;
  for(ll i=1;i<=n;++i)
  {
    if(tmp<=LIM&&p[i]==i)
    {
        tmp*=i;        
    }
    res=res%MOD*((m/tmp)%MOD)%MOD;
    ans=ans+(quick_pow(m,i,MOD)-res)%MOD;
  }
  cout<<ans%MOD<<'\n';
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
  init_prim();
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}