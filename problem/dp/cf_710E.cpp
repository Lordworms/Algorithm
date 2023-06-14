#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e18;
void solve(){
  ll n,x,y;
  cin>>n>>x>>y;
  vector<ll>dp(n+1,INF);
  dp[1]=x;
  for(int i=2;i<=n;++i){
    if(i%2==0){
      dp[i]=min(dp[i],dp[i/2]+y);
    }else{
      dp[i]=min(dp[(i+1)>>1]+x+y,dp[i]);
    }
    dp[i]=min(dp[i-1]+x,dp[i]);
  }
  cout<<dp[n]<<'\n';
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