#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define int ll
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  } 
  sort(a.begin() + 1, a.end());
  vector dp(n + 1, vector<int>(n + 1));
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + a[r] - a[l];
    }
  }
  cout << dp[1][n] << '\n';
  return ;
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