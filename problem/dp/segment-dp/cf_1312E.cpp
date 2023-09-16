#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 510;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> dp(N, vector<int>(N)), a(dp);
  // when a range is length 1, the answer is absolutely 1
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][i];
    dp[i][i] = 1;
  }
  // we initialize the value of a range to be j - i + 1
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      dp[i][j] = j - i + 1;
    }
  }
  // when left and right length is 1 and the value is 1 we could do the merge
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      for (int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
        if (dp[l][k] == 1 && dp[k + 1][r] == 1 && a[l][k] == a[k + 1][r]) {
          dp[l][r] = 1, a[l][r] = a[l][k] + 1; 
        }
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