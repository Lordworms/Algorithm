#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, k, y;
  cin >> n >> k;
  ll sum = 2 * k + n;
  int ansx = -1, ansy = -1;
  for (int x = 0; x <= n; ++x) {
    y = n - x;
    if (x * x + y * y == sum) {
      ansx = x, ansy = y;
    }
  }
  if (ansx == -1 && ansy == -1) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    for (int i = 1; i <= ansx; ++i) {
      cout << 1 << ' ';
    }
    for (int i = 1; i <= ansy; ++i) {
      cout << -1 << ' ';
    } 
    cout << '\n';
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