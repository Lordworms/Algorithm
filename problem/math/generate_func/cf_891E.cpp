/*
    题解：

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int MAXN=5010;
int quick_pow(int base,int exp){int ans=1;for(;exp;exp>>=1,base=base*base%mod)if(exp&1)ans=ans*base%mod;return ans;}
int n,k,x;
int f[MAXN];
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>k;
  int ans=1;
  f[0]=1;
  for(int i=0;i<n;++i)
  {
    cin>>x;
    for(int j=i;j;--j)
    {
        f[j]=(f[j]*x%mod-f[j-1]+mod)%mod;
    }
    f[0]=f[0]*x%mod;
  }
  int inv=quick_pow(n,mod-2);
  int ans=1,r=1;
  for(int i=0;i<k;++i)
  {
        ans=(ans+r*f[i]%mod)%mod;
        r=r*inv%mod*(k-i)%mod;
  }
  cout<<(f[0]-ans+mod)%mod<<endl;
  return 0;
}