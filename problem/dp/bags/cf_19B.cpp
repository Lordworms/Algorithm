#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<ll>t(n+1),c(n+1);
  ll w=0;
  for(int i=1;i<=n;++i){
    cin>>t[i]>>c[i];
    ++t[i];
    w=max(t[i],w);
  }
  w+=n;
  vector<ll>dp(w+1,1e16);
  dp[0]=0;
  for(int i=1;i<=n;++i){
    for(int v=w;v>=t[i];--v){
        dp[v]=min(dp[v],dp[v-t[i]]+c[i]);
    }
  }
  ll ans=1e16;
  for(int i=n;i<=w;++i){
    ans=min(ans,dp[i]);
  }
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