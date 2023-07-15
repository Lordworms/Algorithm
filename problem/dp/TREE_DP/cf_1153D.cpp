#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>op(n+1);
  for(int i=1;i<=n;++i)cin>>op[i];
  vector<vector<int>>E(n+1);
  for(int i=2;i<=n;++i){
    int x;
    cin>>x;
    E[x].push_back(i);
    E[i].push_back(x);
  }
  vector<ll>dp(n+1);
  int k=0;
  function<void(int,int)>dfs=[&](int x,int f){
    int sz=0;
    if(op[x])dp[x]=1e18;
    for(int v:E[x]){
      if(v==f)continue;
      dfs(v,x);
      sz++;
      if(op[x])dp[x]=min(dp[x],dp[v]);
      else dp[x]+=dp[v];
    }
    if(!sz){
      dp[x]=1;
      ++k;
    }
  };
  dfs(1,-1);
  cout<<k+1-dp[1]<<'\n';
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