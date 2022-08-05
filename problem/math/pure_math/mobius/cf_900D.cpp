/*
    g(y)表示和为n,没有限制的子数组数量
    f(y)为和为n，且gcd为(x)的数量
    f(y)=sigma g(d)(d|y)
    反演来做
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
const int MAXN=1e6+10,LIM=1e6;
int x,y;
int prim[MAXN];
bool flag[MAXN];
int cnt=0;
int quick_pow(int base,int exp){int ans=1;while(exp){if(exp&1)ans=ans*base%MOD;exp>>=1,base=base*base%MOD;}return ans;}
void init(int n)
{
    for(int i=2;i<=n;++i)
    {
        if(!flag[i])prim[cnt++]=i;
        for(int j=0;j<cnt&&i*prim[j]<=n;++j)
        {
            flag[i*prim[j]]=true;
        }
    }
}
int mu(int x)//线性求
{
  int ans=1;
  for(int j=0;prim[j]*prim[j]<=x;++j)
  {
    if(x%prim[j]==0)
    {
        int c=0;
        while(x%prim[j]==0)x/=prim[j],++c;
        if(c>1){
          return 0;
        }
      ans=-ans;
    }
  }
  if(x!=1)ans=-ans;
  return ans;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>x>>y;
  if(y%x)
  {
    cout<<0<<endl;
    return 0;
  }
  y/=x;
  int ans=0;
  init(LIM);

  for(int i=1;i*i<=y;++i)
  {
    if(y%i==0)
    {
      (ans+=(quick_pow(2,y/i-1)*mu(i)))%=MOD;
      if(y/i!=i)
      { 
         (ans+=(quick_pow(2,i-1)*mu(y/i)))%=MOD;
      }
    }
  }
  
  (ans+=MOD)%=MOD;
  cout<<ans<<endl;
  return 0;
}