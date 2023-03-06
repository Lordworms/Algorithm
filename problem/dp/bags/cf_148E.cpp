#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m;cin>>n>>m;
  vector<vector<int>>ori(n+1);
  vector<vector<ll>>sum(n+1);
  for(int i=1;i<=n;++i)
  {
    int k;cin>>k;
    ori[i].resize(k+1);
    sum[i].resize(k+2);
    for(int j=1;j<=k;++j)
    {
        cin>>ori[i][j];
        sum[i][j]+=sum[i][j-1]+ori[i][j];
    }
  }
    vector pre_get(n+1,vector<int>(101));
    //pre calculate
    for(int i=1;i<=n;++i)
    {
      int len=ori[i].size();
      for(int j=1;j<len;++j)
      {
        ll tmp=0;
        for(int l=0;l<=j;++l)
        {
          int r=len-(j-l);
          tmp=max(tmp,sum[i][l]+sum[i][len-1]-sum[i][r-1]);
        }
        pre_get[i][j]=tmp;
      }
    }
    vector<ll>dp(m+1);
    for(int i=1;i<=n;++i)//pay attention to iteration order
    {
      for(int v=m;v>=0;--v)
      {
         for(int j=0;j<ori[i].size();++j)
         {
            if(v>=j)
            {
              dp[v]=max(dp[v],dp[v-j]+pre_get[i][j]);
            }
         }
      }
    }
    cout<<dp[m]<<'\n';
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