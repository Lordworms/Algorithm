#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int fa(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return fa(x) == fa(y); }
    bool merge(int x, int y) {
        x = fa(x);
        y = fa(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[fa(x)]; }
};
struct LCA
{
    int n;
    const int MAXN=1e5+10;
    vector<vector<int>>Edges,fa,w,cost;
    vector<int>dep;
    LCA(int num):n(num)
    {
        Edges.resize(num+1);
        fa.resize(num+1,vector<int>(32,0));
		cost.resize(num+1,vector<int>(32,0));
        w.resize(num+1);
        dep.resize(num+1);
    }
    void add_edge(int u,int v,int c)
    {
        Edges[u].push_back(v);
        Edges[v].push_back(u);
        w[u].push_back(c);
        w[v].push_back(c);
    }
    void dfs(int now,int f)
    {
        fa[now][0]=f;
        dep[now]=dep[f]+1;
        for(int i=1;i<31;++i)
        {
            fa[now][i]=fa[fa[now][i-1]][i-1];
            cost[now][i]=cost[fa[now][i-1]][i-1]+cost[now][i-1];
        }
        int sz=Edges[now].size();
        for(int i=0;i<sz;++i)
        {
            if(Edges[now][i]==f)continue;
            cost[Edges[now][i]][0]=w[now][i];
            dfs(Edges[now][i],now);
        }
    }
    int commonFa(int x,int y)
    {
        if(dep[x]>dep[y])swap(x,y);
        int tmp=dep[y]-dep[x];
        ll ans=0;
        for(int j=0;tmp;++j,tmp>>=1)
        {
            if(tmp&1)
            {
                ans+=cost[y][j];
                y=fa[y][j];
            }
        }
        if(x==y)return x;
        for(int i=30;i>=0&&y!=x;--i)
        {
            if(fa[x][i]!=fa[y][i])
            {
                ans+=cost[x][i]+cost[y][i];
                x=fa[x][i];
                y=fa[y][i];
            }
        }
        ans+=cost[x][0]+cost[y][0];
        return fa[x][0];
    }
    ll dis(int x,int y)
    {
        if(dep[x]>dep[y])swap(x,y);
        int tmp=dep[y]-dep[x];
        ll ans=0;
        for(int j=0;tmp;++j,tmp>>=1)
        {
            if(tmp&1)
            {
                ans+=cost[y][j];
                y=fa[y][j];
            }
        }
        if(x==y)return ans;
        for(int i=30;i>=0&&y!=x;--i)
        {
            if(fa[x][i]!=fa[y][i])
            {
                ans+=cost[x][i]+cost[y][i];
                x=fa[x][i];
                y=fa[y][i];
            }
        }
        ans+=cost[x][0]+cost[y][0];
        return ans;
    }
};
void solve()
{
  int n,m;
  cin>>n>>m;
  DSU dsu(n+1);
  vector<array<int,2>>E(n+1);
  LCA lca(n);
  for(int i=1;i<=m;++i)
  {
    int u,v;
    cin>>u>>v;
    int fau=dsu.fa(u),fav=dsu.fa(v);
    if(fau!=fav)//是最小生成树上的点
    {
        lca.add_edge(u,v,1);
        dsu.merge(fau,fav);
        continue;
    }
    E.push_back({u,v});
  }
  lca.dfs(1,0);
  vector<ll>sum(n+1,0);
  function<void(int,int)>dfs=[&](int now,int fa)
  {
    for(int v:lca.Edges[now])
    {
        if(v==fa)continue;
        sum[v]+=sum[now];
        dfs(v,now);
    }
  };
  for(auto[u,v]:E)
  {
    int fa=lca.commonFa(u,v);
    if(fa==u||fa==v)//situation 1 mark the ancester of t=son(son(u,v)) and  son(u,v) which t is a ancestor of son(u,v)
    {
        int t=fa^u^v;
        for(int i=20;i>=0;--i)
        {
            if(lca.dep[lca.fa[t][i]]>lca.dep[fa])t=lca.fa[t][i];
            sum[t]++;
            sum[fa^u^v]--;
        }
    }
    else//只有u，v及其之后的点满足要求
    {
        sum[1]++;
        sum[u]--;
        sum[v]--;
    }
  }
  dfs(1,1);
  for(int i=1;i<=n;++i)
  {
    cout<<(sum[i]==0?1:0);
  }
  cout<<'\n';
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