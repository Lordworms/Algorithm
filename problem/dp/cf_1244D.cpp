#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define rem(x,y) 6-x-y
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>colors(n+1,vector<int>(4));
  vector<vector<int>>E(n+1);
  for(int i=1;i<=3;++i){
    for(int j=1;j<=n;++j){
        cin>>colors[j][i];
    }
  }
  int u,v;
  vector<int>deg(n+1);
  for(int i=1;i<=n-1;++i){
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  vector<int>color(n+1);
  for(int i=1;i<=n;++i){
    if(deg[i]>=3){
        cout<<-1<<'\n';
        return;
    }
  }
  function<void(int,int,int,int)>dfs=[&](int x,int f,int xc,int fc){
    for(int to:E[x]){
      if(to==f)continue;
      color[to]=rem(xc,fc);
      dfs(to,x,color[to],xc);
    }
  };
  vector<int>ans_vec(n+1);
  ll ans=1e18;
  for(int f=1;f<=3;++f){
    for(int s=1;s<=3;++s){
      if(f==s){
        continue;
      }
      color[u]=f;
      color[v]=s;
      dfs(u,v,f,s);
      dfs(v,u,s,f);
      ll tmp=0;
      for(int i=1;i<=n;++i){
        tmp+=colors[i][color[i]];
      }
      if(tmp<ans){
        for(int i=1;i<=n;++i){
          ans_vec[i]=color[i];
        }
        ans=tmp;
      }
    }
  }
  cout<<ans<<'\n';
  for(int i=1;i<=n;++i){
    cout<<ans_vec[i]<<" \n"[i==n];
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