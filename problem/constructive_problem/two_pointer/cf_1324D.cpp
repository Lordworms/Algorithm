#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
#define int ll
void solve() {
  int n, x;
  cin >> n;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    c[i] -= x;
  }
  sort(c.begin() + 1, c.end());
  int ans = 0;
  for (int l = 1, r = n; l <= n; ++l) {
    while (r > 1 && c[l] + c[r] > 0) --r;
    ans += n - max(r, l);
  }
  cout << ans << '\n';
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