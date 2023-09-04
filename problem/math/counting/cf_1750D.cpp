#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  bool flag = false;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i > 1 && a[i - 1] % a[i] != 0) {
      flag = true;
    }
  }
  if (flag) {
    cout << 0 << '\n';
    return;
  }
  ll ans = 1;
  for (int i = 2; i <= n; ++i) {
    ll cur = a[i - 1] / a[i], total = 0, lim = m / a[i], len;
    vector<ll> fac;
    for (int f = 2; f * f <= cur; ++f) {
      if (cur % f == 0) {
        len = fac.size();
        for (int j = 0; j < len; ++j) {
          fac.push_back(-fac[j] * f);
        }
        fac.push_back(f);
        while (cur % f == 0) cur /= f;
      }
    }
    if (cur > 1) {
      len = fac.size();
      for (int j = 0; j < len; ++j) {
        fac.push_back(-fac[j] * cur);
      }
      fac.push_back(cur);
    }
    for (auto& f : fac) {
      total =
          (total + lim / f);  // m / f means how many number has factor f
    }
    ans = ans * (lim - total) % MOD;
  }
  cout << ((ans + MOD) % MOD)<< '\n';
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