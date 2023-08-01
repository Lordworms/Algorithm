#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  int l = 0, r = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    r = max(r, a[i]);
  }
  /*
    ans = min(max(num on odd position), max(num on even position))
    so it means we could use binary search to decide the ans
  */
  function<bool(int)> check = [&](int cur) {
    // could odd positions all <= cur ?
    int pos = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
      // calculate the odd position
      if (pos) {
        pos = 0;
        cnt2++;
      } else if (a[i] <= cur) {
        pos = 1;
        cnt1++;
      }
    }
    if (cnt1 + cnt2 >= k) {
      return true;
    }
    // could even positions all <= cur ?
    cnt1 = cnt2 = pos = 0;
    for (int i = 1; i <= n; ++i) {
      if (pos) {
        if (a[i] <= cur) {
          ++cnt2;
          pos = 0;
        }
      } else {
        pos = 1;
        ++cnt1;
      }
    }
    if (cnt1 + cnt2 >= k) {
      return true;
    }
    return false;
  };
  int ans = 0;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (check(m)) {
      ans = m;
      r = m - 1;
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