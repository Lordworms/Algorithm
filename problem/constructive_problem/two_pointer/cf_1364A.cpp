#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, x, sum = 0;
  cin >> n >> x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] %= x;
    sum += a[i];
  }
  if (sum == 0) {
    cout << -1 << '\n';
  } else if (sum % x != 0) {
    cout << n << '\n';
  } else {
    int l = 1, r = n;
    while (!a[l]) ++l;
    while (!a[r]) --r;
    cout << std::max(n - l, r - 1) << '\n';
  }
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}