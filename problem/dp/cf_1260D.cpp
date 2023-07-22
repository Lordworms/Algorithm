#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct node {
  int l, r, d;
};
void solve() {
  int m, n, k, t;
  cin >> m >> n >> k >> t;
  vector<int> a(m + 1);
  vector<node> s(k + 1);
  vector<int> dif(n + 2);
  for (int i = 1; i <= m; ++i) cin >> a[i];
  for (int i = 1; i <= k; ++i) {
    cin >> s[i].l >> s[i].r >> s[i].d;
  }
  sort(a.begin() + 1, a.end(),greater<int>());
  auto check = [&](int cur) {
    int sum = 0;
    fill(dif.begin(), dif.end(), 0);
    for (int i = 1; i <= k; ++i) {
      if (s[i].d > cur) {
        dif[s[i].l]++;
        dif[s[i].r + 1]--;
      }
    }
    for (int i = 1; i <= n + 1; ++i) {
      dif[i] += dif[i - 1];
      if (dif[i]) {
        sum += 3;
      } else {
        sum += 1;
      }
    }
    return sum <= t;
  };
  int l = 0, r = m+1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(a[mid])) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << max(r-1,0) << '\n';
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