#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=25;
const int mod=1e9+7;
int inv[MAXN];
int n,s;
int arr[MAXN];
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>s;
  inv[1]=1;
  auto C=[&](int n,int m){
    int ans=1;
    for(int i=0;i<m;++i)
    {
        ans=ans*((n-i)%mod)%mod*inv[i+1]%mod;
    }
    return ans%mod;
  };
  for(int i=2;i<MAXN;++i)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  for(int i=0;i<n;++i)cin>>arr[i];
  int ans=0;
  for(int i=0;i<(1<<n);++i)
  {
    bool sign=true;
    int t=s;
    for(int j=0;j<n;++j)
    {
        if(i&(1<<j))
        {
            sign=!sign;
            t-=arr[j]+1;
        }
    }
    if(t<0)continue;
    ans=(ans+(sign?1:-1)*C(n+t-1,n-1)+mod)%mod;
  }
  cout<<ans<<endl;
  return 0;
}