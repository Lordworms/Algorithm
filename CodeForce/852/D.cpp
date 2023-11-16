#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int MOD = 1e9+7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), ida(a), idb(b);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ida[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    idb[b[i]] = i;
  }
  int l = n + 1, r = 0;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int p1 = ida[i], p2 = idb[i];
    if (p1 > p2) {
      swap(p1, p2);
    }
    if (i == 1) { // i == 1 would split the whole sequence into three parts
      ans += p1 * (p1 - 1) / 2;
      ans += (p2 - p1 - 1) * (p2 - p1) / 2;
      ans += (n - p2) * (n - p2 + 1) / 2;
    } else if (p1 < l && p2 > r) { // case 1 could only apply to the cross part
      ans += max(1ll, l - p1) * max(1ll, p2 - r);
    } else if (p2 < l) {
      ans += (l - p2) * (n - r + 1); 
    } else if (p1 > r) {
      ans += (p1 - r) * l;
    }
    l = min(l, p1);
    r = max(r, p2);
  }
  cout << ans + 1 << '\n';
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