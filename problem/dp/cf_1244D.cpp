#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>color(n+1,vector<int>(4)),E(color);
  for(int i=1;i<=n;++i){
    for(int j=1;j<=3;++j){
        cin>>color[i][j];
    }
  }
  vector<int>deg(n+1);
  for(int i=1;i<=n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  for(int i=1;i<=n;++i){
    if(deg[i]>=3){
        cout<<-1<<'\n';
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