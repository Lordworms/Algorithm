/*
  time complexity: O(mn^2)
  there are two optimization for Dinic
  1. multi extend: if we there are more flow that did not used out during on extend, then we could find another road at the same time
  2. now lroad optimization: if we have extend a line, then it is impossible to extend it again
  how to do that?
  we give a depth of every point before every extend
  dep[i] means the distance between i and the start point
  we only extend the dep[i]+1 durng every extend
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct Dinic
{
  struct Edge
  {
    int from,to,cap,flow;
    Edge(int f,int t,int c,int w):from(f),to(t),cap(c),flow(w){}
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
  void add_edge(int from,int to,int cap)
  {
    E.push_back({from,to,cap,0});
    G[from].push_back(E.size()-1);
    E.push_back({to,from,0,0});
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
        if(!vis[e.to]&&e.cap>e.flow)
        {
          vis[e.to]=1;
          d[e.to]=d[x]+1;
          q.push(e.to);
        }
      }
    }
    return vis[t];
  }
  ll dfs(int x,int a)
  {
    if(x==t||a==0)return a;
    ll res=0,f;
    for(int& i=cur[x];i<G[x].size();++i)
    {
      auto& e=E[G[x][i]];
      if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
      {
        e.flow+=f;
        E[G[x][i]^1].flow-=f;
        res+=f;
        a-=f;
        if(a<=0)break;
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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  Dinic dinic(n,m);
  for(int i=0;i<m;++i)
  {
    int from,to,cap;
    cin>>from>>to>>cap;
    dinic.add_edge(from,to,cap);
  }
  cout<<dinic.maxflow(s,t)<<'\n';
  return 0;
}