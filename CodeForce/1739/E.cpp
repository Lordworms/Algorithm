#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int>st[2];
    char ch;
    for(int i=0;i<n;++i)
    {
        cin>>ch;
        st[0].push_back(ch-'0');
    }
    for(int i=0;i<n;++i)
    {
         cin>>ch;
         st[1].push_back(ch-'0');
    }
    int dp[n][2][2];
    for(int i=0;i<n;++i)for(int j=0;j<2;++j)for(int k=0;k<2;++k)dp[i][j][k]=-1e9;
    dp[0][0][st[1][0]]=st[1][0];
    dp[0][0][0]=0;
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<2;++j)
        {
            int nxti=st[j][i+1];
            int nxtji=st[j^1][i+1];
            dp[i+1][j^1][0]=max(dp[i+1][j^1][0],dp[i][j][0]+nxtji);
            dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][0]+nxti);
            dp[i+1][j][nxtji]=max(dp[i+1][j][nxtji],dp[i][j][0]+nxti+nxtji);
        }
    }
    cout<<max({dp[n-1][0][0],dp[n-1][0][1],dp[n-1][1][0],dp[n-1][1][1]})<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}