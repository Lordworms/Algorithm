#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    vector<int>lib(n+1,0);
    vector<int>val(n+1,0);
    for(int i=1;i<=n;++i)
    {
        char ch;
        cin>>ch;
        lib[i]|=(ch-'0');
    }
    ll dp[n+1][2];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        if(lib[i])
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][0]+val[i]);
            if(!lib[i-1])dp[i][1]=max(dp[i-1][0]+val[i-1],dp[i][0]);
        }
        else
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
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
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}