#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
#define lowbit(x) (x & -x)
int n;
#define int ll
struct finwick {
  ll sum[N];
  finwick() { memset(sum, 0, sizeof(sum)); }
  void add(int x, int v) {
    while (x <= n) {
      sum[x] += v;
      x += lowbit(x);
    }
  }
  ll query(int x) {
    ll res = 0;
    while (x) {
      res += sum[x];
      x -= lowbit(x);
    }
    return res;
  }
};
void solve() {
  cin >> n;
  finwick t;
  vector<int> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    t.add(i, i);
  }
  vector<ll> ans(n + 1);
  for (int i = n; i >= 1; --i) {
    int l = 1, r = n, mid;
    ll cur = 0;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (t.query(mid - 1) <= s[i]) {
        l = mid + 1;
        cur = mid;
      } else {
        r = mid - 1;
      }
    }
    ans[i] = cur;
    t.add(cur, -cur);
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }
  return;
}
signed main() {
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