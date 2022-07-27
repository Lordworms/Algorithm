/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=24;
const int MAXM=1e5+10;
const int mod=1e9+7;
int arr[MAXN];
int n,s;
int inv[MAXM],fac[MAXM];
void init()
{
    memset(inv,0,sizeof(inv));
    auto quick_pow=[&](int base,int exp){
        int ans=1;
        while(exp)
        {
            if(exp&1)ans=ans*base%mod;
            exp>>=1;
            base=base*base%mod;
        }
        return ans;
    };
    fac[0]=1;
    for(int i=1;i<=MAXN;++i)fac[i]=fac[i-1]*i%mod,inv[i]=quick_pow(fac[i],mod-2);
}
int C(int n,int m)
{
    if(n<m||m<0)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int lucas(int n,int m)
{
    return !m?1:C(n%mod,m%mod)*lucas(n/mod,m/mod)%mod;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>s;
  init();
  int ans=0;
  for(int i=0;i<n;++i)cin>>arr[i];
  for(int i=0;i<(1<<n);++i)
  {
    int t=s;
    bool sign=true;
    for(int j=0;j<n;++j)
    {
        if(i&(1<<j))
        {
            t-=(arr[j]+1);
            sign=!sign;
        }
    }
    ans=ans+(sign?1:-1)*lucas(n+t-1,t)%mod;
  }
  cout<<ans<<endl;
  return 0;
}