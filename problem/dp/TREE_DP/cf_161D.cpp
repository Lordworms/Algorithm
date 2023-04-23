#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<vector<int>>E(n+1);
  for(int i=0;i<n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector dp(n+1,vector<int>(k+1));
  int ans=0;
  function<void(int,int)>dfs=[&](int x,int f){
    dp[x][0]=1;
    for(int v:E[x]){
        if(v==f)continue;
        dfs(v,x);
        for(int i=0;i<k;++i){
            ans+=dp[x][i]*dp[v][k-i-1];
        }
        for(int i=1;i<=k;++i){
            dp[x][i]+=dp[v][i-1];
        }
    }
  };
  dfs(1,-1);
  cout<<ans<<'\n';
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