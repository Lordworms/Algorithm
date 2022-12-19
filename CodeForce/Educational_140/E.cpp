/*
    if m<=20 we can use bitmask!

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<int>dp((1<<20)+1);
  vector<int>x(m+1),c(n+1);
  vector<vector<int>>G(m+1,vector<int>(m+1,0));
  for(int i=1;i<=n;++i)
  {
    cin>>c[i];
    --c[i];
  }
  for(int i=0;i<m;++i)cin>>x[i];
  for(int i=1;i<=n;++i)
  {
    if(i>1)G[c[i]][c[i-1]]=1;
    if(i<n)G[c[i]][c[i+1]]=1;
  }
  G[c[n]][c[n]]=1,G[c[1]][c[1]]=1;
  int z1=m/2,z2=m-z1;
  for(int mask=(1<<z1)-1;mask>=0;--mask)
  {
    int ok=1;
    for(int i=0;i<z1;++i)
    {
        if((mask>>i)&1)continue;
        for(int j=i;j<z1;++j)
        {
            if((mask>>j)&1)continue;
            if(G[i][j])ok=0;
        }
    }
    if(ok)
    {
        for(int i=0;i<z1;++i)
        {
            if((mask>>i)&1)
            {
                dp[mask]+=x[i];
            }
        }
    }
    else
    {
        dp[mask]=INF;
        for(int i=0;i<z1;++i)
        {
            if(((mask>>i)&1)==0)
            {
                dp[mask]=min(dp[mask],dp[mask^(1<<i)]);//we could add extra edge
            }
        }
    }
  }
  int ans=INF;
  for(int mask=0;mask<1<<z2;++mask)
  {
    int ok=1;
    for(int i=0;i<z2;++i)
    {
        if(mask>>i&1)continue;
        for(int j=i;j<z2;++j)
        {
            if(mask>>j&1)continue;
            if(G[i+z1][j+z1])ok=0;
        }
    }
    if(ok)
    {
        int now=0,t=0;
        for(int i=0;i<z2;++i)
        {
            if(mask>>i&1)
            {
                now+=x[i+z1];
            }
            else
            {
                for(int j=0;j<z1;++j)
                {
                    if(G[i+z1][j])t|=(1<<j);
                }
            }
        }
        ans=min(ans,now+dp[t]);
    }
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
  solve();
  return 0;
}