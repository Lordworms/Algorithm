/*
    f(n)表示gcd为n的解
    F(n)表示gcd为n的倍数的解
    F(n)=2^(cnt(n))-1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int LIM=100000,MAXN=100010,mod=1e9+7;
int mu[MAXN],prim[MAXN];
int cnt[MAXN];
bool flag[MAXN];
int n;
void init(int n)
{
    int cnt=0;
    mu[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!flag[i])mu[i]=-1,prim[++cnt]=i;
        for(int j=1;j<=cnt&&prim[j]*i<=n;++j)
        {
            flag[prim[j]*i]=true;
            if(i%prim[j]==0)
            {
                mu[i*prim[j]]=0;
                break;
            }
            mu[i*prim[j]]=-mu[i];
        }
    }
}
int quick_pow(int base,int exp){int ans=1;while(exp){if(exp&1)ans=ans*base%mod;base=base*base%mod;exp>>=1;}return ans;}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init(LIM);
  cin>>n;
  int x;
  for(int k=0;k<n;++k)
  {
    cin>>x;
    for(int i=1;i*i<=x;++i)
    {
        if(x%i==0)
        {
            cnt[i]++;
            if(x/i!=i)cnt[x/i]++;
        }
    }
  }
  int ans=0;
  for(int i=1;i<=LIM;++i)ans=(ans+mu[i]*(quick_pow(2,cnt[i])-1)%mod)%mod;//1开始
  cout<<(ans+mod)%mod<<endl;
  return 0;
}