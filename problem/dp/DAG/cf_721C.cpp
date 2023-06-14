#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
void solve(){
  int n,m,T;
  cin>>n>>m>>T;
  vector<vector<int>>E(n+1);
  vector<vector<int>>cost(n+1);
  vector<int>in(n+1);
  for(int i=1;i<=m;++i){
    int u,v,w;
    cin>>u>>v>>w;
    in[v]++;
    E[u].push_back(v);
    cost[u].push_back(w);
  }
  vector bef(n+1,vector<int>(n+1,0)),dp(n+1,vector<int>(n+1,INF));
  dp[1][1]=0;
  bef[1][1]=-1;
  //dp[i][j] to be the j times left, and we are in i so dp[i][j]=dp[k][j+v_k]
  function<void()>topSort=[&](){
    queue<int>q;
    for(int i=1;i<=n;++i){
      if(!in[i]){
        q.push(i);
      }
    }
    while(!q.empty()){
      auto u=q.front();
      q.pop();
      for(int i=0;i<E[u].size();++i){
        int v=E[u][i],c=cost[u][i];
        --in[v];
        if(!in[v]){
          q.push(v);
        }
        for(int j=2;j<=n;++j){
          if(dp[v][j]>dp[u][j-1]+c){
            dp[v][j]=dp[u][j-1]+c;
            bef[v][j]=u;
          }
        }
      }
    }
  };
  topSort();
  function<void(int i,int j)>printTrace=[&](int i,int j){
    if(bef[i][j]==-1){
      cout<<i<<' ';
      return;
    }
    printTrace(bef[i][j],j-1);
    cout<<i<<' ';
  };
  for(int i=n;i>=1;--i){
    if(dp[n][i]<=T){
      cout<<i<<'\n';
      printTrace(n,i);
      break;
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