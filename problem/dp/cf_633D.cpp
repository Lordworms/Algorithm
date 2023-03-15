#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  vector<vector<int>>E(n);
  for(int i=1;i<n;++i){
    int x;cin>>x;
    E[i].push_back(x);
    E[x].push_back(i);
  }
  vector<int>c(n);
  for(int i=0;i<n;++i)cin>>c[i];
  vector dp(n,vector<ll>(2));
  function<void(int,int)>dfs=[&](int x,int f){
    dp[x][c[x]]=1;
    for(int v:E[x]){
        if(v==f)continue;
        dfs(v,x);
        int dp0=dp[x][0],dp1=dp[x][1];
        dp[x][1]=(dp1*(dp[v][1]+dp[v][0])%MOD+dp0*dp[v][1]%MOD)%MOD;
        dp[x][0]=(dp[v][1]+dp[v][0])*dp[x][0]%MOD;
    }
  };
  dfs(0,-1);
  cout<<dp[0][1]<<'\n';
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