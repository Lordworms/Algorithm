#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
void solve() {
  int n, m;
  cin >> n >> m;
  vector dp(n + 1, vector<ll>(m + 1));
  vector d(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> d[i][j];
    }
  }
  vector<ll> sum(m + 1);
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      ll cur_max = -INF;
      for (int j = 1; j <= m; ++j) {
        sum[j] = sum[j - 1] + d[i][j];
        dp[i][j] = cur_max + sum[j];
        cur_max = max(cur_max, dp[i - 1][j]);
      }
    } else {
      ll cur_max = -INF;
      for (int j = 1; j <= m; ++j) {
        sum[j] = sum[j - 1] + d[i][j];
      }
      for (int j = m; j >= 1; --j) {
        dp[i][j] = cur_max + sum[j];
        cur_max = max(cur_max, dp[i - 1][j]);
      }
    }
  }
  ll ans = -INF;
  for (int j = 1; j <= m; ++j) {
    ans = max(ans, dp[n][j]);
  }
  cout << ans << '\n';
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