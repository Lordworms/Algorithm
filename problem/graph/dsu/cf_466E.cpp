#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
vector<vector<int>> E;
vector<int> f;
vector<int> dep;
vector<vector<int>> fa;
int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) f[x] = y;
}
void dfs(int x, int par) {
  dep[x] = dep[par] + 1;
  for (int &v : E[x]) {
    if (v == par) continue;
    fa[v][0] = x;
    for (int d = 1; (1 << d) <= dep[x]; ++d) {
      fa[v][d] = fa[fa[v][d - 1]][d - 1];
    }
    dfs(v, x);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  for (int d = 19; d >= 0; --d) {
    if (dep[fa[x][d]] >= dep[y]) {
      x = fa[x][d];  // lower point jumping up
    }
  }
  if (x == y) {
    return x;
  }
  for (int d = 19; d >= 0; --d) {
    if (fa[x][d] != fa[y][d]) {
      x = fa[x][d], y = fa[y][d];
    }
  }
  return fa[x][0];
}
void solve() {
  int n, m, type, x, y, i;
  cin >> n >> m;
  E.resize(n + 1);
  f.resize(n + 1);
  dep.resize(n + 1);
  fa.assign(n + 1, vector<int>(30));
  vector<pair<int, int>> doc;
  vector<pair<int, int>> query;
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = 1; i <= m; ++i) {
    cin >> type;
    switch (type) {
      case 1: {
        cin >> x >> y;
        E[y].push_back(x);
        merge(x, y);
        fa[x][0] = y;
        break;
      }
      case 2: {
        cin >> x;
        doc.push_back(make_pair(x, find(x)));
        break;
      }
      case 3: {
        cin >> x >> y;
        query.push_back(make_pair(x, y));
        break;
      }
      default:
        break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (f[i] == i) {
      dfs(i, 0);
    }
  }
  for (int i = 0; i < query.size(); ++i) {
    int cur = query[i].first, tar = query[i].second;
    int st = doc[tar - 1].first, ed = doc[tar - 1].second;
    int f1 = lca(cur, st), f2 = lca(cur, ed);
    if (lca(cur, st) == cur && lca(cur, ed) == ed) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
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