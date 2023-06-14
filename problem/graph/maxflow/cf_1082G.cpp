/*
    最大闭合子图问题：把原点和正点权连线，把汇点和负点权连线，对应的权值为本来的点权的绝对值，之后把本来的u,v连线，权重为inf,最后的结果就是正点权的权重和-最小割
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e18;
struct Dinic
{
  struct Edge
  {
    int from,to;
    ll cap;
    Edge(int f,int t,ll c):from(f),to(t),cap(c){}
  };
  int n,m,s,t;//size of point and line and the start point and end point
  vector<int>d,cur;
  vector<bool>vis;
  vector<Edge>E;
  vector<vector<int>>G;
  const int INF=0x3f3f3f3f;
  Dinic(int n,int m):n(n),m(m)
  {
    d.resize(n+1);
    vis.resize(n+1,false);
    G.resize(n+1);
    cur.resize(n+1);
  }
  void add_edge(int from,int to,ll cap)
  {
    E.push_back({from,to,cap});
    G[from].push_back(E.size()-1);
    E.push_back({to,from,0});
    G[to].push_back(E.size()-1); 
  }
  bool bfs()//get the depth of every point
  {
    fill(vis.begin(),vis.end(),false);
    queue<int>q;
    q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
      int x=q.front();
      q.pop();
      for(int i=0;i<G[x].size();++i)
      {
        auto& e=E[G[x][i]];
        if(!vis[e.to]&&e.cap)
        {
          vis[e.to]=1;
          d[e.to]=d[x]+1;
          q.push(e.to);
        }
      }
    }
    return vis[t];
  }
  ll dfs(int x,ll a)
  {
    if(x==t||a==0)return a;
    ll res=0,f;
    for(int& i=cur[x];i<G[x].size();++i)
    {
      auto& e=E[G[x][i]];
      if(d[x]+1==d[e.to]&&e.cap)
      {
        ll f=dfs(e.to,min(a-res,e.cap));
        e.cap-=f;
        E[G[x][i]^1].cap+=f;
        res+=f;
        if(res==a)break;
      }
    }
    return res;
  }
  ll maxflow(int s,int t)
  {
    this->s=s;
    this->t=t;
    ll ans=0;
    while(bfs())
    {
      fill(cur.begin(),cur.end(),0);
      ans+=dfs(s,INF);//INF is the now flow
    }
    return ans;
  }
};
void solve(){
  int n,m;
  cin>>n>>m;
  Dinic dinic(n+m+3,0);
  vector<ll>a(n+1);
  ll sum=0;
  int S=0,T=n+m+1;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    dinic.add_edge(S,i,a[i]);//connect cost
  }
  for(int i=1;i<=m;++i){
    ll u,v,w;
    cin>>u>>v>>w;
    sum+=w;
    dinic.add_edge(u,i+n,INF);
    dinic.add_edge(v,i+n,INF);
    dinic.add_edge(i+n,T,w);
  }
  cout<<sum-dinic.maxflow(S,T)<<'\n';
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