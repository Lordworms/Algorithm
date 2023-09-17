#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 5e6 + 10;
const int S = (1 << 22) - 1;
void solve() {
  int n;
  cin >> n;
  vector<int> dp(N);  // dp[i] represent the integer such that i ^ a[i] = S;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    dp[S ^ a[i]] = a[i];
  }
  for (int sta = S; sta >= 0; --sta) {
    if (dp[sta]) continue;
    for (int i = 0; i < 22; ++i) {
      if (dp[sta | (1 << i)]) {
        // think about it, it's very easy
        dp[sta] = dp[sta | (1 << i)];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << (dp[a[i]] ? dp[a[i]] : -1) << " ";
  }
  return;
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