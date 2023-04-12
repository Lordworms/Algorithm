#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>p(n+1);
  for(int i=1;i<=n;++i)cin>>p[i];
  vector<int>dp(n+2);
  dp[1]=0;
  for(int i=2;i<=n+1;++i){
    dp[i]=dp[i-1]+1+dp[i-1]-dp[p[i-1]]+1;
  }
  cout<<dp[n+1]<<'\n';
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