#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct MCMF{
  struct edge{
    int u,v;
    int cap;
    double cost;
  };
  const double INF=1e12;
  int s,t;//source and des
  double mincostflow;//the MCMF answer
  ll maxflow;//the maxflow
  vector<edge>Edge;//all edges
  vector<vector<int>>E;//the graph
  vector<double>dis;//distance between source and i
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
  void add_edge(int u,int v,int cap,double cost){
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
  double dfs(int u,double flow){
    if(u==t)
      return flow;
    vis[u]=1;
    double ans=0;
    for(int i=E[u].size()-1;i>=0;--i){
      int id=E[u][i];
      auto e=Edge[id];
      int v=e.v;
      if(e.cap&&!vis[v]&&dis[v]==dis[u]+e.cost){
        double cur_flow=dfs(v,min(flow-ans,(double)e.cap));//the flow of the remaining graph
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
      double cur_flow;
      while((cur_flow=dfs(s,INF)))maxflow+=cur_flow;
    }
    return mincostflow;
  }
};
struct node{
    double x,y;
};
void solve(){
  int n;
  cin>>n;
  vector<node>a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i].x>>a[i].y;
  }
  sort(a.begin()+1,a.end(),[&](node aa,node bb){
    return aa.y>bb.y;
  });
  if(a[1].y==a[2].y){
    cout<<-1<<'\n';
    return;
  }
  int S=0,T=2*n+1;
  MCMF mf(2*n+1,S,T);
  function<double(int,int)>dis=[&](int i,int j){
    double x_dis=a[i].x-a[j].x;
    double y_dis=a[i].y-a[j].y;
    return sqrt(x_dis*x_dis+y_dis*y_dis);
  };
  for(int i=1;i<=n;++i){
    mf.add_edge(S,i,2,0);//limit that for every node, it could only have two offspring
    if(i>=2)mf.add_edge(i+n,T,1,0);
  }
  for(int i=1;i<=n;++i){
    for(int j=i+1;j<=n;++j){
        if(a[i].y<=a[j].y)continue;
        double d=dis(i,j);
        mf.add_edge(i,j+n,1,d);//cap is 1 indicates that it could only have one parent
    }
  }
  mf.get_mcmf();
  if(mf.maxflow!=n-1){
    cout<<-1<<'\n';
    return;
  }
  cout.precision(10);
  cout<<mf.mincostflow<<'\n';
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