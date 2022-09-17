#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=150000 + 10,M=310;
ll a[M],b[M],t[M];
int n,m,d;
ll dp[2][N];
int q[N];
int h,ta;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m>>d;
  for(int i=1;i<=m;++i)cin>>a[i]>>b[i]>>t[i];
  memset(dp,207,sizeof(dp));
  for(int i=0;i<=n;++i)dp[0][i]=0;
  int cur,pre;
  for(int i=1;i<=m;++i)
  {
    h=1,ta=0;
    cur=i&1,pre=cur^1;
    int k=1;//加在下面会tle
    for(int j=1;j<=n;++j)
    {
        for(;k<=min(1LL*n,1LL*(t[i]-t[i-1])*d+j);++k)
        {   
            while(h<=ta&&dp[pre][k]>=dp[pre][q[ta]])--ta;
            q[++ta]=k;
        }
        while(h<=ta&&q[h]<max(0LL,j-(t[i]-t[i-1])*d))++h;//注意 
        dp[cur][j]=dp[pre][q[h]]+b[i]-abs(a[i]-j);
    }
  }
  ll ans=-1e18;
  for(int i=1;i<=n;++i)ans=max(ans,dp[cur][i]);
  cout<<ans<<endl;
  return 0;
}