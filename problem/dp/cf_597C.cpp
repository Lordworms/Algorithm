#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int MOD = 1e9+7;
const int MAXN = 1e5 + 10;
const int K = 20;
int dp[MAXN][K];
#define lowbit(x) (x & -x)
void add(int x, int y, int v) {
  while (x < MAXN) {
    dp[x][y] += v;
    x += lowbit(x);
  }
}
int sum(int x, int y) {
  int res = 0;
  while (x) {
    res += dp[x][y];
    x -= lowbit(x);
  }
  return res;
}
void solve() {
  /* 
    dp[i][j][k] = sigma_{0}^{a[j]} dp[i - 1][j][k - 1];
  */
  int n, K;
  cin >> n >> K; ++K;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min(i + 1, K); ++j) {
      if (j == 1) {
        add(a[i], 1, 1);
      } else {
        add(a[i], j, sum(a[i] - 1, j - 1)); 
      }
    }
  }
  cout << sum(n, K) << '\n';
  return;
}
signed main() {
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