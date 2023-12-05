#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>> E(n + 1);
  vector<int> want(n + 1), has(n + 1);
  bool is_valid = true;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
    has[v]++;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> want[i];
  }
  vector<int> ans;
  function<void(int, int)> dfs = [&] (int x, int f) {
    for (int &v : E[x]) {
      if (v == f) continue;
      if (want[x] != want[v] && want[v] != v) {
        is_valid = false;
      }
      dfs(v, x);
    }
    if (want[x] == x) {
      ans.push_back(x);
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (!has[i]) {
      dfs(i, 0);
    }
  }
  if (!is_valid) {
    cout << -1 << '\n';
  } else {
    cout << ans.size() << '\n';
    for (auto &k : ans) {
      cout << k << '\n';
    }
    cout << '\n';
  }
  return;

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt", "r", stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt", "w", stdout);
#endif
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}