#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  int l = 1, r = n;
  vector<vector<int>> a(n + 2, vector<int>(3)), dp(a);
  for (int j = 0; j < 2; ++j) {
    for (int i = 1; i <= n; ++i) {
      char c;
      cin >> c;
      a[i][j] = (c == '*' ? 1 : 0);
    }
  }
  while (!a[l][0] && !a[l][1]) ++l;
  while (!a[r][0] && !a[r][1]) --r;
  for (int i = l; i <= r; ++i) {
    dp[i][0] = min(dp[i - 1][0] + 1 + a[i][1], dp[i - 1][1] + 2);
    dp[i][1] = min(dp[i - 1][1] + 1 + a[i][0], dp[i - 1][0] + 2);
  }
  cout << min(dp[r][0], dp[r][1]) - 1 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
