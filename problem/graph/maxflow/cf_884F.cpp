#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct MCMF{
  struct edge{
    int u,v;
    ll cap,cost;
  };
  const ll INF=1e18;
  int s,t;//source and des
  ll mincostflow;//the MCMF answer
  ll maxflow;//the maxflow
  vector<edge>Edge;//all edges
  vector<vector<int>>E;//the graph
  vector<ll>dis;//distance between source and i
  vector<int>vis;//whether this point in the loose queue or not
  MCMF(int n,int source,int sink){
    E.resize(n+1);
    dis.resize(n+1);
    vis.resize(n+1);
    s=source;
    t=sink;
    mincostflow=0;
    maxflow=0;
  }
  void add_edge(int u,int v,int cap,int cost){
    E[u].push_back(Edge.size());
    Edge.push_back({u,v,cap,cost});
    E[v].push_back(Edge.size());
    Edge.push_back({v,u,0,-cost});
  }
  bool spfa(){
    fill(dis.begin(),dis.end(),INF);
    queue<int>q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while(!q.empty()){
      auto tmp=q.front();
      q.pop();
      vis[tmp]=0;
      for(int id:E[tmp]){
        auto e=Edge[id];
        int to=e.v;
        if(e.cap>0&&dis[to]>dis[tmp]+e.cost){
          dis[to]=dis[tmp]+e.cost;
          if(!vis[to]){
            q.push(to);
            vis[to]=1;
          }
        }
      }
    }
    return dis[t]!=INF;
  } 
  ll dfs(int u,ll flow){
    if(u==t)
      return flow;
    vis[u]=1;
    ll ans=0;
    for(int i=E[u].size()-1;i>=0;--i){
      int id=E[u][i];
      auto e=Edge[id];
      int v=e.v;
      if(e.cap&&!vis[v]&&dis[v]==dis[u]+e.cost){
        ll cur_flow=dfs(v,min(flow-ans,e.cap));//the flow of the remaining graph
        if(cur_flow){
          if(ans+cur_flow>flow)
            break;
          mincostflow+=cur_flow*e.cost;
          ans+=cur_flow;
          Edge[id^1].cap+=cur_flow;
          Edge[id].cap-=cur_flow;
        }
      }
    }
    vis[u]=0;
    return ans;
  }
  ll get_mcmf(){
    maxflow=0;
    while(spfa()){
      int cur_flow;
      while((cur_flow=dfs(s,INF)))maxflow+=cur_flow;
    }
    return mincostflow;
  }
};
void solve(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  s=')'+s;
  vector<int>b(n+1);
  vector<int>cnt(26);
  ll sum=0;
  for(int i=1;i<=n;++i){
    cin>>b[i];
    sum+=b[i];
    cnt[s[i]-'a']++;
  }
  int source=n/2+26+1,sink=source+1;
  MCMF mf(n/2+26+3,source,sink);
  for(int i=0;i<26;++i){
    mf.add_edge(source,i+1,cnt[i],0);
    for(int j=1;j<=n/2;++j){
       int val=0;
       if(s[j]-'a'==i){
        val=max(val,b[j]);
       }
       if(s[n-j+1]-'a'==i){
        val=max(val,b[n-j+1]);
       }
       mf.add_edge(i+1,26+j,1,-val);
    }
  }
  for(int i=1;i<=n/2;++i){
    mf.add_edge(26+i,sink,2,0);
  }
  mf.get_mcmf();
  cout<<-mf.mincostflow<<'\n';
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