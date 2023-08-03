#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int all = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    all ^= a[i];
  }
  bool flag = false; // judge whether it is possible to get results of the game
  for (int i = 30; i >= 0; --i) {
    if (!(all & (1 << i))) continue;
    int tot = 0;
    for (int j = 1; j <= n; ++j) {
      int c = a[j];
      if (c & (1 << i)) ++tot;
    }
    flag = true;
    if ((n - tot) % 2 == 0 && (tot) % 4 == 3) {
      cout << "LOSE" << '\n';
    } else {
      cout << "WIN" << '\n';
    }
    break;
  }
  if (!flag) {
    cout << "DRAW" << '\n';
  }
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