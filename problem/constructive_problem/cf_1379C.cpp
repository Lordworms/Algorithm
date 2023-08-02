#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
#define int ll
struct node {
  ll a, b;
};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<node> a(m + 1);
  ll cur_max = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].a >> a[i].b;
    cur_max = max(a[i].a, cur_max);
  }
  sort(a.begin() + 1, a.begin() + m + 1, [&](node a, node b) {
    if (a.a == b.a) return a.b > b.b;
    return a.a > b.a;
  });
  vector<ll> sum(m + 1), current(N);

  for (int i = 1; i <= m; ++i) {
    sum[i] = sum[i - 1] + a[i].a;
    current[i] = a[i].a;
  }
  ll ans = 0;
  for (int i = 1; i <= m; ++i) {
    int pos = lower_bound(current.begin() + 1, current.begin() + 1 + m, a[i].b, greater<int>()) - current.begin();
    --pos;
    if (pos > n) {
      ans = max(ans, sum[n]);
    } else if (pos < i) {
      ans = max(ans, sum[pos] + a[i].a + (n - pos - 1) * a[i].b);
    } else {
      ans = max(ans, (n - pos) * a[i].b + sum[pos]);
    }
  }
  cout << ans << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}