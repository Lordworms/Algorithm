/*
  very clever idea to use network flow to solve the problem:
  1. first we should know that we can transfer the modification of b to modify a 
    which is that, let every a[v[i]] or a[u[i]] add 1, and then we pick up one of them, and let a[choose] minus 2
  2. how to create the graph
    first, we set up a source and a end(crap) we connect the source with point ranging[0,m) with capacity 1, which means that we need an operation on the a[v[i]] or a[u[i]] 
    then we connect i with u[i]+m and v[i]+m, which means we need a selection between them 2
    then we connect i+m with end if s[i]==1 else connect i+m with tmp
  3. do the maxflow, check the flow of i and v[i]+m and u[i]+m for specific details
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
  const ll INF=0x3f3f3f3f;
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
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<int>s(n+1),a(n+1),u(m+1),v(m+1);
  for(int i=0;i<n;++i)cin>>s[i];
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=0;i<m;++i)
  {
    cin>>v[i]>>u[i];
    --v[i],--u[i];
    ++a[v[i]],++a[u[i]];
  }
  int rem=m;
  for(int i=0;i<n;++i)
  {
    if(!s[i])continue;
    if(a[i]<0||a[i]%2)
    {
      cout<<"NO"<<'\n';
      return;
    }
    rem-=a[i]/2;
  }
  Dinic din(n+m+2,0);
  int st=n+m,t=n+m+1,tmp=n+m+2;
  for(int i=0;i<m;++i)
  {
    din.add_edge(st,i,1);
    din.add_edge(i,u[i]+m,1);
    din.add_edge(i,v[i]+m,1);
  }
  for(int i=0;i<n;++i)
  {
    if(s[i])
    {
      din.add_edge(i+m,t,a[i]/2);//this point need to sub a[i]/2 times
    }
    else
    {
      din.add_edge(i+m,tmp,rem);
    }
  }
  din.add_edge(tmp,t,rem);
  if(rem<0||din.maxflow(st,t)!=m)
  {
    cout<<"NO"<<'\n';
    return;
  }
  cout<<"YES"<<'\n';
  for(int i=0;i<m;++i)
  {
    if(din.E[6*i+2].flow==1)
    {
      swap(u[i],v[i]);
    }
    cout<<u[i]+1<<' '<<v[i]+1<<'\n';
  }
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}