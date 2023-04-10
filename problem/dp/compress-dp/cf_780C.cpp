#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  vector<vector<int>>E(n+1);
  for(int i=0;i<n-1;++i){
    int x,y;cin>>x>>y;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int>color(n+1);
  int cnt=0;
  function<void(int,int)>dfs=[&](int u,int f){
    int c=0;
    for(int v:E[u]){
        if(v!=f){
            ++c;
            while(c==color[u]||c==color[f])++c;
            color[v]=c;
            cnt=max(cnt,c);
        }
    }
    for(int v:E[u]){
        if(v!=f){
            dfs(v,u);
        }
    }
  };
  color[1]=1;
  dfs(1,1);
  cout<<cnt<<'\n';
  for(int i=1;i<=n;++i){
    cout<<color[i]<<" \n"[i==n];
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