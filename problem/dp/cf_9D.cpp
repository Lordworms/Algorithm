#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,h;
  cin>>n>>h;
  vector dp(n+1,vector<ll>(n+1));//dp[i][j] means using i nodes and the depth is less than j
  for(int height=1;height<=n;++height){
    dp[0][height-1]=1;
    for(int total_nodes=1;total_nodes<=n;++total_nodes){
        for(int left=0;left<total_nodes;++left){//number of left nodes
            dp[total_nodes][height]+=dp[left][height-1]*dp[total_nodes-left-1][height-1];
        }
    }
  }
  cout<<dp[n][n]-dp[n][h-1]<<'\n';
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