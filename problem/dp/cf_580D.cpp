#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<vector<ll>> dp(n,
                        vector<ll>(1 << n));  // the status is sta and ends in i
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    dp[i][1 << i] = a[i];
  }
  int u, v, c;
  vector<vector<int>> mp(n, vector<int>(n));
  for (int i = 0; i < k; ++i) {
    cin >> u >> v >> c;
    --u, --v;
    mp[u][v] = c;
  }
  for (int sta = 0; sta < (1 << n); ++sta) {
    for (int i = 0; i < n; ++i) {
      if (!(sta & (1 << i))) continue;
      for (int j = 0; j < n; ++j) {
        if (i == j || !(sta & (1 << j))) continue;
        dp[i][sta] = max(dp[i][sta], dp[j][sta ^ (1 << i)] + mp[j][i] + a[i]);
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < (1 << n); ++i) {
    if (__builtin_popcount(i) != m) {
      continue;
    }
    for (int j = 0; j < n; ++j) {
      ans = max(ans, dp[j][i]);
    }
  }
  cout << ans << '\n';
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