#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    dp[i][i + 1] = 1 + (a[i] != a[i + 1]);
  }
  for (int len = 3; len <= n; ++len) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      if (a[l] == a[r]) dp[l][r] = dp[l + 1][r - 1];
      for (int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
      }
    }
  }
  cout << dp[1][n] << '\n';
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