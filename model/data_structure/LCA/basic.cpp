#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// starts with index 1;倍增版lca
struct LCA {
  int n;
  const int MAXN = 1e5 + 10;
  vector<vector<int>> Edges, fa, w, cost;
  vector<int> dep;
  LCA(int num) : n(num) {
    Edges.resize(num + 1);
    fa.resize(num + 1, vector<int>(32, 0));
    cost.resize(num + 1, vector<int>(32, 0));
    w.resize(num + 1);
    dep.resize(num + 1);
  }
  void add_edge(int u, int v, int c) {
    Edges[u].push_back(v);
    Edges[v].push_back(u);
    w[u].push_back(c);
    w[v].push_back(c);
  }
  void dfs(int now, int f) {
    fa[now][0] = f;
    dep[now] = dep[f] + 1;
    for (int i = 1; i < 31; ++i) {
      fa[now][i] = fa[fa[now][i - 1]][i - 1];
      cost[now][i] = cost[fa[now][i - 1]][i - 1] + cost[now][i - 1];
    }
    int sz = Edges[now].size();
    for (int i = 0; i < sz; ++i) {
      if (Edges[now][i] == f) continue;
      cost[Edges[now][i]][0] = w[now][i];
      dfs(Edges[now][i], now);
    }
  }
  int commonFa(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    int tmp = dep[y] - dep[x];
    ll ans = 0;
    for (int j = 0; tmp; ++j, tmp >>= 1) {
      if (tmp & 1) {
        ans += cost[y][j];
        y = fa[y][j];
      }
    }
    if (x == y) return x;
    for (int i = 30; i >= 0 && y != x; --i) {
      if (fa[x][i] != fa[y][i]) {
        ans += cost[x][i] + cost[y][i];
        x = fa[x][i];
        y = fa[y][i];
      }
    }
    ans += cost[x][0] + cost[y][0];
    return fa[x][0];
  }
  ll dis(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    int tmp = dep[y] - dep[x];
    ll ans = 0;
    for (int j = 0; tmp; ++j, tmp >>= 1) {
      if (tmp & 1) {
        ans += cost[y][j];
        y = fa[y][j];
      }
    }
    if (x == y) return ans;
    for (int i = 30; i >= 0 && y != x; --i) {
      if (fa[x][i] != fa[y][i]) {
        ans += cost[x][i] + cost[y][i];
        x = fa[x][i];
        y = fa[y][i];
      }
    }
    ans += cost[x][0] + cost[y][0];
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt", "r", stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt", "w", stdout);
#endif
  return 0;
}