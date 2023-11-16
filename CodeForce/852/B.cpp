#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int x, y;
  cin >> x >> y;
  int len = x - y;
  cout << 2 * len << '\n';
  for (int i = y + 1; i <= x; ++i) {
    cout << i << " ";
  }
  for (int i = x - 1; i >= y; --i) {
    cout << i << " \n" [i == y];
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