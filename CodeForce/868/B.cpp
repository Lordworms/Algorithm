#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, k;
  cin >> n >> k;
  int non_equal = 0;
  vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
    if ((pos[a[i]] - a[i]) % k != 0) {
      ++non_equal;
    }
  }
  if (non_equal == 0) {
    cout << 0 << '\n';
  } else if (non_equal == 2) {
    cout << 1 << '\n';
  } else  {
    cout << -1 << '\n';
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