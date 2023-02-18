/*
    dp[i][j][h]表示前i棵树被分成j组，且第i棵树被涂成k颜色的时候的答案
    转移方程也很简单,看代码就🌟了
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e18;
void solve()
{
  int n,m,K;
  cin>>n>>m>>K;
  vector<int>c(n+1);
  vector<vector<int>>p(n+1,vector<int>(m+1,INF));
  for(int i=1;i<=n;++i)
  {
    cin>>c[i];
  }
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=m;++j)
    {
        cin>>p[i][j];
    }
  }
  vector dp(n+1,vector<vector<ll>>(n+1,vector<ll>(m+1,INF)));
  if(c[1])
  {
    dp[1][1][c[1]]=0;
  }
  else
  {
    for(int i=1;i<=m;++i)dp[1][1][i]=p[1][i];
  }
  for(int i=2;i<=n;++i)
  {
    for(int j=1;j<=K;++j)
    {
        if(c[i])
        {
            dp[i][j][c[i]]=dp[i-1][j][c[i]];
            for(int k=1;k<=m;++k)
            {
                if(k!=c[i])
                {
                    dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j-1][k]);
                }
            }
        }
        else
        {
            for(int k=1;k<=m;++k)
            {
                dp[i][j][k]=dp[i-1][j][k]+p[i][k];
                for(int z=1;z<=m;++z)
                {
                    if(z!=k)
                    {
                        dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][z]+p[i][k]);
                    }
                }
            }
        }
    }
  }
  ll ans=INF;
  for(int i=1;i<=m;++i)
  {
    ans=min(ans,dp[n][K][i]);
  }
  cout<<(ans==INF?-1:ans)<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}