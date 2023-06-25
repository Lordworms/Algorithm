#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;
  cin>>n>>m;
  vector<int>a(n+1),deg(n+1);
  vector<vector<int>>E(n+1);

  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=m;++i){
    int u,v;
    cin>>u>>v;
    ++u,++v;
    E[v].push_back(u);
    deg[u]++;
  }
  queue<int>qmain,qco;
  for(int i=1;i<=n;++i){
    if(!deg[i]){
        if(!a[i]){
            qmain.push(i);
        }else{
            qco.push(i);
        }
    }
  }
  int ans=0;
  while(!qmain.empty()||!qco.empty()){
    while(!qmain.empty()){
        auto cur=qmain.front();
        qmain.pop();
        for(int v:E[cur]){
            --deg[v];
            if(!deg[v]){
                if(!a[v]){
                    qmain.push(v);
                }else{
                    qco.push(v);
                }
            }
        }
    }
    if(!qco.empty()){
        ++ans;
    }
    while(!qco.empty()){
        auto cur=qco.front();
        qco.pop();
        for(int v:E[cur]){
            --deg[v];
            if(!deg[v]){
                if(!a[v]){
                    qmain.push(v);
                }else{
                    qco.push(v);
                }
            }
        }
    }
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