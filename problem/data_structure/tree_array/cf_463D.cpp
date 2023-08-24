#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, K;
  cin >> n >> K;
  vector<vector<int>> pos(K + 1, vector<int>(n + 1)), a(pos);
  for (int i = 1; i <= K; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      pos[i][a[i][j]] = j;
    }
  } 
  vector<int> dp(n + 1, 1);
  int ans = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      bool flag = true;
      for (int k = 2; k <= K; ++k) {
        if (pos[k][a[1][j]] > pos[k][a[1][i]]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
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