/*
    组合数递推公式：cab=ca(b-1)+c(a-1)(b-1)
*/
#include <bits/stdc++.h>
using namespace std;
const int N=2010;
const int mod=1e9+7;
const int MAXN=1e5+10;
using ll=long long;
void init()
{
    vector<vector<int>>C(N,vector<int>(N,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0) C[i][j]=1;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int get_inv(int n)//递归方式求
{
  return n==1?1:get_inv(mod%n)*(mod-mod/n);
}
int C(int n,int m)
{
    if(m<0||m>n)return 0;
    int up=1,down=1;
    for(int i=0;i<m;++i)
    {
        up=up*(n-i)%mod;
        down=down*(i+1)%mod;
    }
    return up*get_inv(down);
}
//逆元求
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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}