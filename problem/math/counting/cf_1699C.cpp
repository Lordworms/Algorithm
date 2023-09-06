#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), pos(n);
  for (int i = 0; i <= n - 1; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int l = pos[0], r = pos[0];
  ll ans = 1;
  for (int i = 1; i <= n - 1; ++i) {
    if (pos[i] < l) {
      l = pos[i];
    } else if (pos[i] > r) {
      r = pos[i];
    } else {
      ans = ans * (r - l + 1 - i) % MOD;
    }
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}