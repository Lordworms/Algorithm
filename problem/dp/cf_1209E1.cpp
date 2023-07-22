#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  vector mp(n + 1, vector<int>(m + 1));
  vector dp(m + 1, vector<int>(25));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> mp[i][j];
  for (int i = 1; i <= m; ++i) {
    for (int s = 0; s < (1 << n); ++s) {
      for (int iter = 1; iter <= n; ++iter) {
        int val = 0;
        for (int j = 1; j <= n; ++j) {
          if (s & (1 << j - 1)) {
            val += mp[j][i];
          }
        }
        for (int p = 0; p < (1 << n); ++p) {
          if (!(s & p)) {
            dp[i][s | p] = max(dp[i][s | p], dp[i - 1][p] + val);
          }
        }
        for (int j = 1; j <= n; ++j) {
          mp[j - 1][i] = mp[j][i];
        }
        mp[n][i] = mp[0][i];
      }
    }
  }
  cout << dp[m][(1 << n) - 1] << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}