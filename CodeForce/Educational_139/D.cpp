#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1e7+10;
int prime[MAXN],p[MAXN],cnt;//p stands for the biggest prim factor of i and prime stands for whether it is a prim
void init_prim()
{
    p[0]=p[1]=1;
    for(int i=2;i<MAXN;++i)
    {
        if(!p[i])
        {
          prime[++cnt]=i;
          p[i]=i;  
        }
        for(int j=1;j<=cnt&&i*prime[j]<MAXN;++j)
        {
            p[i*prime[j]]=prime[j];
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
void solve()
{
  int x,y;
  cin>>x>>y;
  int dif=abs(x-y);
  int ans=INT_MAX;
  if(abs(x-y)==1)
  {
    cout<<-1<<'\n';
    return;
  }
  if(gcd(x,y)!=1)
  {
    cout<<0<<'\n';
    return;
  }
  int idx=1;
  while(prime[idx]*prime[idx]<=dif)
  {
    if(dif%prime[idx]==0)
    {
        ans=min(ans,prime[idx]-x%prime[idx]);
        while(dif%prime[idx]==0)dif/=prime[idx];
    }
    ++idx;
  }
  if(dif>1)
  {
    ans=min(ans,dif-x%dif);
  }
  cout<<ans<<'\n';
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  init_prim();
  while(T--)
  {
    solve();
  }
  return 0;
}