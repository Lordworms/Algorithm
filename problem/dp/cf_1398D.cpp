#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 210;
ll dp[N][N][N];
void solve() {
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<int> a(n1 + 1), b(n2 + 1), c(n3 + 1);
  for (int i = 1; i <= n1; ++i) cin >> a[i];
  for (int i = 1; i <= n2; ++i) cin >> b[i];
  for (int i = 1; i <= n3; ++i) cin >> c[i];
  sort(a.begin() + 1, a.end(), greater<int>());
  sort(b.begin() + 1, b.end(), greater<int>());
  sort(c.begin() + 1, c.end(), greater<int>());
  ll ans = 0;
  for (int i = 0; i <= n1; ++i) {
    for (int j = 0; j <= n2; ++j) {
      for (int k = 0; k <= n3; ++k) {
        ll t = 0;
        if (i != 0 && j != 0) {
          t = max(t, dp[i - 1][j - 1][k] + a[i] * b[j]);
        }
        if (j != 0 && k != 0) {
          t = max(t, dp[i][j - 1][k - 1] + b[j] * c[k]);
        }
        if (i != 0 && k != 0) {
          t = max(t, dp[i - 1][j][k - 1] + a[i] * c[k]);
        }
        dp[i][j][k] = max(dp[i][j][k], t);
        ans = max(ans, dp[i][j][k]);
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