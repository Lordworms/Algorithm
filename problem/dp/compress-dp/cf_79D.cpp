#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
void solve(){
  int n,k,l;
  cin>>n>>k>>l;
  vector<int>x(k+1),a(n+2),len(l+1),id(n+1);
  for(int i=1;i<=k;++i){
    cin>>x[i];
    a[x[i]]=1;
  }
  for(int i=1;i<=l;++i){
    cin>>len[i];
  }
  int cnt=0;
  for(int i=0;i<=n;++i){
    a[i]^=a[i+1];
    id[i]=a[i]?cnt++:0;
  }
  vector dist(cnt+1,vector<int>(cnt+1));
  vector<int>dis(n+1,INF);
  vector<int>vis(n+1,0);
  auto dij=[&](int st){ 
    fill(dis.begin(),dis.end(),INF);
    fill(vis.begin(),vis.end(),0);
    dis[st]=0;
    vis[st]=1;
    queue<int>q;
    q.push(st);
    while(!q.empty()){
      int now=q.front();
      q.pop();
      for(int i=1;i<=l;++i){
        int d1=now+len[i],d2=now-len[i];
        if(d1<=n&&!vis[d1]){
          dis[d1]=dis[now]+1;
          vis[d1]=1;
          q.push(d1);
        }
        if(d2>=0&&!vis[d2]){
          dis[d2]=dis[now]+1;
          vis[d2]=1;
          q.push(d2);
        }
      } 
    }
    for(int i=0;i<=n;++i){
      if(a[i])dist[id[st]][id[i]]=dis[i];
    }
  };
  for(int i=0;i<=n;++i){
    if(a[i])dij(i);
  }
  vector<int>dp((1<<cnt));
  for(int status=1;status<(1<<cnt);++status){
    dp[status]=INF;
    for(int i=0;i<cnt;++i){
      if(!((status>>i)&1))continue;
      for(int j=i+1;j<cnt;++j){
        if(!((status>>j)&1))continue;
        dp[status]=min(dp[status],dp[status-(1<<i)-(1<<j)]+dist[i][j]);
      }
    }
  }
  cout<<(dp[(1<<cnt)-1]==INF?-1:dp[(1<<cnt)-1])<<'\n';
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