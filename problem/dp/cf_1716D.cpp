#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 2e5 + 20;
ll dp[2][MAXN], pre[MAXN];
#define int ll
void solve() {
  int n, k;
  cin >> n >> k;
  int begin = 0, kk = k, m = 0;
  while (begin <= n) {
    begin += kk;
    kk++;
    m++;
  }
  vector<ll> ans(n + 1);
  int c, p;
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    c = i & 1, p = c ^ 1;
    memset(pre, 0,sizeof(pre));
    for (int j = 0; j <= n; ++j) {
      if (j >= (i + k - 1)) {
        pre[j] = (pre[j - (i + k - 1)] + dp[p][j]) % MOD;
      } else {
        pre[j] = dp[p][j];
      }
    }
    for (int j = 0; j <= n; ++j) {
      if (j >= (i + k - 1)) {
        dp[i & 1][j] = (dp[c][j] + pre[j - (i + k - 1)]) % MOD;
      }
    }
    for (int j = 1; j <= n; ++j) {
      ans[j] = (ans[j] + dp[c][j]) % MOD;
    }
    memset(dp[p], 0, sizeof(dp[p]));
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] <<  " \n" [i == n];
  }
  return;
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