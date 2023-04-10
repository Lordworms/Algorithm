#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=1e9;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1),b(a),c(a);
  vector<vector<int>>dp(n+2,vector<int>(2));//dp[i][0]means i feed after i-1
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i)cin>>b[i];
  for(int i=1;i<=n;++i)cin>>c[i];
  dp[1][0]=-INF;
  dp[1][1]=0;
  for(int i=2;i<=n+1;++i){
    dp[i][0]=max(dp[i-1][0]+b[i-1],dp[i-1][1]+a[i-1]);
    dp[i][1]=max(dp[i-1][1]+b[i-1],dp[i-1][0]+c[i-1]);
  }
  cout<<dp[n+1][0]<<'\n';
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}