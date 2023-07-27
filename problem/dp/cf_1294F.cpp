#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
using pii = pair<int, int>;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n + 1);
  for (int i = 1; i <= n; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  int c = 0, st = 0, ed = 0;
  vector<int> dis(n + 1), bef(n + 1);
  // find diameter
  function<void(int)> dfs = [&](int x) {
    c = dis[x] > dis[c] ? x : c;
    for (int v : E[x]) {
      if (v == bef[x]) continue;
      dis[v] = dis[x] + 1;
      bef[v] = x;
      dfs(v);
    }
  };
  dfs(1);
  st = c;
  dis[st] = 0;
  bef[st] = -1;
  dfs(st);
  ed = c;
  queue<pii> q;
  vector<int> vis(n + 1);
  while (c != -1) {
    q.push({c, 0});
    vis[c] = 1;
    c = bef[c];
  }
  int d, x, extra = 0, p = bef[ed];
  while (!q.empty()) {
    x = q.front().first;
    d = q.front().second;
    q.pop();
    if (d > extra) {
      p = x;
      extra = d;
    }
    for (int v : E[x]) {
      if (vis[v]) {
        continue;
      }
      q.push({v, d + 1});
      vis[v] = 1;
    }
  }
  cout << extra + dis[ed] << '\n';
  cout << st << ' ' << ed << ' ' << p << '\n';
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