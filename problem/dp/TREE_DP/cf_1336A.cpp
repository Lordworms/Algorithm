#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;cin>>n>>k;
  vector<vector<int>>E(n+1);
  for(int i=0;i<n-1;++i){
    int a,b;cin>>a>>b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<ll>dep(n+1),siz(n+1);
  function<void(int,int)>dfs=[&](int x,int f){
    siz[x]=1;
    for(int v:E[x]){
        if(v==f)continue;
        dep[v]=dep[x]+1;
        dfs(v,x);
        siz[x]+=siz[v];
    }
    dep[x]-=(siz[x]-1);
  };
  dfs(1,0);
  sort(dep.begin()+1,dep.end(),greater<ll>());
  ll ans=accumulate(dep.begin()+1,dep.begin()+k+1,0ll);
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