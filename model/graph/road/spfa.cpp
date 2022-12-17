#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1e5+10;
struct Edge
{
    int to,cost;
};
struct SPFA
{
    vector<Edge>edges[MAXN];
    ll dis[MAXN];
    int vis[MAXN],cnt[MAXN];
    int s,n;
    const int INF=0x3f3f3f3f;
    void add_edge(int from,int to,int w)
    {
        edges[from].push_back({to,w});
    }
    bool spfa()
    {
        queue<int>q;
        memset(dis,INF,sizeof(dis));
        dis[s]=0;
        vis[s]=1;
        q.push(s);
        while(!q.empty())
        {
            auto u=q.front();
            q.pop();
            vis[u]=0;
            for(int i=0;i<edges[u].size();++i)
            {
                auto v=edges[u][i].to,cost=edges[u][i].cost;
                if(dis[v]>dis[u]+cost)
                {
                    dis[v]=dis[u]+cost;
                    cnt[v]=cnt[u]+1;
                    if(cnt[v]>=n)return false;
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v]=1;
                    }
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