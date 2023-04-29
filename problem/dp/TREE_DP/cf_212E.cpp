#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>E(n+1);
  for(int i=0;i<n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int>dp(n+1),siz(n+1);
  function<void(int,int)>dfs=[&](int x,int f){
    siz[x]=1;
    for(int v:E[x]){
        if(v==f)continue;
        dfs(v,x);
        siz[x]+=siz[v];
    }
  };
  vector<int>ans(n+1);
  for(int i=1;i<=n;++i){
    fill(dp.begin(),dp.end(),0);
    fill(siz.begin(),siz.end(),0);
    dfs(i,-1);
    dp[0]=1;
    for(int v:E[i]){
        int size=siz[v];
        for(int vol=n;vol>=size;--vol){
            if(dp[vol-size]){
                dp[vol]=ans[vol]=1;
            }
        }
    }
  }
  int cnt=0;
  for(int i=1;i<=n-2;++i){
    if(ans[i])++cnt;
  }
  cout<<cnt<<'\n';
  for(int i=1;i<=n-2;++i){
    if(ans[i]){
        cout<<i<<' '<<(n-1-i)<<'\n';
    }
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