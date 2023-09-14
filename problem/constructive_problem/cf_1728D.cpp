#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  s = ')' + s;
  auto check = [&](char x, char y) {
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
  };
  vector dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i < n; ++i) {
    dp[i][i + 1] = (s[i] == s[i + 1]) ? 0 : 1;
  }
  int f1, f2, f3, f4;
  for (int len = 4; len <= n; len += 2) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      dp[l][r] = -1;
      // case 1: Alice pick up s[l], Bob pick up s[l + 1]
      f1 = dp[l + 2][r] == 0 ? check(s[l], s[l + 1]) : dp[l + 2][r]; 
      // case 2: Alice pick up s[l], Bob pick up s[r]
      f2 = dp[l + 1][r - 1] == 0 ? check(s[l], s[r]) : dp[l + 1][r - 1];
      // case 1: Alice pick up s[r], Bob pick up s[r - 2]
      f3 = dp[l][r - 2] == 0 ? check(s[r], s[r - 1]) : dp[l][r - 2];
      // case 1: Alice pick up s[r], Bob pick up s[l]
      f4 = dp[l + 1][r - 1] == 0 ? check(s[r], s[l]) : dp[l + 1][r - 1];
      dp[l][r] = max(min(f1, f2), min(f3, f4));
    }
  }
  if (dp[1][n] == 1) {
    cout << "Alice" << '\n';
  } else if (dp[1][n] == -1) {
    cout << "Bob" << '\n';
  } else {
    cout << "Draw" << '\n';
  }
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}