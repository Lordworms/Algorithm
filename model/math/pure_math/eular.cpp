/*
    欧拉函数：什么是欧拉函数呢？我们记φ(n)为小于x且和x互质的数的数量，那么φ(n)就是欧拉函数
    φ(n)=n*(1-1/p1)(1-1/p2)(1-1/p3)*(1-1/p4)……(1-1/pn)
    
*/
#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
const int MAXN=1e5+10;
int eular(int x)
{
    int ans=x;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
          ans=ans/i*(i-1);
          while(x%i==0)x/=i;
        }        
    }
    if(x>1)ans=ans/x*(x-1);
    return ans;
}
int is[MAXN],prime[MAXN],phi[MAXN];//is:is_prim
void init_eular()
{
  for(int i=1;i<MAXN;++i)
  {
    is[i]=1;
  }
  int cnt=0;
  is[1]=0;
  phi[1]=0;
  for(int i=2;i<MAXN;++i)
  {
    if(is[i])
    {
      prime[++cnt]=i;
      phi[i]=i-1;
    }
    for(int j=1;j<=cnt&&i*prime[j]<MAXN;++j)
    {
      is[i*prime[j]]=0;
      if(i%prime[j])
      {
        phi[i*prime[j]]=phi[prime[j]]*phi[i];
      }
      else
      {
        phi[i*prime[j]]=prime[j]*phi[i];
        break;//use the minimal prime to do
      }
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}