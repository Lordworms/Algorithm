#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
struct node {
  int x, y;
};
void solve() {
  int n;
  cin >> n;
  vector<node> a(n + 1);
  vector<ll> fac(n + 1);
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  ll ans1 = 0, ans2 = 0;
  // calculate number of first increasing shit
  sort(a.begin() + 1, a.end(),
       [&](node a, node b) { return a.x == b.x ? a.y < b.y : a.x < b.x; });
  int l = 1;
  ll total1 = 1;
  while (l <= n) {
    ll len = 1;
    while (l + 1 <= n && a[l + 1].x == a[l].x) {
      ++l;
      ++len;
    }
    total1 = total1 * fac[len] % MOD;
    ++l;
  }
  // calculate number of second increasing shit
  sort(a.begin() + 1, a.end(), [&](node a, node b) { return a.y < b.y; });
  ll total2 = 1;
  l = 1;
  while (l <= n) {
    ll len = 1;
    while (l + 1 <= n && a[l + 1].y == a[l].y) {
      ++l;
      ++len;
    }
    total2 = total2 * fac[len] % MOD;
    ++l;
  }
  ll extra = 1;
  sort(a.begin() + 1, a.end(),
       [&](node a, node b) { return a.x == b.x ? a.y < b.y : a.x < b.x; });
  bool need_continue = true;  
  for (int i = 2; i <= n; ++i) {
    if (a[i].y < a[i - 1].y) {
      need_continue = false;
      extra = 0;
    }
  }
  if (need_continue) {
    l = 1;
    while (l <= n) {
      ll len = 1;
      while (l + 1 <= n && a[l + 1].x == a[l].x && a[l + 1].y == a[l].y) {
        ++l;
        ++len;
      }
      extra = extra * fac[len] % MOD;
      ++l;
    }
  }
  ll ans = (total1 + total2 - extra + MOD) % MOD;
  cout << (fac[n] - ans + MOD) % MOD << '\n';
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