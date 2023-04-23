#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,d;
  cin>>n>>d;
  vector<vector<int>>E(n+1);
  for(int i=0;i<n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  int m1,m2;
  cin>>m1;
  vector<int>vis1(n+1),vis2(n+1),must1(n+1),must2(n+1);
  for(int i=0;i<m1;++i){
    int x;cin>>x;
    vis1[x]=1;
  }
  cin>>m2;
  for(int i=0;i<m2;++i){
    int x;cin>>x;
    vis2[x]=1;
  }
  int num1=0,num2=0;
  vector<int>ids(n+1);
  int cnt=0;
  function<void(int,int)>dfs=[&](int x,int f){
    ids[++cnt]=x;//use for optimization,make sure that now-d is always the points that has distance d
    for(int v:E[x]){
        if(v==f)continue;
        dfs(v,x);
        if(must1[v])must1[x]=1;
        if(must2[v])must2[x]=1;
    }
    int last_d_dep;
    if(cnt-d<=0)last_d_dep=1;
    else last_d_dep=ids[cnt-d];
    --cnt;//make sure it is the nearest d dep point
    if(vis1[x])vis2[last_d_dep]=1,must1[x]=1;
    if(vis2[x])vis1[last_d_dep]=1,must2[x]=1;
    if(must1[x])++num1;
    if(must2[x])++num2;
  };  
  dfs(1,0);  
  cout<<2*(num1+num2-2)<<'\n';
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