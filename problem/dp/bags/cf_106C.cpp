#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, m, c0, d0;
  /*
    multi-pack problem
    we have some options here
    I. build this bread with stuffing
    II. build this bread without stuffing
    III. do not build this bread
  */
  cin >> n >> m;
  vector<int> a(m + 2), b(m + 2), c(m + 2), d(m + 2);
  cin >> c[1] >> d[1];
  for (int i = 2; i <= m + 1; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  int ans = 0;
  vector dp(m + 2, vector<int>(n + 1));
  for (int i = 1; i <= m + 1; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k * b[i] <= a[i] && k * c[i] <= j; ++k) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * c[i]] + d[i] * k);
        ans = max(dp[i][j], ans);
      }
    }
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