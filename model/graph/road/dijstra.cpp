#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Edge
{
    int to,cost;
};
const int MAXN=5e5+10;
struct Dijkstra
{
    struct node
    {
        ll dis;
        int u;
        bool operator>(const node& a)const
        {
            return dis>a.dis;
        }
    };
    int n,s;
    const ll INF=INT_MAX;
    vector<Edge>edges[MAXN];
    ll dis[MAXN];
    int vis[MAXN];
    priority_queue<node,vector<node>,greater<node>>q;
    void add_edge(int from,int to,int w)
    {
        edges[from].push_back({to,w});
    }
    void getMin()
    {
        memset(dis,INF,sizeof(dis));
        dis[s]=0;
        q.push({0,s});
        while(!q.empty())
        {
            auto u=(q.top().u);
            q.pop();
            if(vis[u])continue;
            vis[u]=1;
            for(auto ed:edges[u])
            {
                int to=ed.to,cost=ed.cost;
                if(dis[to]>dis[u]+cost)
                {
                    dis[to]=dis[u]+cost;
                    q.push((node){dis[to],to});
                }
            }
        }
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
  return 0;
}