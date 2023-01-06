/*
    let's assume that the answer sequences is ti, it is easy to see that t is in a non-decrease
order
    let dp[i][j][k] means that we want a[i] in the jth turn and we have k chances left
    1.pick up the same number
        dp[i][j][k]=dp[i][j-1][k]
    2.pick up something else
        dp[i][j][k]=max()
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=520;
int dp[2][N][N];
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n+1,0);
  for(int i=1;i<=n;++i)cin>>a[i];
  memset(dp,-1,sizeof(dp));
  dp[0][0][0]=0;
  for(int i=1;i<=n;i++){
        memset(dp[i%2],-1, sizeof (dp[i%2]));
        for(int j=0;j<i;j++){
            for(int k=max(0,i-(j+1)-1);k<=j;k++){
                if(dp[(i+1)%2][j][k]==-1)continue;
                dp[i%2][j+1][k-(i-(j+1))+1]=max( dp[i%2][j+1][k-(i-(j+1))+1],dp[(i+1)%2][j][k]+a[i]);
                ///
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=0;k<=j;k++){
                if(dp[i%2][j-1][k]==-1)continue;
                dp[i%2][j][k]=max(dp[i%2][j][k],dp[i%2][j-1][k]+a[i]);
            }
        }
        for(int j=0;j<=n;j++){
            for(int k=0;k<=j;k++){
                dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i+1)%2][j][k]);
            }
        }
    }
  int ans=0;
  for(int i=0;i<=n;++i)
  {
    ans=max(ans,dp[n%2][n][i]);
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}