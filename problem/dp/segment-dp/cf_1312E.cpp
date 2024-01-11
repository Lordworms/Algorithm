#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  vector dp(n + 1, vector<int> (n + 1, INF)), a(dp);
  for (int i = 1; i <= n; ++i) cin >> a[i][i];
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = 1;
  }
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
      for (int k = l; k <= r - 1; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
        if (dp[l][k] == 1 && a[l][k] == a[k + 1][r] && dp[k + 1][r] == 1) {
          a[l][r] = a[l][k] + 1; 
          dp[l][r] = 1;
        }
      }
    }
  }
  cout << dp[1][n] << '\n';
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