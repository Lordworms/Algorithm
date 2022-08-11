/*
题意：给你n(n<=300)个数，问有多少个排列满足任意相邻两个数的积不为完全平方数。(相同数字交换位置算不同的排列，可以知道，总排列数一定有n!个)。
题解：
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=300+10,LIM=300,MOD=1e9+7,N=1e5+10;
int inv[MAXN],fac[MAXN],c[MAXN];
int n,m;//m
int dp[MAXN][MAXN];
unordered_map<int,int>h;
int quick_pow(int base,int exp){int ans=1;while(exp){if(exp&1)ans=ans*base%MOD;base=base*base%MOD;exp>>=1;}return ans;}
void init(int n)
{
    inv[0]=inv[1]=fac[1]=fac[0]=1;
    for(int i=2;i<=n;++i)fac[i]=fac[i-1]*i%MOD,inv[i]=quick_pow(fac[i],MOD-2);
}
int C(int n,int m){if(m>n||m<0)return 0;return fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  int x;
  init(LIM);
  for(int i=0;i<n;++i)
  {
    cin>>x;
    for(int i=2;i*i<=x;++i)
    {
        while(x%(i*i)==0)
        {
            x/=(i*i);
        }
    }
    if(!h.count(x))
    {
        h[x]=++m;
    }
    c[h[x]]++;
  }
  int total=0;
  dp[0][0]=1;
  for(int i=1;i<=m;++i)
  {
    total+=c[i];
    for(int k=1;k<=total;++k)
    {
      for(int j=1;j<=k;++j)
      {
        (dp[i][k]+=(dp[i-1][k-j]*C(c[i]-1,j-1)%MOD*fac[c[i]]%MOD*inv[j]%MOD))%=MOD;
      }
    }
  }
  int mul=1;
  int ans=0;
  for(int i=n;i>=0;--i)
  {
    (ans+=(mul*dp[m][i]*fac[i]%MOD))%=MOD;
    mul=-mul;
  }
  cout<<(ans+MOD)%MOD<<endl;
  return 0;
}