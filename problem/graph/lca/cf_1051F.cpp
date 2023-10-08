/**
 * for those points which are on the tree, do dis[x] + dis[y] - 2 * dis[LCA(x,
 * y)];
 * for those points which are not on the tree, do Dijistra
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
vector<vector<int>> E, cost;
struct Query {
  int u, v;
  ll ans;
};
struct edge {
  int from, to, w;
  bool operator<(const edge &a) const { return a.w > w; }
};
struct node {
  int u;
  ll dis;
  bool operator<(const node &a) const { return a.dis < dis; }
};
vector<set<int>> invalid;
int n, m;
vector<vector<int>> fa;
vector<int> f, dep, vis;
vector<ll> dis, DIS;
int lca(int x, int y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  for (int d = 19; d >= 0; --d) {
    if (dep[fa[x][d]] >= dep[y]) {
      x = fa[x][d];
    }
  }
  if (x == y) {
    return x;
  }
  // jump to some position that fa[x][d] == fa[y][d]
  for (int d = 19; d >= 0; --d) {
    if (fa[x][d] != fa[y][d]) {
      x = fa[x][d], y = fa[y][d];
    }
  }
  return fa[x][0];
}
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    f[x] = y;
  }
}
void dfs(int x, int par) {
  dep[x] = dep[par] + 1;
  for (int i = 0; i < E[x].size(); ++i) {
    int v = E[x][i], c = cost[x][i];
    if (v == par || invalid[x].find(i) != invalid[x].end()) continue;
    fa[v][0] = x, DIS[v] = DIS[x] + c;
    for (int d = 1; (1 << d) <= dep[x]; ++d) {
      fa[v][d] = fa[fa[v][d - 1]][d - 1];
    }
    dfs(v, x);
  }
}
void dijkstra(int s) {
  for (int i = 1; i <= n; ++i) {
    dis[i] = 1e18;
    vis[i] = 0;
  }
  priority_queue<node> q;
  q.push({s, 0});
  dis[s] = 0;
  while (!q.empty()) {
    auto tmp = q.top();
    q.pop();
    int u = tmp.u;
    vis[u] = 1;
    for (int i = 0; i < E[u].size(); ++i) {
      int v = E[u][i], c = cost[u][i];
      if (!vis[v] && dis[v] > dis[u] + c) {
        dis[v] = dis[u] + c;
        q.push({v, dis[v]});
      }
    }
  }
}
void solve() {
  // m - n < 20
  cin >> n >> m;
  invalid.resize(n + 1);
  vector<edge> Edge(m + 1);
  E.resize(n + 1), cost.resize(n + 1);
  f.resize(n + 1), fa.resize(n + 1);
  dis.resize(n + 1), DIS.resize(n + 1);
  vis.resize(n + 1), dep.resize(n + 1);
  fa.assign(n + 1, vector<int>(30, 0));
  iota(f.begin(), f.end(), 0);
  for (int i = 1; i <= m; ++i) {
    cin >> Edge[i].from >> Edge[i].to >> Edge[i].w;
  }
  sort(Edge.begin() + 1, Edge.end());
  int cnt = 0, u, v, w;
  vector<int> flag(m + 1);
  // building trees
  for (int i = 1; i <= m; ++i) {
    u = Edge[i].from;
    v = Edge[i].to;
    w = Edge[i].w;
    if (find(u) != find(v)) {
      merge(u, v);
    } else {
      flag[i] = 1;
      invalid[u].insert(E[u].size());
      invalid[v].insert(E[v].size());
    }
    E[u].push_back(v);
    E[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);
  }
  for (int i = 1; i <= n; ++i) {
    if (f[i] == i) {
      dfs(i, 0);
    }
  }
  int q;
  cin >> q;
  vector<Query> query(q + 1);
  for (int i = 1; i <= q; ++i) {
    cin >> query[i].u >> query[i].v;
    int com = lca(query[i].u, query[i].v);
    query[i].ans = DIS[query[i].u] + DIS[query[i].v] - 2 * DIS[com];
  }
  for (int i = 1; i <= m; ++i) {
    if (flag[i]) {
      dijkstra(Edge[i].from);
      for (int j = 1; j <= q; ++j) {
        query[j].ans = min(query[j].ans, dis[query[j].u] + dis[query[j].v]);
      }
    }
  }
  for (int i = 1; i <= q; ++i) {
    cout << query[i].ans << '\n';
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}