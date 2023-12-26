#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
// using double is slow
void solve() {
  int n;
  cin >> n;
  vector<int> pre(1e6 + 10);
  ll ans = 0, tmp = 0, x;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    tmp += i - pre[x];
    pre[x] = i;
    ans += tmp * 2 - 1;
  }
  cout << 1.0 * ans / n / n << '\n';
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