#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a[n] = "fuck you bitch";
  bool sign = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][0] != a[i][j] || a[i][0] == a[i + 1][0]) {
        sign = true;
        break;
      }
    }
    if (sign) {
      break;
    }
  }
  cout << (sign ? "NO" : "YES") << '\n';
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