#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 2e6 + 10;
void solve() {
  int T;
  cin >> T;
  int n;
  vector<ll> dp(N);
  for (int i = 3; i < N; ++i) {
    dp[i] = (2ll * dp[i - 2] + dp[i - 1] + (i % 3 == 0)) % MOD;
  }
  while (T--) {
    cin >> n;
    cout << 4ll * dp[n] % MOD << '\n';
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