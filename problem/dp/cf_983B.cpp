#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector dp(n+1,vector<int>(n+1));
  for(int i=1;i<=n;++i){
    cin>>dp[i][i];
  }
  /*
        dp[l][r]=max(dp[l][r],max(dp[l+1][r],dp[l][r-1]))
  */
  for(int len=2;len<=n;++len){
    for(int l=1;l+len-1<=n;++l){
        int r=l+len-1;
        dp[l][r]=dp[l+1][r]^dp[l][r-1];
    }
  }
  for(int len=2;len<=n;++len){
    for(int l=1;l+len-1<=n;++l){
        int r=l+len-1;
        dp[l][r]=max(dp[l][r],max(dp[l+1][r],dp[l][r-1]));
    }
  }
  int q;
  cin>>q;
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<dp[l][r]<<'\n';
  }
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