#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
#define int ll
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), dp(n + 1);
  for (int i = 1; i <= n - 1; ++i) cin >> a[i];
  dp[1] = 1;
  for (int i = 1; i <= n - 1; ++i) {
    dp[i + 1] = dp[i] * (i - a[i]) % MOD;
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    ans = (ans * i + !a[i] * dp[i]) % MOD;
    cout << ans << " \n" [i == n - 1];
  }
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}