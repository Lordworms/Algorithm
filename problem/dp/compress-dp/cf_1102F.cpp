#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1 << 30;
const int N = 18;
const int M = 1e4 + 10;
int dp[1 << N][N];  // dp[i][j] means the current row status is i and the last
                    // row is row j
void solve() {
  int n, m;
  cin >> n >> m;
  vector mp(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mp[i][j];
    }
  }
  vector h(n + 1, vector<int>(n + 1)), g(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      h[i][j] = g[i][j] = INF;
      for (int k = 1; k <= m; ++k) {
        g[i][j] = min(g[i][j], abs(mp[i][k] - mp[j][k]));
      }
      for (int k = 2; k <= m; ++k) {
        h[i][j] = min(h[i][j], abs(mp[i][k - 1] - mp[j][k]));
      }
    }
  }
  int ans = 0;
  for (int k = 0; k < n; ++k) {
    memset(dp, 0, sizeof(dp));
    dp[1 << k][k] = INF;  // the primary position vallue is INF
    for (int S = 0; S < (1 << n); ++S) {
      for (int i = 0; i < n; ++i) {
        if (S & (1 << i)) {
          for (int j = 0; j < n; ++j) {
            if (!(S & (1 << j))) {
              dp[S | (1 << j)][j] =
                  max(dp[S | (1 << j)][j], min(dp[S][i], g[i][j]));
            }
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        ans = max(min(dp[(1 << n) - 1][i], h[k][i]), ans);
      }
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