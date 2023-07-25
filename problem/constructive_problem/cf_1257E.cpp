#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int a[N];
void solve() {
  int k1, k2, k3, x;
  cin >> k1 >> k2 >> k3;
  int n = k1 + k2 + k3;
  for (int i = 1; i <= k1; ++i) {
    cin >> x;
    a[x] = 1;
  }
  for (int i = 1; i <= k2; ++i) {
    cin >> x;
    a[x] = 2;
  }
  for (int i = 1; i <= k3; ++i) {
    cin >> x;
    a[x] = 3;
  }
  int pre = INT_MIN, ans = INT_MIN, cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (int i = 0; i <= n; ++i) {
    if (a[i] == 1) {
      ++cnt1;
    } else if (a[i] == 2) {
      ++cnt2;
    } else if (a[i] == 3) {
      ++cnt3;
    }
    pre = max(pre, cnt1 - cnt2);
    ans = max(ans, pre + k3 - cnt3 + cnt2);
  }
  cout << n - ans << '\n'; // n - ans is the answer
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