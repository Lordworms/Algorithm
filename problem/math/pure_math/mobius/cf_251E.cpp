/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2010;
const int LIM=2000;
const int mod=1073741824;
int mu[MAXN],prim[MAXN];
bool flag[MAXN];
int a,b,c;
int g[MAXN][MAXN];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void init(int n)
{
    for(int i=1;i<MAXN;++i)
    {
        for(int j=1;j<=i;++j)
            g[i][j]=g[j][i]=gcd(i,j);
    }
    mu[1]=1;
    int cnt=0;
    for(int i=2;i<=n;++i)
    {
        if(!flag[i])mu[i]=-1,prim[cnt++]=i;
        for(int j=0;j<cnt&&i*prim[j]<=LIM;++j)
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
int F(int n,int m)
{
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(g[i][m]==1)
        {
            ans+=n/i;
        }
    }
    return ans;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init(LIM);
  cin>>a>>b>>c;
  int ans=0;
  for(int i=1;i<=a;++i)
  {
    for(int j=1;j<=min(b,c);++j)
    {
        if(g[i][j]==1)
        {
            ans+=mu[j]*(a/i)*F(b/j,i)*F(c/j,i);
        }
    }
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}