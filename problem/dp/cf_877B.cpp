#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  string s;
  cin>>s;
  int n=s.size();
  vector dp(n,vector<ll>(3));
  dp[0][0]=dp[0][2]=s[0]=='a';
  dp[0][1]=s[0]=='b';
  for(int i=1;i<n;++i)
  {
    if(s[i]=='a'){
        dp[i][0]=dp[i-1][0]+1;
        dp[i][1]=dp[i-1][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][2])+1;
    }else{
        dp[i][1]=max(dp[i-1][0]+1,dp[i-1][1]+1);
        dp[i][0]=dp[i-1][0];
        dp[i][2]=dp[i-1][2];
    }
  }
  cout<<std::max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<'\n';
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