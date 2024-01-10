#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector dp(n + 1, vector<int>(k + 1));
  int ans = 0;
  /*
    dp[i][j] means the number of nodes that could be
  */
  vector<int> sz(n + 1);
  function<void(int, int, int)> dfs = [&](int x, int f, int d) {
    dp[x][d % k] = sz[x] = 1;
    for (int &v : E[x]) {
      if (v == f) continue;
      dfs(v, x, d + 1);
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
          int dis = ((i + j) % k - (2 * d % k) + k) % k;
          ans += dp[x][i] * dp[v][j] * ((k - dis + k + k) % k);
        }
      }
      for (int i = 0; i < k; ++i) {
        dp[x][i] += dp[v][i];
      }
      ans += sz[v] * (n - sz[v]);
      sz[x] += sz[v];
    }
  };
  dfs(1, 0, 0);
  cout << ans / k << '\n';
  return;
}
signed main() {
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