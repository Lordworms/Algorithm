#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, m, l, r;
  cin >> n >> m;
  vector<int> p(n + 1), pos(n + 1), farest(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  ll ans = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r;
    int a = max(pos[l], pos[r]), b = min(pos[l], pos[r]);
    farest[a] = max(farest[a], b);
  }
  l = 0;
  for (int i = 1; i <= n; ++i) {
    l = max(farest[i], l);
    ans += i - l;
  }
  cout << ans << '\n';
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