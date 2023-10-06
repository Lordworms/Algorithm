#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
unordered_map<int, int> f[MAXN];
map<pair<int, int>, int> ans;
void solve() {
  function<int(int, int)> find = [&] (int x, int c) {
    int tmp = x;
    while (f[x][c]) x = f[x][c];
    while (f[tmp][c]) {
      int cur = tmp;
      tmp = f[tmp][c];
      f[cur][c] = x;
    }
    return x;
  };
  function<void(int, int, int)> merge = [&] (int x, int y, int c) {
    int fx = find(x, c), fy = find(y, c);
    if (fx != fy) {
      f[fx][c] = fy;
    }
  };
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    merge(u, v, c);
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (ans[make_pair(u, v)]) {
      cout << ans[make_pair(u, v)] << '\n';
      continue;
    }
    int sum = 0;
    if (f[u].size() > f[v].size()) swap(u, v);
    for (auto it = f[u].begin(); it != f[u].end(); ++it) {
      int c = it -> first;
      if (find(u, c) == find(v, c) && f[v].count(c)) {
        ++sum;
      }
    }
    cout << sum << '\n';
    ans[make_pair(u,v)] = sum;
    ans[make_pair(v,u)] = sum;
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