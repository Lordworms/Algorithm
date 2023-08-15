#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct edge {
  int u, v, w;
};
vector<ll> ans;
ll cur;
struct DSU {
    std::vector<ll> f, siz;
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
        cur += siz[x] * siz[y];
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[fa(x)]; }
};
struct node {
  int id, w;
};
void solve() {
  int n, m;
  cin >> n >> m;
  ans.resize(m + 1);
  vector<edge> E;
  vector<node>q(m + 1);
  DSU dsu(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    E.push_back({u, v, w});
  } 
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].w;
    q[i].id = i;
  }
  sort(E.begin(), E.end(), [&](edge a, edge b){
    return a.w < b.w;
  });
  sort(q.begin() + 1, q.end(), [&](node a, node b) {
    return a.w < b.w;
  });
  int last = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = last; j < E.size(); ++j) {
      if (E[j].w <= q[i].w) {
        dsu.merge(E[j].u, E[j].v);
        ++last;
      } else {
        break;
      }
    }
    ans[q[i].id] = cur;
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << " \n" [i == m];
  }
  return ;
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