#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e18;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  vector<vector<int>>E(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<ll>dp(n+1);
  function<void(int,int)>dfs1=[&](int x,int fa){
    dp[x]=a[x];
    for(int v:E[x]){
        if(v==fa)continue;
        dfs1(v,x);
        dp[x]+=dp[v];
    }
  };
  dfs1(1,-1);
  ll ans=-INF;
  function<void(int,int)>dfs2=[&](int x,int fa){
    ll max_first=-INF,max_second=max_first;
    for(int v:E[x]){
        if(v==fa)continue;
        dfs2(v,x);
        if(dp[v]>=max_first){
            max_second=max_first;
            max_first=dp[v];
        }else if(dp[v]>max_second){
            max_second=dp[v];
        }
        dp[x]=max(dp[x],dp[v]);
    }
    if(max_first!=-INF&&max_second!=-INF){
        ans=max(ans,max_first+max_second);
    }
  };
  dfs2(1,-1);
  if(ans==-INF){
    cout<<"Impossible"<<'\n';
  }else{
    cout<<ans<<'\n';
  }
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