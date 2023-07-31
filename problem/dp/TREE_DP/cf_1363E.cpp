#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define int ll
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), c(n + 1);
  vector dp(n + 1, vector<int>(2));
  vector<vector<int>> E(n + 1);
  ll s1 = 0, s2 = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    s1 += b[i], s2 += c[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  if (s1 != s2) {
    cout << -1 << '\n';
    return;
  }
  ll ans = 0;
  function <void(int, int)> dfs = [&](int x, int f) {
    if (x != 1) {
      a[x] = min(a[x], a[f]);
    }
    dp[x][b[x]] += (b[x] != c[x]);
    for (int v: E[x]) {
      if (v == f) continue;
      dfs(v, x);
      dp[x][0] += dp[v][0];
      dp[x][1] += dp[v][1];
    }
    int cur_min = min(dp[x][0], dp[x][1]);
    ans += cur_min * a[x] * 2;
    dp[x][0] -= cur_min;
    dp[x][1] -= cur_min;
  };
  dfs(1, -1);
  cout << ans << '\n';
  return;
}
signed main() {
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