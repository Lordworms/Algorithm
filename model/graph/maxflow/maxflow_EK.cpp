/*
time complexity(nm^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1e5+10;
struct EK
{
  struct Edge
  {
    int from,to,cap,flow;
    Edge(int f,int t,int c,int w):from(f),to(t),cap(c),flow(w){}
  };
  int n,m,s,t;//size of point and line and the start point and end point
  vector<int>a,p;// a[x] is the flow that provided by the closest line, p is the line number which is cloest to point x
  vector<vector<int>>G;
  vector<Edge>E;
  const int INF=0x3f3f3f3f;
  EK(int n,int m,int st,int end):n(n),m(m),s(st),t(end)
  {
    G.resize(n+1);
    a.resize(n+1);
    p.resize(n+1);
  }
  void add_edge(int from,int to,int cap)
  {
      E.push_back({from,to,cap,0});
      G[from].push_back(E.size()-1);
      E.push_back({to,from,0,0});//reverse line
      G[to].push_back(E.size()-1);
  }
  ll maxflow()
  {
    ll ans=0;
    while(1)
    {
      fill(a.begin(),a.end(),0);
      queue<int>q;
      q.push(s);
      a[s]=INF;
      while(!q.empty())
      {
        int x=q.front();
        q.pop();
        for(int i=0;i<G[x].size();++i)
        {
          auto& e=E[G[x][i]];
          if(!a[e.to]&&e.cap>e.flow)//did not extended and 
          {
            a[e.to]=min(a[x],e.cap-e.flow);
            p[e.to]=G[x][i];
            q.push(e.to);
          }
        }
        if(a[t])break;
      }
      if(!a[t])//which means the start point cannot reach the end point
      {
        break;
      }
      for(int u=t;u!=s;u=E[p[u]].from)
      {
        E[p[u]].flow+=a[t];
        E[p[u]^1].flow-=a[t];
      }
      ans+=a[t];
    }
    return ans;
  }
};