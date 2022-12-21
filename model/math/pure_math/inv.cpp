/*
线性求逆元，
逆元：若ax=1(mod p)则x为ax modp的逆元
逆元也可以用来求组合数
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int quick_pow(int x,int exp,int p)
{
     int ans=1;
      while(exp)
      {
        if(exp&1)ans=ans*x%p;
        exp>>=1;
        x=x*x%p;
      }
      return ans;
}
int inv[MAXN];
void init_inv(int n,int mod,int p)//想想怎么证明
{
    memset(inv,0,sizeof(inv));
    inv[1]=1;
    for(int i=2;i<=n;++i)
    {
        inv[i]=((p-(p/i))*inv[p%i])%mod;
    }
}
int mod;
int get_inv(int n)//递归方式求
{
  return n==1?1:get_inv(mod%n)*(mod-mod/n);
}
//求任意n个数的逆元
vector<int>get_multi_inv(vector<int>arr,int p)
{
  auto quick_pow=[&](int x,int exp){
      int ans=1;
      while(exp)
      {
        if(exp&1)ans=ans*x%p;
        exp>>=1;
        x=x*x%p;
      }
      return ans;
  };
  int n=arr.size();
  vector<int>inv(n+1);
  vector<int>S(n+1),Sn(n+1);
  S[0]=1;
  for(int i=1;i<=n;++i)S[i]=S[i-1]*arr[i-1]%p;
  Sn[n]=quick_pow(S[n],p-2);
  for(int i=n-1;i>=1;--i)Sn[i]=Sn[i+1]*arr[i]%p;
  for(int i=1;i<=n;++i)inv[i]=S[i-1]*Sn[i]%p;
  return inv;
}
//逆元求组合数
int inv[MAXN],fac[MAXN];
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
  if(m>n||m<0)return 0;
  return fac[n]*inv[n-m]%p*inv[n]%p;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}