/*
  每个数字都对答案有对应的贡献，然后预处理出O(1)计算组合数的方案即可
*/
#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN=1e5+10;
int inv[MAXN],fac[MAXN],arr[MAXN];
int mod=1e9+7;
int quick_pow(int x,int exp,int p)
{
    int ans=1;
    while(exp)
    {
      if(exp&1)ans=ans*x%p;
      exp>>=1;
      x=x*x%p;
    }
    return ans%p;
}
void init(int n,int p)
{
  memset(inv,0,sizeof(inv));
  memset(fac,0,sizeof(fac));
  inv[0]=fac[0]=1;
  for(int i=1;i<=n;++i)
  {
    fac[i]=fac[i-1]*i%p;
    inv[i]=quick_pow(fac[i],p-2,p)%p;
  }
}
int C(int n,int m,int p)
{
  if(m<0||n<m)return 0;
  return (fac[n]*inv[n-m]%p)*inv[m]%p;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  string s;
  
  cin>>n>>k;
  cin>>s;
  init(n,mod);
  for(int i=0;i<n;++i)
  {
    arr[i]=s[i]-'0';
  }
  int mul=1;
  vector<int>sum(n+1,0);
  int base=1;
  for(int i=n-1;i>=0;--i)
  {
    sum[i]=sum[i+1]%mod+C(i-1,k-1,mod)*base%mod;
    base=base*10%mod;
  }
  int ans=0;base=1;
  for(int i=n;i>=1;--i)
  {
    ans+=(sum[i]+C(i-1,k,mod)*base)*arr[i-1];
    ans%=mod;
    base=base*10%mod;
  }
  cout<<ans<<endl;
  return 0;
}