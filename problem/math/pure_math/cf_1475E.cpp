/*
先选比第k的数大的，然后在和第k个数相同的数里选k-pos个就可以了
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int MAXN=1010;
int inv[MAXN],fac[MAXN];
int quick_pow(int x,int exp)
{
    int ans=1;
    while(exp)
    {
        if(exp&1)ans=ans*x%mod;
        x=x*x%mod;
        exp>>=1;
    }
    return ans;
}
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=MAXN;++i)fac[i]=fac[i-1]*i%mod,inv[i]=quick_pow(fac[i],mod-2)%mod;
}
int C(int n,int m)
{
    if(m<0||m>n)return 0;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  map<int,int,greater<int>>mp;
  vector<int>arr;
  init();
  int T,n,k;
  cin>>T;
  while(T--)
  {
    cin>>n>>k;
    mp.clear();
    arr.clear();
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    for(auto& it:mp)
    {
      if(k>it.second)
      {
        k-=it.second;
      }
      else
      {
        cout<<C(it.second,k)<<endl;
        break;
      }
    }
  }
  return 0;
}