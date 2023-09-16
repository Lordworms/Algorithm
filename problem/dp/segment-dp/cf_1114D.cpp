#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int pre = 0;
void solve() {
  int n;
  cin >> n;
  vector<int> a;
  a.push_back(0);
  int x;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (x != pre) {
      a.push_back(x);
    }
    pre = x;
  }
  n = a.size() - 1;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = 0;
  } 
  for (int i = 1; i < n; ++i) {
    dp[i][i + 1] = (a[i] != a[i + 1]);
  }
  for (int len = 3; len <= n; ++len) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      if (a[l] == a[r]) {
        dp[l][r] = dp[l + 1][r - 1] + 1;
      } else {
        dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
      }
    }
  }
  cout << dp[1][n] << '\n';
  return ;
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