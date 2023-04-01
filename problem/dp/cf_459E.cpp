#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct edge{
    int from,to,w;
};
void solve(){
  int n,m;cin>>n>>m;
  vector<pair<int,int>>state;
  vector<int>dp(n+1);
  vector<edge>E(m+1);
  int ans=0;
  auto calc=[&](){
    for(auto pi:state){
        dp[pi.first]=max(dp[pi.first],pi.second);
        ans=max(dp[pi.first],ans);
    }
    state.clear();
  };    
  for(int i=1;i<=m;++i){
    cin>>E[i].from>>E[i].to>>E[i].w;
  }
  sort(E.begin()+1,E.end(),[&](edge a,edge b){
    return a.w<b.w;
  });
  for(int i=1;i<=m;++i){
    if(E[i].w!=E[i-1].w)calc();
    state.push_back({E[i].to,dp[E[i].from]+1});
  }
  calc();
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