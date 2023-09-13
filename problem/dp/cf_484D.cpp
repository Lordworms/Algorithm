/*
    we could prove that every group is monotonically increasing otherwise, we could always construct a better result
    than the current one

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<ll> dp(n + 1);
  auto check = [&] (int i) {
    return (a[i] > a[i - 1] && a[i - 1] > a[i - 2]) || (a[i] < a[i - 1] && a[i - 1] < a[i - 2]); 
  };
  dp[1] = 0, dp[2] = abs(a[2] - a[1]);
  for (int i = 3; i <= n; ++i) {
    if (check(i)) {
      dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
    } else {
      dp[i] = max(dp[i - 1], dp[i - 2] + abs(a[i] - a[i - 1]));
    }
  } 
  cout << dp[n] << '\n';
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