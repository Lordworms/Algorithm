#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m,w;
  cin>>n>>m>>w;
  vector<int>dp(w+1),fa(n+1),b(n+1),we(n+1);
  function<int(int x)>f=[&](int x){
        return fa[x]==x?x:fa[x]=f(fa[x]);
  };
  iota(fa.begin(),fa.end(),0);
  for(int i=1;i<=n;++i){
    cin>>we[i];
  }
  for(int i=1;i<=n;++i){
    cin>>b[i];
  }
  for(int i=1;i<=m;++i){
    int u,v;
    cin>>u>>v;
    fa[f(u)]=f(v);
  }
  vector<vector<int>>fr(n+1);
  for(int i=1;i<=n;++i){
    fr[f(i)].push_back(i);
  }
  for(int i=1;i<=n;++i){
    for(int siz=w;siz>=0;--siz){
        int W=0,B=0;
        for(int v:fr[i]){
            W+=we[v];
            B+=b[v];
            if(siz>=we[v])dp[siz]=max(dp[siz-we[v]]+b[v],dp[siz]);
        }
        if(siz>=W){
            dp[siz]=max(dp[siz-W]+B,dp[siz]);
        }
    }
  }
  cout<<dp[w]<<'\n';
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