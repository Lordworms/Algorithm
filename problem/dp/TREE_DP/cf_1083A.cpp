#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
void solve(){
  int n;
  cin>>n;
  vector<int>W(n+1);
  for(int i=1;i<=n;++i)cin>>W[i];
  vector<vector<int>>E(n+1),cost(E);
  for(int i=0;i<n-1;++i){
    int u,v,c;
    cin>>u>>v>>c;
    E[u].push_back(v);
    E[v].push_back(u);
    cost[u].push_back(c);
    cost[v].push_back(c);
  }
  vector<int>dp(n+1);
  int ans=0;
  function<void(int,int)>dfs=[&](int x,int f){
    dp[x]=W[x];
    ans=max(ans,dp[x]);
    for(int i=0;i<E[x].size();++i){
        int c=cost[x][i];
        int v=E[x][i];
        if(v==f)continue;
        dfs(v,x);
        ans=max(ans,dp[v]+dp[x]-c);
        dp[x]=max(dp[x],dp[v]+W[x]-c);
    }
  }; 
  dfs(1,0);
  cout<<ans<<'\n';   
  return;
}
signed main(){
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