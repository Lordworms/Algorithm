#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
const int MAXN=1e6+10,LIM=1e6;
int x,y;
int mu[MAXN],prim[MAXN];
bool flag[MAXN];
int quick_pow(int base,int exp){int ans=1;while(exp){if(exp&1)ans=ans*base%MOD;exp>>=1,base=base*base%MOD;}return ans;}
void init(int n)
{
    int cnt=0;
    mu[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!flag[i])prim[cnt++]=i,mu[i]=-1;
        for(int j=0;i*prim[j]<=n;++j)
        {
            flag[i*prim[j]]=true;
            if(i%prim[j]==0)
            {
                mu[i*prim[j]]=0;
                break;
            }
            mu[i*prim[j]]=-mu[i];
        }
    }
}
int Mu(int x)//线性求
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