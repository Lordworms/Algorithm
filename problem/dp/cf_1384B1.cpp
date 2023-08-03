#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, k ,l;
  cin >> n >> k >> l; 
  int N = n * k + n;
  int mod = 2 * k;
  vector<int> p(2 * k + 3);
  vector<int> d(n + 1);
  iota(p.begin(), p.begin() + k + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> d[i];
  // p = [0, 1, 2, ... k - 1, k, k - 1, .... 1]
  for (int i = k + 1; i <= 2 * k; ++i) {
    p[i] = 2 * k - i;
  }
  vector dp(N + 1, vector<int>(n + 1));
  for (int i = 0; i <= N; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = 0;
      if (d[j] + p[i % mod] <= l) {
        dp[i][j] = dp[i - 1][j] | dp[i - 1][j - 1];
      }
    }
    if (dp[i][n]) {
      cout << "Yes" << '\n';
      return;
    }
  }
  cout << "No" << '\n';
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in","r",stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out","w",stdout);
#endif
  int T = 1; 
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}