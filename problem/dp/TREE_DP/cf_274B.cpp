#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
void solve(){
  int n;
  cin>>n;
  vector<int>add(n+1),del(n+1),a(n+1);
  vector<vector<int>>E(n+1);
  for(int i=0;i<n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for(int i=1;i<=n;++i)cin>>a[i];
  function<void(int,int)>dfs=[&](int x,int f){
    for(int v:E[x]){
        if(v==f)continue;
        dfs(v,x);
        add[x]=max(add[x],add[v]);
        del[x]=max(del[x],del[v]);
    }
    a[x]+=add[x];
    a[x]-=del[x];
    if(a[x]>0){
        del[x]+=a[x];
    }else{
        add[x]-=a[x];
    }
  };
  dfs(1,-1);
  cout<<add[1]+del[1]<<'\n';
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