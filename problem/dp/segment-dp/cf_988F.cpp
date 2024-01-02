#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 2e3 + 10;
const int INF = 0x3f3f3f3f;
int dp[N][N];
void solve() {
  int n, m, A, l, r, p, x;
  cin >> A >> n >> m;
  vector<int> covered(A + 1), id(A + 1), w(m + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> l >> r;
    for (int j = l + 1; j <= r; ++j) {
      covered[j] = 1;
    }
  }
  w[0] = INF;
  for (int i = 1; i <= m; ++i) {
    cin >> p >> w[i];
    if (w[i] < w[id[p]]) {
      id[p] = i;
    }
  }
  memset(dp[0], INF, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= A; ++i) {
    memset(dp[i], INF, sizeof(dp[i]));
    for (int j = 0; j <= m; ++j) {
      // option I: heading up if you have an umbrella
      if (j) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + w[j]);    
      }
      // option II: drop an umbrella if you have one and no rain here
      if (!covered[i]) {
        dp[i][0] = min(dp[i][0], dp[i - 1][j]);
      }
      // option III: switch an umbrella if got one
      if (id[i - 1]) {
        dp[i][id[i - 1]] = min(dp[i][id[i - 1]], dp[i - 1][j] + w[id[i - 1]]);  
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= m; ++i) {
    ans = min(ans, dp[A][i]);
  }
  if (ans == dp[0][1]) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
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
  while (T--) {
    solve();
  }
  return 0;
}