/*
phi[i] represent the pair of a,b such that gcd(a,b)=1 and a+b=i
that is because gcd(a,i)=gcd(i-a,a) so it is phi[i]
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
int is[MAXN],prime[MAXN],phi[MAXN];//is:is_prim
vector<vector<int>>fac;
void init_eular()
{
  for(int i=1;i<MAXN;++i)
  {
    is[i]=1;
  }
  int cnt=0;
  is[1]=0;
  phi[1]=0;
  for(int i=2;i<MAXN;++i)
  {
    if(is[i])
    {
      prime[++cnt]=i;
      phi[i]=i-1;
    }
    for(int j=1;j<=cnt&&i*prime[j]<MAXN;++j)
    {
      is[i*prime[j]]=0;
      if(i%prime[j])
      {
        phi[i*prime[j]]=phi[prime[j]]*phi[i];
      }
      else
      {
        phi[i*prime[j]]=prime[j]*phi[i];
        break;//use the minimal prime to do
      }
    }
  }
  fac.resize(MAXN);
  for(int i=1;i<MAXN;++i)
  {
    for(int j=i;j<MAXN;j+=i)
    {
        fac[j].push_back(i);
    }
  }
}
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
void solve()
{
  int n;
  cin>>n;
  ll ans=0;
  auto lcm=[&](ll a,ll b)
  {
    return 1ll*a*b/gcd(a,b);
  };
  for(ll c=1;c<n-1;++c)
  {
    for(ll d:fac[n-c])
    {
        auto k=lcm(c,d);
        ans=(ans+1ll*lcm(c,d)*phi[(n-c)/d]%MOD)%MOD;
    }
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
  int T=1;
  init_eular();
  while(T--)
  {
    solve();
  }
  return 0;
}