/*
time complexity(nm^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1e5+10;
struct Edge
{
    int from,to,cap,flow;
};
struct EK
{
    int n,m=0;
    const int INF=0x3f3f3f3f;
    vector<Edge>edges;
    vector<int>G[MAXN];
    int a[MAXN],p[MAXN];//a:最接近x的边给他的最大流,p:最接近x的边
    void init()
    {
        for(int i=0;i<MAXN;++i)G[i].clear();
        edges.clear();
    }
    void addEdge(int from,int to,int cap)
    {
        edges.push_back({from,to,cap,0});
        edges.push_back({to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    ll maxflow(int s,int t)
    {
        ll ans=0;
        while(1)
        {
            memset(a,0,sizeof(a));
            queue<int>q;
            q.push(s);
            a[s]=INF;
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                for(int i=0;i<G[x].size();++i)
                {
                    auto &e=edges[G[x][i]];
                    if(!a[e.to]&&e.cap>e.flow)
                    {
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);//update the minimum flow 
                        q.push(e.to);
                    }
                }
                if(a[t])break;
            }
            if(!a[t])break;
            //add back_edge
            for(int u=t;u!=s;u=edges[p[u]].from)
            {
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            ans+=a[t];
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
  EK demo;
  int n,m;
  cin>>n>>m;
  demo.n=n;
  int s,t;
  cin>>s>>t;
  for(int i=0;i<m;++i)
  {
    int u,v,w;
    cin>>u>>v>>w;
    demo.addEdge(u,v,w);
  }
  cout<<demo.maxflow(s,t)<<'\n';
  return 0;
}