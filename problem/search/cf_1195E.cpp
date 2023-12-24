#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n; cin >> n;
  ll k; cin >> k;
  vector<ll> a(n + 1), sum(a);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  auto check = [&] (int cur) {
    // set the maximum to a[l] + cur;
    for (int l = 1, r = 1; l <= n; ++l) {
      while (r <= n && a[r] - a[l] <= cur) ++r;
      if (a[l] * (l - 1) - sum[l] + (sum[n] - sum[r - 1]) - (a[l] + cur) * (n - r + 1) <= k) {
        return 1;  
      }
    }
    // set the maximum to a[l] - cur;
    for (int l = 1, r = 1; l <= n; ++l) {
      while (a[l] - a[r] > cur) ++r;
      if ((a[l] - cur) * (r - 1) - (sum[n] - sum[r - 1]) - (a[l] * (n - l) - sum[l])) {
        return 1;
      }
    }
    return 0;
  };
  int l = 0, r = a[n] - a[1], ans = 0;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (check(m)) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
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