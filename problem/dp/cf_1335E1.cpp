#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, x;
  cin >> n;
  vector<int> a(n + 1);
  vector cnt(n + 1, vector<int>(27));
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    for (int j = 1;j <= 26; ++j) {
      cnt[i][j] = cnt[i-1][j] + (x == j);
    }
  }
  int ans = 0;
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      int x = 0, y = 0;
      for (int k = 1;k <= 26; ++k) {
        x = max(x, cnt[r][k] - cnt[l - 1][k]); //centroid
        y = max(y, 2 * min(cnt[n][k] - cnt[r][k], cnt[l - 1][k])); //two sides
      }
      ans = max(ans, x + y);
    }
  }
  cout << ans << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}